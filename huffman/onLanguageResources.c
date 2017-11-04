#include "onLanguageResources.h"
#include "utils.h"	

void mainMenuPortuguese() {
	printf("Digite uma das opções: \n");
	printf("	(1) Codificar arquivo.\n"); 
	printf("	(2) Decodificar.\n");
	printf("	(3) Terminar programa.\n");
	printf("	(4) Ver repositório no GitHub.\n");
}

void mainMenuEnglish() {
	printf("Pick up an option: \n");
	printf("	(1) Codify file.\n"); 
	printf("	(2) Decode file.\n");
	printf("	(3) End program.\n");
	printf("	(4) See project on GitHub.\n");
}

void mainMenuEspanish() {
	printf("Elija una de las opciones: \n");
	printf("	(1) Codificar archivo.\n"); 
	printf("	(2) Decodificar archivo.\n");
	printf("	(3) Finalizar aplicación.\n");
	printf("	(4) Ver proyecto en GitHub.\n");
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

void askForOutputEnglish() {
	printf("Type desired output name: ");
}

void askForOutputPortuguese() {
	printf("Digite o nome de saída desejado: ");
}

void askForOutputEspanish() {
	printf("Escriba el nombre de salida desejado: ");
}

char *askForValidInput(int index) {
	printf("%s", COLOR_RED); //changin color warning to red
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
