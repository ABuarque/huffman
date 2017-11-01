#include "HuffmanApplication.h"
#include "HuffmanHandler.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define DEBUG if(1)

const char* HUFFMAN = 
"\
||     || ||	|| ||||||||| |||||||      ||   	   ||             || 	  ||       ||\
||     || ||	|| ||        ||		    || ||    || ||		    || ||     || ||    ||\
||     || ||	|| ||        ||        ||    || ||   ||	       ||   ||    ||  ||   ||\
||||||||| ||	|| ||||||    ||||||   ||      ||      ||      ||=====||   ||   ||  ||\
||     || ||    || ||        ||      ||                ||    ||       ||  ||    || ||\
||     || ||    || ||	     ||     ||                  ||  ||	       || ||	 ||||\
||     || |||||||| ||        ||    ||		             || ||         || ||       ||";


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
 * @param a function to handle the propper manu
 */
void mainManu(void (*mainMenuHandler)(void));	

/**
 * Menu handle for portuguese language.
 */
void mainMenuPortuguese();

/**
 * Menu handle for english language.
 */
void mainMenuEnglish();

/**
 * Menu handle for spanish language.
 */
void mainMenuEspanish();

/**
 * It asks user for the input file name
 * in portuguese.
 */
void askForInputPortuguese();

/**
 * It asks user for the input file name
 * in english.
 */
void askForInputEnglish();

/**
 * It asks user for the input file name
 * in espanish.
 */
void askForInputEspanish(); 

/**
 * Template function to ask user for input file name.
 *
 * @param a handle function.
 */
void askForInput(void (*askForInputHandler)(void));

/**
 * It asks user for the output file name
 * in english.
 */
void askForOutputEnglish();

/**
 * It asks user for the output file name
 * in portuguese.
 */
void askForOutputPortuguese();

/**
 * It asks user for the output file name
 * in espanish.
 */
void askForOutputEspanish();

/**
 * Template function to ask user for output file name.
 *
 * @param a handle function.
 */
void askForOutput(void (*askForOutputHandler)(void));

/**
 * It asks user for a valid input.
 * 
 * @param index of enum languages
 * @return propper message
 */
char *askForValidInput(int index);

/**
 * It says to user that the given input file name
 * is wrong.
 *
 * @param index enum language
 * @return a proper message
 */
char *informWrongInputFileName(int index);

/**
 * It says to user that extension file is not .huff.
 *
 * @param the index enum language
 * @return proper message
 */
char* alertFileInvalidExtension(int index);

//Array to store manu languages
void (*preferenceLanguages[])(void) = { mainMenuEnglish, 
										mainMenuPortuguese,
										mainMenuEspanish};

//Array to store function handles to ask input file name
void (*inputFileLangues[])(void) = { askForInputEnglish, 
									 askForInputPortuguese, 
									 askForInputEspanish};

//Array to store function handles to ask input file name
void (*outputFileLangues[])(void) = { askForOutputEnglish, 
									  askForOutputPortuguese, 
									  askForOutputEspanish};
/**********************************************************
			Contract's functions implementation
***********************************************************/
void huffmanApplication() {
	system("clear");
	header();
	int input, typedInputValue = 0;;
	baseMenu(&input);
	const int LANGUAGE = input;
	system("clear");
	header();
	mainManu(preferenceLanguages[LANGUAGE - 1]);
	while((scanf("%d", &input))) {
		getchar();
		switch(input) {
			case DO_COMPRESS:
				typedInputValue = 0;
				system("clear");
				header();
				askForInput(inputFileLangues[LANGUAGE - 1]);
				scanf("%[^\n]", inputFileName);
				getchar();
				askForOutput(outputFileLangues[LANGUAGE - 1]);
				scanf("%[^\n]", outputFileName);
				getchar();
				onCompress(inputFileName, outputFileName, informWrongInputFileName(LANGUAGE - 1));
				printf("Ok!\n");
				break;
			case DO_DECOMPRESS:
				typedInputValue = 0;
				system("clear");
				header();
				askForInput(inputFileLangues[LANGUAGE - 1]);
				scanf("%[^\n]", inputFileName);
				getchar();
				askForOutput(outputFileLangues[LANGUAGE - 1]);
				scanf("%[^\n]", outputFileName);
				getchar();
				onDecompress(inputFileName, outputFileName, informWrongInputFileName(LANGUAGE - 1), alertFileInvalidExtension(LANGUAGE - 1));
				printf("Ok!\n");
				break;
			case END_APP:
				DEBUG printf("Closing app!\n");
				exit(0);
			default :
				typedInputValue = 1;
				DEBUG printf("Invalid option.\n");
				system("clear");
				header();
				printf("%s", askForValidInput(LANGUAGE - 1));
				mainManu(preferenceLanguages[LANGUAGE - 1]);
				break;
		}
		if(!typedInputValue) {
			system("clear");
			header();
			mainManu(preferenceLanguages[LANGUAGE - 1]);
		}
	}
}

