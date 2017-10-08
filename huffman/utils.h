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

//define a constant error for accessing empty data structures
#define DATA_ESTRUCTURE_EMPTY "Requested element in a empty data structure.\n"

//define DO_COMPRESS as flag to run compress process
#define DO_COMPRESS 1

//define DO_DECOMPRESS as flag to run decompress process
#define DO_DECOMPRESS 2

//define a constant to user finish app
#define END_APP 3

#endif
