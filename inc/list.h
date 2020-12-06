//
// Created by romain on 06/12/2020.
//

#include <stdlib.h>
#include <stdio.h>

#ifndef INC_HUFFMAN_LIST_H
#define INC_HUFFMAN_LIST_H

typedef struct Node {
    int occ;
    char letter;
    struct Node *next;
} Node;

Node *create_SLL();

void free_SLL(Node *head);

void show_SLL(Node *head);

void add_letter(Node* hear, char letter);

#endif //INC_HUFFMAN_LIST_H