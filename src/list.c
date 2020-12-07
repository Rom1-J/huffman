#include "../inc/list.h"


List create_huffman_list(FILE *fpi) {
    if (!fpi) return NULL;

    char letter;
    int exist = 0;

    List list = malloc(sizeof(*list));

    list->occ = 1;
    list->letter = fgetc(fpi);
    list->next = NULL;


    Node *curr;
    curr = list;

    while ((letter = fgetc(fpi)) != EOF) {
        while (curr) {
            if (letter == curr->letter) {
                curr->occ++;
                exist = 1;
            }

            curr = curr->next;

        }

        if (!exist) {
            add_letter(list, letter);
        }

        exist = 0;
        curr = list;
    }

    return list;
}


List create_SLL() {
    return (struct Node *) malloc(sizeof(struct Node));
}

void free_SLL(Node *head) {
    Node *tmp;

    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void show_SLL(Node *head) {
    while (head) {
        printf("%c:%d->", head->letter, head->occ);
        head = head->next;
    }
    printf("/\n");
}

void add_letter(Node *head, char letter) {
    Node *curr = head ? head : create_SLL();
    Node *tmp;
    int exist = 0;

    while (curr) {
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

List pop(List list) {
    if (!list) return list;

    List tmp = create_SLL();

    tmp = list->next;
    free(list);
    list = NULL;

    return tmp;
}

Tree *create_huffman_tree(List list) {
    Node *tmp = list;

    Tree *tree, *left, *right;

    int occ;
    char letter;
    int weight;

    TreeList *nodeList = NULL;

    while (tmp) {
        occ = tmp->occ;
        letter = tmp->occ;
        tmp = pop(tmp);

        insert_tree_node(&nodeList, create_tree_node(occ, letter));
    }
    while (tree_list_len(nodeList) != 1) {
        left = tree_list_min(&nodeList);
        right = tree_list_min(&nodeList);

        weight = left->occ + right->occ;

        tree = create_tree(left, right, weight);
        insert_tree_node(&nodeList, tree);
    }
    tree = tree_list_min(&nodeList);

    return tree;
}

Tree *create_tree(Tree *left, Tree *right, int weight) {
    Tree *tree = create_tree_node(weight, 0);

    tree->left = left;
    tree->right = right;

    if (left)
        left->parent = tree;

    if (right)
        right->parent = tree;

    return tree;
}

Tree *create_tree_node(int occ, char letter) {
    Tree *tree = malloc(sizeof(*tree));

    if (!tree) {
        fprintf(stderr, "Erreur allocation memoire.\n");
        exit(EXIT_FAILURE);
    }

    tree->occ = occ;
    tree->letter = letter;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = NULL;

    return tree;
}

void insert_tree_node(TreeList **list, Tree *node) {

    TreeList *curr = malloc(sizeof(TreeList));
    curr->node = node;
    curr->next = NULL;

    if (!(*list)) *list = curr;
    else {
        TreeList *tmp = *list;

        while (tmp->next)
            tmp = tmp->next;

        tmp->next = curr;
    }
}

void delete_node(TreeList **list, Tree *node) {
    if (*list && node) {
        if (compare_node((*list)->node, node) == 1) {
            TreeList *tmp = *list;

            *list = (*list)->next;

            free(tmp);
        } else delete_node(&((*list)->next), node);

    }

}

int compare_node(Tree *node1, Tree *node2) {
    if (node1 == node2) return 1;
    if (!(node1 || node2)) return 0;
    return (
            (node1->occ == node2->occ)
            && (node1->letter == node2->letter)
            && compare_node(node1->left, node2->left)
            && compare_node(node1->right, node2->right)
    );
}

int tree_list_len(TreeList *list) {
    int len = 0;

    while (list) {
        len++;
        list = list->next;
    }

    return len;
}


Tree *tree_list_min(TreeList **list) {

    if (*list) {
        int min;

        TreeList *curr = *list;
        Tree *node = NULL;

        min = (*list)->node->occ;

        while (curr) {
            if (curr->node->occ <= min) {
                min = curr->node->occ;
                node = curr->node;
            }

            curr = curr->next;
        }

        delete_node(list, node);

        return node;
    } else {
        // todo: implementer si l'arg ets null
        exit(EXIT_FAILURE);
    }
}

void print_tree(Tree *tree) {
    if (!tree) return;

    if (tree->parent != NULL)
        if (tree->letter == 126) printf("{%d}->{%d}\n", tree->parent->occ, tree->occ);
        else printf("{%d}->{%c/%d}\n", tree->parent->occ, tree->letter, tree->occ);
    else
        printf("{%d}\n", tree->occ);

    if (tree->left) print_tree(tree->left);

    if (tree->right) print_tree(tree->right);
}