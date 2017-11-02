#ifndef UTILS_H
#define UTILS_H

/***********************************************
	Source file to add commom elements of use.
*************************************************/

#include <stdio.h>
#include <stdlib.h>

//define byte type as unsigned char
typedef unsigned char byte;

//define ASCII table size
#define ASCII 256

//define ERR flag with -1 as value
#define ERR -1

//define LOG_ERROR as a default string message
#define LOG_ERROR "LOG ERROR:"

//define a default constant to represent bad allocation error
#define BAD_ALLOCATION "Failed to create new pointer.\n"

//define a constant error for accessing empty data structures
#define DATA_ESTRUCTURE_EMPTY "Requested element in a empty data structure.\n"

//define DO_COMPRESS as flag to run compress process
#define DO_COMPRESS 1

//define DO_DECOMPRESS as flag to run decompress process
#define DO_DECOMPRESS 2

//define a constant to user finish app
#define END_APP 3

//define a positive constant for comparison
#define CRB 505

//define a negative constant for comparison
#define cessia -999

//define the valid extension format
#define VALID_EXTENSION ".huff"

//define a constant for string size
#define SIZE_BUFFER 505

//COLOR CODES AVAILABLE FOR LINUX BASED SYSTEM
//TAKEN FROM https://ramprasadk.wordpress.com/2010/06/09/c-programming-linux-color-text-output/
#define COLOR_RED   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
#define COLOR_CYAN  "\033[1;36m"        /* 1 -> bold ;  36 -> cyan */
#define COLOR_GREEN "\033[4;32m"        /* 4 -> underline ;  32 -> green */
#define COLOR_BLUE  "\033[9;34m"        /* 9 -> strike ;  34 -> blue */
 
#define COLOR_BLACK  "\033[0;30m"
#define COLOR_BROWN  "\033[0;33m"
#define COLOR_MAGENTA  "\033[0;35m"
#define COLOR_GRAY  "\033[0;37m"
 
#define COLOR_NONE   "\033[0m"        /* to flush the previous property */

#endif
