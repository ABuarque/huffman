#ifndef HUFFMANAPPLICATION_H
#define HUFFMANAPPLICATION_H

/****************************************************************

	This file deals with user interaction, it just
handles language preferences and user inputs, 
to compress or decompress some file.

	On compress - client must provide these informations:
		* Input file name (the file path)
		* Ouput file name
	On decrompress - cliente must provide these informations:
		* Input file name (the file path)
		* Ouput file name
		
*****************************************************************/

/**
 * This enum defines formal constant values for 
 * the languages supported by this app:
 * EN: english, PT: portuguese, ES: espanish
 *
 */
enum {EN = 1, PT, ES};

/**
 * 	That's the entry point of Huffman app.
 * 
 */
void huffmanApplication();


#endif
