#include "../inc/translate.h"
#include "../inc/utils.h"
#include <stdio.h>

int main(void) {
    FILE *fpi, *fpo;

    fpi = fopen("test/Alice.txt", "r");
    fpo = fopen("test/Output.txt", "w");

    translate_file(fpi, fpo);

    fpi = fopen("test/Alice.txt", "r");
    show_chars_count(fpi);

    return 0;
}