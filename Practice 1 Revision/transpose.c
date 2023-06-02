#include <stdio.h>
#include <stdlib.h>

typedef struct entry {
    int data;
    int col_num;
    struct entry *next;
} entry;

typedef struct row {
    int row_num;
    entry *start;
    struct row *next;
} row;

void printSparse(row *toPrintSparse) {
    for(row *currentRow = toPrintSparse; currentRow != NULL; currentRow = currentRow->next) {
        printf("row %d contains ", currentRow->row_num);
        for(entry *currentEntry = currentRow->start; currentEntry != NULL; currentEntry = currentEntry->next) {
            printf("(col %d, data %d)", currentEntry->col_num, currentEntry->data);
            if(currentEntry->next != NULL) printf(", ");
        }
        printf("\n");
    }
    printf("\n");
}

void pushSortedIntoSparse(row **toPushInto, int rowNumber, int colNumber, int data) {
    row *currentRow = (*toPushInto);
    row **beforeCurrentRow = toPushInto;
    for( ; currentRow != NULL && rowNumber > currentRow->row_num; beforeCurrentRow = &((*beforeCurrentRow)->next), currentRow = currentRow->next);
    if(currentRow == NULL || currentRow->row_num != rowNumber) {
        row *newRow = (row*)malloc(sizeof(row));
        entry *newEntry = (entry*)malloc(sizeof(entry));
        newEntry->col_num = colNumber;
        newEntry->data = data;
        newEntry->next = NULL;
        newRow->row_num = rowNumber;
        newRow->start = newEntry;
        newRow->next = currentRow;
        (*beforeCurrentRow) = newRow;
        return;
    }
    entry *currentEntry = currentRow->start;
    entry **beforeCurrentEntry = &(currentRow->start);
    for( ; currentEntry != NULL && colNumber > currentEntry->col_num; beforeCurrentEntry = &((*beforeCurrentEntry)->next), currentEntry = currentEntry->next);
    if(currentEntry == NULL || currentEntry->col_num != colNumber) {
        entry *newEntry = (entry*)malloc(sizeof(entry));
        newEntry->col_num = colNumber;
        newEntry->data = data;
        newEntry->next = currentEntry;
        (*beforeCurrentEntry) = newEntry;
    }
}

void transpose(row **sparse) {
    row *newSparse = NULL;
    for(row **currentRow = sparse; *currentRow != NULL; ) {
        for(entry **currentEntry = &((*currentRow)->start); *currentEntry != NULL; ) {
            pushSortedIntoSparse(&newSparse, (*currentEntry)->col_num, (*currentRow)->row_num, (*currentEntry)->data);
            entry *entryToFree = (*currentEntry);
            (*currentEntry) = (*currentEntry)->next;
            free(entryToFree);
        }
        row *rowToFree = (*currentRow);
        (*currentRow) = (*currentRow)->next;
        free(rowToFree);
    }
    *sparse = newSparse;
}

void main() {
    row *exampleSparse = NULL;
    pushSortedIntoSparse(&exampleSparse, 1, 4, 1);
    pushSortedIntoSparse(&exampleSparse, 1, 8, 3);
    pushSortedIntoSparse(&exampleSparse, 1, 9, -1);
    pushSortedIntoSparse(&exampleSparse, 2, 1, 3);
    pushSortedIntoSparse(&exampleSparse, 2, 6, 4);
    pushSortedIntoSparse(&exampleSparse, 3, 2, 4);
    pushSortedIntoSparse(&exampleSparse, 3, 4, 7);
    pushSortedIntoSparse(&exampleSparse, 3, 5, 2);
    pushSortedIntoSparse(&exampleSparse, 3, 8, 1);
    pushSortedIntoSparse(&exampleSparse, 6, 4, 41);
    printSparse(exampleSparse);
    transpose(&exampleSparse);
    printSparse(exampleSparse);
}