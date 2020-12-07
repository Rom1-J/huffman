#include "../inc/translate.h"
#include "../inc/utils.h"
#include <stdio.h>

int main(void) {
    FILE *fpi, *fpo;
//
    fpi = fopen("test/Alice.txt", "r");
//    fpo = fopen("test/Output.txt", "w");
//
//    translate_file(fpi, fpo);
//
//    fpi = fopen("test/Alice.txt", "r");
//    show_chars_count(fpi);

    List list = create_huffman_list(fpi);

    show_SLL(list);
    /*
     * $ ./main
        :0->T:1->A:1->S:3->E:1->/
     */

    Tree *htree = create_huffman_tree(list);
    print_tree(htree);

    return 0;
}