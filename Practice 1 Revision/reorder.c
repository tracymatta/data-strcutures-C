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

node **helper(node **head, node *tail, int count, int *c){
    if(tail == NULL){
        *c = count;
        return head;
    }
    node** ptr = helper( head, tail->next, count+1, c);
    if((*ptr) == NULL){
        return ptr;
    }
    if(count < (*c)/2 || *ptr == tail) {
        tail->next = NULL;
        return &(tail->next);
    }
    node** next = &((*ptr)->next);  
    tail->next = *ptr;
    (*ptr) = tail;
    return next;
}

void reorder(node **headRef)
{
    int c = 0;
    helper(headRef, *headRef , 0 , &c);
}

void main() {
    node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printLL(head);
    reorder(&head);
    printLL(head);
}