#include <stdio.h>
#include <stdlib.h>
#include "../inc/huffman.h"

void compress(FILE *fpi) {
    printf("compression...\n");

    FILE* dict_w = fopen("test/dict","w");

    List list = create_huffman_list(fpi);
    Tree *tree = create_huffman_tree(list);

    Stack *stack = NULL;
    create_dict(tree, &stack, dict_w);
    fclose(dict_w);

//    free_tree(tree);

    printf("fin\n");
}