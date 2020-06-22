#include <stdio.h>
#include <stdlib.h> // The library that contains malloc/free

#define HOWMANY 10

int i;

typedef struct nd {
    int data;
    struct nd* next;
} node;

node* backbone[HOWMANY];

int main() {
    for (i=0; i<HOWMANY; i++) {
        backbone[i] = (node*)malloc(sizeof(node));
        backbone[i]->data = 20-(2*i);
        backbone[i]->next = NULL;
    }

    for (i=0; i<HOWMANY; i++) {
        backbone[i]->next = (node*)malloc(sizeof(node));
        (backbone[i]->next)->data = 300*i;
        if (i<9){
            (backbone[i]->next)->next = backbone[i+1];
        } else {
            (backbone[i]->next)->next = backbone[0];
        }
    }
    printf("%d\n",
                (backbone[1]->data) *
                ((((backbone[2]->next)->next)->next)->data));

    return 0;
}
