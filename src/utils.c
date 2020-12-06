#include "../inc/utils.h"
#include <stdio.h>
#include <stdlib.h>


void show_chars_count(FILE *fpi) {
    int i = 0;
    char character;

    while ((character = fgetc(fpi)) != EOF) i++;

    printf("Il y a %d caracteres\n", i);
}