/**********************************************************
			Auxiliar functions implementation
**********************************************************/
void header() {
	//printf("|---------------------------------------------------------------------------------------------------|\n");
	//printf("|                                               Huffman                                             |\n");
	//printf("|                                                                                                   |\n");
	//printf("|                                         [version 1.0 - 2017]                                      |\n"); 
	//printf("|---------------------------------------------------------------------------------------------------|\n");
	
	printf("-------------------------------------------------------------------------------------------\n");
	printf("||     || ||	|| ||||||||| |||||||      ||       ||             ||      ||||     ||\n");
	printf("||     || ||	|| ||        ||         || ||    || ||          || ||     || ||    ||\n");
	printf("||     || ||	|| ||        ||        ||    || ||   ||        ||   ||    ||  ||   ||\n");
	printf("||||||||| ||	|| ||||||    ||||||   ||      ||      ||      ||=====||   ||   ||  ||\n");
	printf("||     || ||    || ||        ||      ||                ||    ||       ||  ||    || ||\n");
	printf("||     || ||    || ||	     ||     ||                  ||  ||	       || ||	 ||||\n");
	printf("||     || |||||||| ||        ||    ||                    || ||         || ||       ||\n");
	printf("-------------------------------------------------------------------------------------------\n");
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
			printf("Please type a valid value:\n");
			baseMenu(chosen);
	}
}

void mainMenuPortuguese() {
	printf("Digite uma das opções: \n");
	printf("	(1) Codificar arquivo.\n"); 
	printf("	(2) Decodificar.\n");
	printf("	(3) Terminar programa.\n");
}

void mainMenuEnglish() {
	printf("Pick up an option: \n");
	printf("	(1) Codify file.\n"); 
	printf("	(2) Decode file.\n");
	printf("	(3) End program.\n");
}

void mainMenuEspanish() {
	printf("Elija una de las opciones: \n");
	printf("	(1) Codificar archivo.\n"); 
	printf("	(2) Decodificar archivo.\n");
	printf("	(3) Finalizar aplicación.\n");
}

void mainManu(void (*mainMenuHandler)(void)) {
	mainMenuHandler();
}

void askForInputPortuguese() {
	printf("Digite o nome do arquivo de entrada: ");
}

void askForInputEnglish() {
	printf("Type input file name: ");
}

void askForInputEspanish() {
	printf("Escriba el nombre de archivo de entrada: ");
}

void askForInput(void (*askForInputHandler)(void)) {
	askForInputHandler();
}

void askForOutputEnglish() {
	printf("Type desired output name: ");
}

void askForOutputPortuguese() {
	printf("Digite o nome de saída desejado: ");
}

void askForOutputEspanish() {
	printf("Escriba el nombre de salida desejado: ");
}

void askForOutput(void (*askForOutputHandler)(void)) {
	askForOutputHandler();
}

char *askForValidInput(int index) {
	if(index == 0) 
		return "Please type a valid value:\n";
	else if(index == 1)
		return "Por favor insira um argumento valido\n";
	return "Per favor escriba un valor válido\n";
}

char *informWrongInputFileName(int index) {
	if(index == 0)
		return "Impossible to find file with given name, try again: ";
	else if(index == 1)
		return "Impossível encontrar arquivo com nome informado, tente de novo: ";
	return "Imposible encontrar un archivo con un nombre determinado, escriba novamente: ";
}

char* alertFileInvalidExtension(int index) {
	if(index == 0)
		return "Given file has not right extension: '.huff', Please, type it again.\n";
	else if(index == 1)
		return "Arquivo informado não possui extensão correta: '.huff', Por favor, digite de novo.\n";
	return "El archivo dado no tiene la extensión correcta: '.huff', por favor, tipea de nuevo.\n";
}
