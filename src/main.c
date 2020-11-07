#include "../inc/translate.h"
#include <stdio.h>

int main(void) {
    FILE *fpi, *fpo;

    fpi = fopen("test/Alice.txt", "r");
    fpo = fopen("test/Output.txt", "w");

    translate_file(fpi, fpo);

    return 0;
}