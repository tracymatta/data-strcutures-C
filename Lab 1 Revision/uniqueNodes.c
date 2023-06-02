#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void push(node **headref, int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *headref;
    *headref = newnode;
}

void printLL(node *head) {
    if(head==NULL) printf("empty");
    for( ; head!=NULL; head=head->next) {
        printf("%d ", head->data);
    }
    printf("\n");
}

void deleteAllOcc(node **headref, int data, int *flag) {
    if(*headref == NULL) return;
    if((*headref)->data == data) {
        node *toFree = (*headref);
        (*headref) = (*headref)->next;
        free(toFree);
        *flag = 1;
        deleteAllOcc(headref, data, flag);
    }
    else deleteAllOcc(&((*headref)->next), data, flag);
}

void uniqueNodes(node **headref) {
    if(*headref == NULL) return;
    int flag = 0;
    deleteAllOcc(&((*headref)->next), (*headref)->data, &flag);
    if(flag==1) {
        node *toFree = (*headref);
        (*headref) = (*headref)->next;
        free(toFree);
        uniqueNodes(headref);
    }
    else uniqueNodes(&((*headref)->next));
}

void main() {
    node *head = NULL;
    push(&head, 1);
    push(&head, 1);
    push(&head, 8);
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 1);
    push(&head, 1);
    push(&head, 6);
    push(&head, 5);
    push(&head, 3);
    push(&head, 1);
    printLL(head);
    uniqueNodes(&head);
    printLL(head);
}