#ifndef HUFFMANAPPLICATION_H
#define HUFFMANAPPLICATION_H

/****************************************************************

	This file deals with user interaction, it just
handles language preferences and user inputs, 
to compress or decompress some file.

	On compress - cliente must provide these information flags:
		* -comp: it says user wants to compress (action flag)
		* FILE_PATH: it says where is the file
		* OUTPUT_NAME: it says what is gonne be output name
	On decrompress - cliente must provide these information flags
		* -decomp: it says user wants to decompress (action flag)
		* FILE_PATH: it says where is the file to be decompressed
		* OUTPUT_NAME: it says what is gonne be output name
		
*****************************************************************/

/**
 * 	That's the entry point of Huffman app.
 * It gets arguments sent on command line
 * and runs the application with them.
 *	From command line 4 arguments should
 * be given: application launcher, action flag
 * (see above description), input and output file.
 * 
 * @param number of arguments
 * @param arguments list
 */
void huffmanApplication(int argumentsCounter, char* argmentsVector[]);

#endif
