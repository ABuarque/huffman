#include "HuffmanApplication.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define DEBUG if(1)

/****************************************************
				Auxiliar functions
	Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/

/**
 * It shows on console the application header.
 *
 */
void header();

/**
 * First menu to be show. Here, user defines
 * application language and its index on 
 * enum defined at header will be placed
 * into the pointer.
 *
 * @param pointer to store chosen language
 */
void baseMenu(int *chosen);

/**
 * It show the main menu according with user`s language preference.
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

/**********************************************************
			Contract's functions imeplementation
***********************************************************/
void huffmanApplication(int argumentsCounter, char* argmentsVector[]) {
	void (*preferenceLanguages[])(void) = {mainMenuEnglish, 
										   mainMenuPortuguese,
										   mainMenuEspanish};
	header();
	int chosenLanguage;
	baseMenu(&chosenLanguage);
	mainManu(preferenceLanguages[chosenLanguage - 1]);

}

/**********************************************************
			Auxiliar functions imeplementation
**********************************************************/
void header() {
	//system("clear");
	printf("|---------------------------------------------------------------------------------------------------|\n");
	printf("|                                               Huffman                                             |\n");
	printf("|                                                                                                   |\n");
	printf("|                                         [version 1.0 - 2017]                                      |\n"); 
	printf("|---------------------------------------------------------------------------------------------------|\n");
}

void baseMenu(int *chosen) {
	printf("Choose a language: \n");
	printf("\t (1) English\n");
	printf("\t (2) Portuguese\n");
	printf("\t (3) Espanish\n");
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
	system("clear");
	header();
	printf("Digite uma das opções: \n");
	printf("	(1) Codificar arquivo.\n"); 
	printf("	(2) Decodificar.\n");
}

void mainMenuEnglish() {
	system("clear");
	header();
	printf("Pick up an option: \n");
	printf("	(1) Codify file.\n"); 
	printf("	(2) Decode file.\n");
}

void mainMenuEspanish() {
	system("clear");
	header();
	printf("Elija una de las opciones: \n");
	printf("	(1) Codificar archivo.\n"); 
	printf("	(2) Decodificar archivo.\n");
}

void mainManu(void (*mainMenuHandler)(void)) {
	mainMenuHandler();
}
