#ifndef ONLANGUAGERESOURCES_H
#define ONLANGUAGERESOURCES_H

#include "utils.h"

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

#endif
