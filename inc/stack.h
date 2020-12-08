//
// Created by romain on 07/12/2020.
//

#include <stdlib.h>
#include <stdio.h>

#ifndef INC_HUFFMAN_STACK_H
#define INC_HUFFMAN_STACK_H

typedef struct Stack {
    char letter;
    struct Stack *next;
} Stack;

//////////////////////////////////////////////////////////////

Stack *create_stack(char letter);

Stack *push(Stack *stack, char letter);

Stack *stack_pop(Stack *stack);

#endif //INC_HUFFMAN_STACK_H
