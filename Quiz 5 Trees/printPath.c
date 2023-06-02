#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Btree {
    element data;
    struct Btree *left, *right;
} *Btree;

Btree Construct(element e, Btree L, Btree R) {
    Btree created = (Btree)malloc(sizeof(struct Btree));
    if(!created) return 0;
    created->data = e;
    created->left = L;
    created->right = R;
    return created;
}

int find(Btree B, int toFind) {
    if(B == NULL) return 0;
    else if(B->data == toFind) return 1;
    return find(B->left, toFind) || find(B->right, toFind);
}

Btree lca(Btree root, Btree first, Btree second) {
    if(root == NULL || root->data == '0' || first == NULL || second == NULL) return NULL;
    if((find(root->left, first->data) && find(root->right, second->data)) || (find(root->right, first->data) && find(root->left, second->data))) return root;
    Btree left = lca(root->left, first, second);
    if(left != NULL) return left;
    return lca(root->right, first, second);
}

void printPathDown(Btree lca, Btree second, char *path, int index) {
    if(lca == NULL) return;
    if(lca->data == second->data) {
        *(path + index) = lca->data;
        index += 1;
        *(path + index) = '\0';
        path += 1;
        printf("%s\n", path);
        return;
    }
    *(path + index) = lca->data;
    printPathDown(lca->left, second, path, index + 1);
    printPathDown(lca->right, second, path, index + 1);
}

int printPathUp(Btree first, Btree lca) {
    if(lca == NULL) return 0;
    if(lca->data == first->data) {
        printf("%c", first->data);
        return 1;
    }
    if(printPathUp(first, lca->left) || printPathUp(first, lca->right)) printf("%c", lca->data);
    else return 0;
    return 1;
}

void printPath(Btree root, Btree first, Btree second) {
    Btree common = lca(root, first, second);
    printPathUp(first, common);
    char *T = (char*)malloc(sizeof(char)*20);
    printPathDown(common, second, T, 0);
}

void main() {
    Btree B = Construct('A',
                    Construct('B',
                        Construct('C',
                            Construct('D',
                                Construct('E', 
                                    Construct('F', 
                                        Construct('G', 
                                            Construct('H', 
                                                Construct('I', 
                                                    Construct('0', NULL, NULL),
                                                    Construct('J',
                                                        Construct('0', NULL, NULL),
                                                        Construct('K', 
                                                            Construct('0', NULL, NULL),
                                                            Construct('0', NULL, NULL)))), 
                                                Construct('0', NULL, NULL)), 
                                            Construct('0', NULL, NULL)),
                                        Construct('0', NULL, NULL)),
                                    Construct('L', 
                                        Construct('0', NULL, NULL),
                                        Construct('0', NULL, NULL))),
                                Construct('M', 
                                    Construct('N',
                                        Construct('0', NULL, NULL),
                                        Construct('0', NULL, NULL)),
                                    Construct('O',
                                        Construct('0', NULL, NULL),
                                        Construct('0', NULL, NULL)))),
                            Construct('P',
                                Construct('0', NULL, NULL),
                                Construct('0', NULL, NULL))),
                        Construct('Q',
                            Construct('0', NULL, NULL),
                            Construct('R',
                                Construct('0', NULL, NULL),
                                Construct('S',
                                    Construct('0', NULL, NULL),
                                    Construct('T',
                                        Construct('U', 
                                            Construct('V', 
                                                Construct('0', NULL, NULL),
                                                Construct('0', NULL, NULL)),
                                            Construct('0', NULL, NULL)),
                                        Construct('0', NULL, NULL)))))),
                    Construct('W',
                        Construct('X',
                            Construct('0', NULL, NULL),
                            Construct('0', NULL, NULL)),
                        Construct('Y',
                            Construct('0', NULL, NULL),
                            Construct('Z',
                                Construct('0', NULL, NULL),
                                Construct('0', NULL, NULL)))));
    printf("%c\n", lca(B, Construct('H', NULL, NULL), Construct('V', NULL, NULL))->data);
    printPath(B, Construct('L', NULL, NULL), Construct('N', NULL, NULL));
}