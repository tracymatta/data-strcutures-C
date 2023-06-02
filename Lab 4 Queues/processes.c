#include <stdio.h>
#include "../Implementations/Queues/Static/Queue.h"

typedef element process;
typedef queue systemQ[N];

void create_system(systemQ t) {
    for(int i = 0; i < N; i++) {
        *(t + i) = CreateQueue();
    }
}

void display(systemQ t) {
    element e;
    queue q = CreateQueue();
    for(int i = N - 1; i >= 0; i--) {
        while(Front(*(t + i), &e)) {
            printf("%d ", e);
            Dequeue(t + i);
            EnQueue(&q, e);
        }
        while(Front(q, &e)) {
            Dequeue(&q);
            EnQueue(t + i, e);
        }
    }
}

int add(systemQ t, process p, element priority) {
    if(priority < 0 || priority >= N) return 0;
    return EnQueue(t + priority, p);
}

int deletePri(systemQ t) {
    int size = N - 1;
    while(size >= 0) { 
        if(!isEmptyQueue(*(t + size))) {
            if(!Dequeue(t + size)) return 0;
            return 1;
        }
        else size--;
    }
    return 0;
}

int nb_elements(systemQ t, element priority) {
    if(priority < 0 || priority >= N) return 0;
    element e;
    int counter = 0;
    queue q = CreateQueue();
    while(Front(*(t + priority), &e)) {
        Dequeue(t + priority);
        EnQueue(&q, e);
        counter += 1;
    }
    while(Front(q, &e)) {
        EnQueue(t + priority, e);
        Dequeue(&q);
    }
    return counter;
}

void modify(int priority1, int priority2, systemQ t) {
    if(priority1 < 0 || priority1 >= N || priority2 < 0 || priority2 >= N) return;
    element e;
    while(Front(*(t + priority1), &e)) {
        EnQueue(t + priority2, e);
        Dequeue(t + priority1);
    }
}

void main() {
    systemQ t;
    create_system(t);
    if(!add(t, 4, 10)) printf("Add failed\n");
    modify(4, 7, t);
    printf("%d\n", nb_elements(t, 1));
    display(t);
    printf("\n");
    if(!add(t, 5, 2)) printf("Add failed\n");
    display(t);
    printf("\n");
    modify(8, 5, t);
    if(!add(t, 2, 12)) printf("Add failed\n");
    printf("%d\n", nb_elements(t, 3));
    display(t);
    printf("\n");
    modify(6, 8, t);
    if(!add(t, 3, 2)) printf("Add failed\n");
    display(t);
    printf("\n");
    deletePri(t);
    display(t);
    printf("\n");
    if(!add(t, 9, 6)) printf("Add failed\n");
    deletePri(t);
    printf("%d\n", nb_elements(t, 2));
    if(!add(t, 10, 2)) printf("Add failed\n");
}