//
// Created by romain on 06/12/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

#ifndef INC_HUFFMAN_LIST_H
#define INC_HUFFMAN_LIST_H

typedef struct Node {
    int occ;
    char letter;
    struct Node *next;
} Node, *List;

//////////////////////////////////////////////////////////////

List create_huffman_list(FILE *fpi);

List append(List list, char letter, int occ);

List pop(List list);

#endif //INC_HUFFMAN_LIST_H