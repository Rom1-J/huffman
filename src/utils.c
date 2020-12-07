#include "../inc/utils.h"
#include "../inc/list.h"
#include <stdio.h>
#include <string.h>


void show_chars_count(FILE *fpi) {
    int i = 0;
    char character;

    while ((character = fgetc(fpi)) != EOF) i++;

    printf("Il y a %d caracteres\n", i);
}

List count_occurences(char *string) {
    Node *start = create_SLL();

    for (int i = 0; i < strlen(string); i++){
        add_letter(start, string[i]);
    }

    return start;
}