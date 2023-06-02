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

void addNumbersH(node *head1, node *head2, node  **sum, int *carry) {
    if(head1 == NULL && head2 == NULL) return;
    addNumbersH(head1->next, head2->next, sum, carry);
    int add = head1->data + head2-> data + (*carry);
    node *newNode = (node*)malloc(sizeof(node));
    newNode->next = *sum;
    newNode->data = add%10;
    *carry = add/10;
    *sum = newNode;
}

node *addNumbers(node *head1, node *head2) {
    int carry =  0;
    node* sum = NULL;
    addNumbersH(head1, head2 , &sum, &carry);
    if (carry != 0) {
        node *last = (node*)malloc(sizeof(node));
        last->data = carry;
        last->next = sum;
        sum = last;
    }
    return sum;
}

void main() {
    node *head1 = NULL;
    push(&head1, 5);
    push(&head1, 2);
    push(&head1, 1);
    node *head2 = NULL;
    push(&head2, 5);
    push(&head2, 6);
    push(&head2, 1);
    printLL(head1);
    printLL(head2);
    printLL(addNumbers(head1, head2));
}