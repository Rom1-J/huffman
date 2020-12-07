//
// Created by romain on 07/12/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "../inc/list.h"

#ifndef INC_HUFFMAN_DICT_H
#define INC_HUFFMAN_DICT_H

typedef struct Stack {
    char letter;
    struct Stack *next;
} Stack;

//////////////////////////////////////////////////////////////

void create_dict(Tree *a, Stack **stack, FILE *dict);

Stack *create_stack(char letter);

Stack *stack_push(Stack *stack, char letter);

Stack *stack_pop(Stack *stack);

void stack2dict(Stack *stack, FILE *dict);

#endif //INC_HUFFMAN_DICT_H