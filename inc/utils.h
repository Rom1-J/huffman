//
// Created by romain on 06/12/2020.
//

/*****************************************************************//**
 * \file utils.h.
 *  \brief
Some utils functions apart from big part
 *
 * \author Romain J. and his group
 * \date   December 2020
 *********************************************************************/

#include <stdio.h>
#include "list.h"

#ifndef INC_HUFFMAN_UTILS_H
#define INC_HUFFMAN_UTILS_H

//////////////////////////////////////////////////////////////
/**
* \brief
Functions such as count chars in file and binary to int conversion
* \n Example :
* \code{.c}
* \endcode
* \return chars_count --> return the number of characters in giver file
* \return bin2int --> return int value of binary stored in string
*/

int chars_count(FILE *fpi);

int bin2int(char *string);

#endif //INC_HUFFMAN_UTILS_H
