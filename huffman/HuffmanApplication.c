#include "HuffmanApplication.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**********************************************************
			Contract's functions imeplementation
***********************************************************/
void huffmanApplication(int argumentsCounter, char* argmentsVector[]) {
	header();
	int chosenLanguage;
	baseMenu(&chosenLanguage);

}

/**********************************************************
			Auxiliar functions imeplementation
**********************************************************/
void header() {
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
			printf("Please type a valid value\n");
			baseMenu(chosen);
	}
}

void mainManu(void (*mainMenuHandler)(void)) {
	mainMenuHandler();
}
