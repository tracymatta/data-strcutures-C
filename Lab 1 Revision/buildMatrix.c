#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row, col, value;
} element;

typedef struct matrix {
    element data;
    struct matrix *down, *right;
} matrix;

void printMatrix(matrix *built) {
    matrix *toPrint = built;
    if(toPrint == NULL) printf("empty");
    printf("rows:%d columns:%d\n", (toPrint->data).row, (toPrint->data).col);
    toPrint = toPrint->right;
    printf("head node:%d %d %d\n", (toPrint->data).row, (toPrint->data).col, (toPrint->data).value);
    toPrint = toPrint->right;
    for( ; toPrint != built->right; toPrint = toPrint->right) {
        printf("row:%d column:%d value:%d down:%d\n", (toPrint->data).row, (toPrint->data).col, (toPrint->data).value, (toPrint->down->data).value);
    }
}

void push(matrix **toPushAt, int row, int col, int value) {
    matrix *newMatrix = (matrix*)malloc(sizeof(matrix));
    (newMatrix->data).row = row;
    (newMatrix->data).col = col;
    if(value != 0) (newMatrix->data).value = value;
    newMatrix->right = *toPushAt;
    *toPushAt = newMatrix;
}

matrix* buildMatrix() {
    matrix *toBuild = NULL;
    matrix **toPushAt = &toBuild;
    int row, col, value;
    scanf("%d %d", &row, &col);
    push(toPushAt, row, col, 0);
    toPushAt = &((*toPushAt)->right);
    row = 0;
    col = 0;
    value = 0;
    while(1) {
        push(toPushAt, row, col, value);
        if(scanf("%d %d %d", &row, &col, &value) != 3) break;
        if(row == 0 && col == 0 && value == 0) break;
        toPushAt = &((*toPushAt)->right);
    }
    (*toPushAt)->right = toBuild->right;
    matrix *least = toBuild->right->right;
    for(matrix *toFix = toBuild->right->right; toFix != toBuild->right; toFix = toFix->right) {
        toFix->down = toFix;
        for(matrix *toSearch = toBuild->right->right; toSearch != toBuild->right; toSearch = toSearch->right) {
            if(toFix->down == toFix && ((toSearch->data).col > (toFix->data).col || ((toSearch->data).col == (toFix->data).col && (toSearch->data).row > (toFix->data).row))) toFix->down = toSearch;
            else if(toFix->down != toFix) {
                if((toSearch->data).col < (toFix->down->data).col && (toSearch->data).col > (toFix->data).col) toFix->down = toSearch;
                else if((toSearch->data).col < (toFix->down->data).col && (toSearch->data).col == (toFix->data).col && (toSearch->data).row > (toFix->data).row) toFix->down = toSearch;
                else if((toSearch->data).col == (toFix->down->data).col && (toSearch->data).row < (toFix->down->data).row) toFix->down = toSearch;
            }
            if((toSearch->data).col < (least->data).col) least = toSearch;
            else if((toSearch->data).col == (least->data).col && (toSearch->data).row < (least->data).row) least = toSearch;
        }
        if(toFix->down == toFix) toFix->down = toBuild->right;
    }
    toBuild->right->down = least;
    return toBuild;
}

void main() {
    matrix *built = buildMatrix();
    printMatrix(built);
}