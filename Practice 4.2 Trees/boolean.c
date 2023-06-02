#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[4];

typedef struct {
    char var [5];
    int val;
} Couple;

typedef struct node {
    element value;
    struct node *left, *right;
} *Expression;

typedef struct {
    Couple arr[100];
    int size;
} Interpretation;

Expression Construct(element value, Expression L, Expression R) {
    Expression E = (Expression) malloc (sizeof(struct node));
    strcpy(E->value, value);
    E->left = L;
    E->right = R;
    return E;
}

int find_val(Interpretation In, char v[], int *value) {
	for(int i = 0; i < In.size; i++) {
        if(strcmp(v, In.arr[i].var) == 0) {
            *value = In.arr[i].val;
            return 1;
        }
    }
    return 0;
}

int Evaluate(Interpretation I, Expression E, int *value)  {
	if(E == NULL) {
	    return 0;
	}
    if(E->left == NULL && E->right == NULL) {
        return find_val(I, E->value, value);
    }
    if(strcmp(E->value, "AND") == 0) {
        int one;
        Evaluate(I, E->left, &one);
        int two;
        Evaluate(I, E->right, &two);
        *value = one && two;
        return 1;
    }
    else if(strcmp(E->value, "OR") == 0 ) {
        int one;
        if(Evaluate(I, E->left, &one) == 0) return 0;
        int two;
        if(Evaluate(I, E->right, &two) == 0) return 0;
        *value = one || two;
        return 1;
    }
    else if(strcmp(E->value, "NOT") == 0) {
        if(E->left == NULL) {
            int one;
            if(Evaluate(I, E->right, &one) == 0) return 0;
            if(one == 0) *value = 1;
            else *value = 0;
        } 
        else if(E->right == NULL) {
            int one;
            if(Evaluate(I, E->left, &one) == 0) return 0;
            if(one == 0) *value = 1;
            else *value = 0;
        } 
        return 1;
    }
    else {
        return 0;
    }
}

int Valid(Interpretation arrayInter[], int NBInter, Expression E) {
	int value;
    for(int i = 0; i< NBInter; i++) {
        if(Evaluate(arrayInter[i], E, &value) == 0) return -1;
        if(value == 0) return 0;
    }
    return 1;
}

void main() {
    Interpretation I = {{{"a1", 1}, {"bool2", 0}, {"bx30", 0}}, 3};
    Expression E = Construct("AND",
                        Construct("a1", 
                            NULL,
                            NULL
                        ),
                        Construct("NOT", 
                            NULL,
                            Construct("OR",
                                Construct("bool2",
                                    NULL,
                                    NULL
                                ),
                                Construct("bx30",
                                    NULL,
                                    NULL
                                )
                            )
                        )
                    );
    int value;
    Evaluate(I, E, &value);
    printf("Evaluation = %d\n", value);
}
