#include "../inc/list.h"


Node *create_SLL() {
    return (struct Node *) malloc(sizeof(struct Node));
}

void free_SLL(Node *head) {
    Node *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void show_SLL(Node *head) {
    while (head != NULL) {
        printf("%c:%d->", head->letter, head->occ);
        head = head->next;
    }
    printf("/\n");
}

void add_letter(Node *head, char letter) {
    Node *curr = head != NULL ? head : create_SLL();
    Node *tmp;
    int exist = 0;

    while (curr != NULL) {
        if (curr->letter == letter) {
            curr->occ += 1;
            exist = 1;
        }
        tmp = curr;
        curr = curr->next;
    }

    if (!exist) {
        Node *new = create_SLL();
        new->occ = 1;
        new->letter = letter;

        tmp->next = new;
    }
}