#include "../inc/utils.h"
#include "../inc/list.h"
#include <stdio.h>
#include <string.h>


int chars_count(FILE *fpi) {
    int i = 0;
    char character;

    while ((character = fgetc(fpi)) != EOF) i++;

    return i;
}