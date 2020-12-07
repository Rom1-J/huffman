//#include "../inc/translate.h"
#include "../inc/utils.h"
#include "../inc/huffman.h"
#include <stdio.h>

int main(void) {
    FILE *fpi;

    fpi = fopen("test/Alice.txt", "r");

    compress(fpi);

    fclose(fpi);

    return 0;
}