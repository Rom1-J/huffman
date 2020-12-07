#include "../inc/translate.h"
#include <stdio.h>
#include <stdlib.h>


int translate_char(int ch) {
    int out = 0, i = 1, rem;

    while (ch > 0) {
        rem = ch % 2;
        out += (i * rem);

        ch /= 2;

        i *= 10;
    }

    return out;
}

void translate_file(FILE *fpi, FILE *fpo) {
    char character;

    while ((character = fgetc(fpi)) != EOF) {
        if (character < 64)
            fprintf(fpo, "00%d", translate_char((int) character));
        else
            fprintf(fpo, "0%d", translate_char((int) character));
    }
}
