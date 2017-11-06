#include "HuffmanApplication.h"
#include "HuffmanHandler.h"
#include "utils.h"
#include "onLanguageResources.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define DEBUG if(0)

/****************************************************
				Auxiliar functions
	Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/

//Array to store input file name
char inputFileName[SIZE_BUFFER];

//Array to store output file name
char outputFileName[SIZE_BUFFER];

/**
 * It shows on console the application header.
 *
 */
void header();

/**
 * First menu to be shown. Here, user chooses
 * the application language and its index on 
 * enum defined at header will be placed
 * into the pointer.
 *
 * @param pointer to store chosen language
 */
void baseMenu(int *chosen);

/**
 * It shows the main menu according to the user`s language preference.
 * 
 * @param a function to handle the propper menu
 */
void mainMenu(void (*mainMenuHandler)(void));	

/**
 * Template function to ask user for input file name.
 *
 * @param a handle function.
 */
void askForInput(void (*askForInputHandler)(void));

/**
 * Template function to ask user for output file name.
 *
 * @param a handle function.
 */
void askForOutput(void (*askForOutputHandler)(void));

//Array to store menu languages
void (*preferenceLanguages[])(void) = { mainMenuEnglish, 
										mainMenuPortuguese,
										mainMenuEspanish};

//Array to store function handles to ask input file name
void (*inputFileLanguages[])(void) = { askForInputEnglish, 
									 askForInputPortuguese, 
									 askForInputEspanish};

//Array to store function handles to ask input file name
void (*outputFileLanguages[])(void) = { askForOutputEnglish, 
									  askForOutputPortuguese, 
									  askForOutputEspanish};
/**
 * It opens up default browser on our GitHub repository.
 */
void openRepository();

/**********************************************************
			Contract's functions implementation
***********************************************************/
void huffmanApplication() {
	system("clear");
	header();
	int input, typedInputValue = 0;
	baseMenu(&input);
	const int LANGUAGE = input;
	system("clear");
	header();
	mainMenu(preferenceLanguages[LANGUAGE - 1]);
	while((scanf("%d", &input))) {
		getchar();
		switch(input) {
			case DO_COMPRESS:
				typedInputValue = 0;
				system("clear");
				header();
				askForInput(inputFileLanguages[LANGUAGE - 1]);
				scanf("%[^\n]", inputFileName);
				getchar();
				askForOutput(outputFileLanguages[LANGUAGE - 1]);
				scanf("%[^\n]", outputFileName);
				getchar();
				onCompress(inputFileName, outputFileName, informWrongInputFileName(LANGUAGE - 1));
				break;
			case DO_DECOMPRESS:
				typedInputValue = 0;
				system("clear");
				header();
				askForInput(inputFileLanguages[LANGUAGE - 1]);
				scanf("%[^\n]", inputFileName);
				getchar();
				askForOutput(outputFileLanguages[LANGUAGE - 1]);
				scanf("%[^\n]", outputFileName);
				getchar();
				onDecompress(inputFileName, outputFileName, informWrongInputFileName(LANGUAGE - 1), alertFileInvalidExtension(LANGUAGE - 1));
				break;
			case END_APP:
				DEBUG printf("Closing app!\n");
				exit(0);
			case SHOW_REPOSITORY:
				typedInputValue = 0;
				openRepository();
				break;
			default :
				typedInputValue = 1;
				DEBUG printf("Invalid option.\n");
				system("clear");
				header();
				printf("%s", askForValidInput(LANGUAGE - 1));
				printf("%s", COLOR_CYAN);
				mainMenu(preferenceLanguages[LANGUAGE - 1]);
				break;
		}
		if(!typedInputValue) {
			system("clear");
			header();
			mainMenu(preferenceLanguages[LANGUAGE - 1]);
		}
	}
}

/**********************************************************
			Auxiliar functions implementation
**********************************************************/
void header() {
	printf("%s", COLOR_CYAN); //setting color to cyan
	printf("-----------------------------------------------------------------------------------------\n");
	printf("+ ||     || ||	  || ||||||||| |||||||      ||       ||             ||      ||||     || +\n");
	printf("+ ||     || ||	  || ||        ||         || ||    || ||          || ||     || ||    || +\n");
	printf("+ ||     || ||	  || ||        ||        ||    || ||   ||        ||   ||    ||  ||   || +\n");
	printf("+ ||||||||| ||	  || ||||||    ||||||   ||      ||      ||      |||||||||   ||   ||  || +\n");
	printf("+ ||     || ||    || ||        ||      ||                ||    ||       ||  ||    || || +\n");
	printf("+ ||     || ||    || ||        ||     ||                  ||  ||         || ||     |||| +\n");
	printf("+ ||     || |||||||| ||        ||    ||                    || ||         || ||       || +\n");
	printf("+                                                                                       +\n");
	printf("+                                     [version 1.0 - 2017]                              +\n"); 
	printf("-----------------------------------------------------------------------------------------\n");
}

void baseMenu(int *chosen) {
	printf("Choose a language: \n");
	printf("\t (1) English\n");
	printf("\t (2) Portuguese\n");
	printf("\t (3) Spanish\n");
	int input;
	scanf("%d", &input);
	getchar();
	switch(input) {
		case EN:
			*chosen = input;
			break;
		case PT:
			*chosen = input;
			break;
		case ES:
			*chosen = input;
			break;
		default: 
			system("clear");
			header();
			printf("%s", COLOR_RED);
			printf("Please type a valid value:\n");
			printf("%s", COLOR_CYAN);
			baseMenu(chosen);
	}
}

void openRepository() {
	system("x-www-browser https://github.com/ABuarque/huffman");
}

void mainMenu(void (*mainMenuHandler)(void)) {
	mainMenuHandler();
}

void askForInput(void (*askForInputHandler)(void)) {
	askForInputHandler();
}

void askForOutput(void (*askForOutputHandler)(void)) {
	askForOutputHandler();
}
