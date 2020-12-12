//
// Created by romain on 07/12/2020.
//
/*****************************************************************//**
 * \file tree.h.
 * \brief Functions for Huffman tree manipulation
 * \author Romain J. and his group
 * \date   December 2020
 *********************************************************************/

#include <stdlib.h>
#include <stdio.h>

#ifndef INC_HUFFMAN_TREE_H
#define INC_HUFFMAN_TREE_H

#include "list.h"

/**
 * \typedef struct Tree
 * \ brief
structure composed of 5 elements:  occ (contains the occurrence of letter) ,
letter (the given letter ) ,
*left, *right (specific to binary tree) ,
*parent (parent of this leaf) .
 */

typedef struct Tree {
    int occ;
    char letter;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} Tree;

/**
 * \typedef struct TreeList
 * \ brief Binary tree with Tree as value/info.
 */

typedef struct TreeList {
    Tree *node;
    struct TreeList *next;
} TreeList;

//////////////////////////////////////////////////////////////

/**
 * \brief
Set of utils functions for binary tree manipulation and Huffman tree manipulation
Example :
 * \code{.c}
 * \endcode
 * \return Tree* create_node --> simple as binary tree add node methode, because nodes contains letter and occurrences, we pass them
 * \return Tree *h_tree --> generate Huffman tree from given list
 * \return void insert_node --> add node as Tree to TreeList
 * \return void compare_node --> check if given nodes are same as pointer or values
 * \return void delete_node --> remove node as Tree from TreeList
 * \return Tree* TreeList_min --> Return the minimum Tree node from given TreeList
 * \return void TreeList_len --> Return the length of given TreeList
 * \return void clear_tree --> free
 */

Tree *create_node(char letter, int occ);

Tree *h_tree(List list);

void insert_node(TreeList **list, Tree *tree);

int compare_node(Tree *node1, Tree *node2);

void delete_node(TreeList **list, Tree *tree);

Tree *TreeList_min(TreeList **list);

int TreeList_len(TreeList *list);

void clear_tree(Tree *tree);

#endif //INC_HUFFMAN_TREE_H
