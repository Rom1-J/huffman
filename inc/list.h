//
// Created by romain on 06/12/2020.
//

#include <stdlib.h>
#include <stdio.h>

#ifndef INC_HUFFMAN_LIST_H
#define INC_HUFFMAN_LIST_H

typedef struct Node {
    unsigned int occ;
    char letter;
    struct Node *next;
} Node, *List;

typedef struct Tree {
    int occ;
    char letter;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} Tree;

typedef struct TreeList {
    Tree *node;
    struct TreeList *next;
} TreeList;

List create_SLL();
void free_SLL(Node *head);
void show_SLL(Node *head);
void add_letter(Node *hear, char letter);
List pop(List list);

//////////////////////////////////////////////////////////////

Tree *create_huffman_tree(List list);
Tree *create_tree(Tree *left, Tree *right, int weight);
Tree *create_tree_node(int occ, char letter);
void insert_tree_node(TreeList **list, Tree *node);
void delete_node(TreeList **list, Tree *node);
int compare_node(Tree *node1, Tree *node2);
int tree_list_len(TreeList *list);
Tree *tree_list_min(TreeList **list);
void print_tree(Tree *tree);

#endif //INC_HUFFMAN_LIST_H