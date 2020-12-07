#include "../inc/list.h"
#include "../inc/dict.h"
#include <stdio.h>
#include <stdlib.h>

void create_dict(Tree *tree, Stack **stack, FILE *dict) {
    if (tree) {
        if (tree->left) {
            if (tree->left->letter != 0) {
                *stack = stack_push(*stack, '0');

                fprintf(dict, "%c : ", tree->right->letter);

                stack2dict(*stack, dict);

                fputc('\n', dict);

                create_dict(tree->right, stack, dict);
            } else {
                *stack = stack_push(*stack, '0');
                create_dict(tree->right, stack, dict);
            }
            *stack = stack_pop(*stack);
        }

        if (tree->right) {
            if (tree->right->letter != 0) {
                *stack = stack_push(*stack, '1');

                fprintf(dict, "%c : ", tree->left->letter);

                stack2dict(*stack, dict);

                fputc('\n', dict);

                create_dict(tree->left, stack, dict);
            } else {
                *stack = stack_push(*stack, '1');
                create_dict(tree->left, stack, dict);
            }
            *stack = stack_pop(*stack);
        }
    }
}

void stack2dict(Stack *stack, FILE *dict) {
    if (stack) {
        stack2dict(stack->next, dict);
        fputc(stack->letter, dict);

    }
}

Stack *create_stack(char letter) {
    Stack *stack = malloc(sizeof(Stack));

    stack->letter = letter;
    stack->next = NULL;

    return stack;
}

Stack *stack_push(Stack *stack, char letter) {

    if (stack) {
        return create_stack(letter);
    } else {
        Stack *new_stack = create_stack(letter);
        new_stack->next = stack;

        return new_stack;
    }

}

Stack *stack_pop(Stack *stack) {
    if (!stack) {
        return stack;
    } else {
        Stack *temp = stack->next;
        free(stack);
        
        return temp;
    }
}
