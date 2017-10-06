#ifndef UTILS_H
#define UTILS_H

/***********************************************
	Source file to add commom elements of use.
*************************************************/

#include <stdio.h>
#include <stdlib.h>

//define byte type as unsigned char
typedef unsigned char byte;

//define ERR flag with -1 as value
#define ERR -1

//define LOG_ERROR as a default string message
#define LOG_ERROR "LOG ERROR:"

//define a default constant to represent bad allocation error
#define BAD_ALLOCATION "Failed to create new pointer.\n"

//define a default constant to represent error caused by wron arguments
#define BAD_ARGUMENTS "List arguments should be: ./app <ACTION_FLAG> <INPUT_FILE> <OUTPUT_FILE>\n"

//define a default constant to alert about bugs caused by wrong flags
#define UNKNOW_ACTION_FLAG "Invalid action flag values: -comp or -decomp\n"

//define DO_COMPRESS as flag to run compress process
#define DO_COMPRESS "-comp"

//define DO_DECOMPRESS as flag to run decompress process
#define DO_DECOMPRESS "-decomp"

#endif
