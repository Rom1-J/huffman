//
// Created by romain on 07/12/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "dict.h"
#include "utils.h"

#ifndef INC_HUFFMAN_ENCODER_H
#define INC_HUFFMAN_ENCODER_H

typedef struct EncodeList {
    char letter;
    char *value;
    struct EncodeList *next;
} EncodeList;

//////////////////////////////////////////////////////////////

void compress(FILE *fpi);

void encode(FILE *fpi, FILE *dict);

char *get_char(FILE *dict);

EncodeList* create_encode_list(FILE* dict);

#endif //INC_HUFFMAN_ENCODER_H