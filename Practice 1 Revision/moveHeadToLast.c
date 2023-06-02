#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void addNode(node **headref, int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next= *headref;
    *headref = newnode;
}

void printLL(node *headref){
    if(!headref) printf("empty");
    for( ; headref!=NULL; headref=headref->next) {
        printf("%d ", headref->data);
    }
    printf("\n");
}

void moveHeadToLast(node **headref) {
    if(!headref || !*headref || !(*headref)->next) return;
    node *temp = (*headref)->next;
    (*headref)->next = (*headref)->next->next;
    temp->next = *headref;
    *headref = temp;
    moveHeadToLast(&((*headref)->next));
}

void main() {
    node *head=NULL;
    addNode(&head, 4);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);
    printLL(head);
    moveHeadToLast(&head);
    printLL(head);
}