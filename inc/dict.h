//
// Created by romain on 07/12/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stack.h"

#ifndef INC_HUFFMAN_DICT_H
#define INC_HUFFMAN_DICT_H

typedef struct Dict {
    char key;
    char *val;

    struct Dict *left;
    struct Dict *right;
} Dict;

//////////////////////////////////////////////////////////////

void create_dict(Tree *tree, Stack **P, FILE *dict);

void stack2dict(Stack *stack, FILE *dict);

#endif //INC_HUFFMAN_DICT_H