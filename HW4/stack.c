/*
CS5007
Homework 4 - Problem 1: Stack Implementation with Linked List
2020/06/02
Randy Lirano
*/

// This program implement Stack data structure using a linked list

#include <stdio.h>
#include <stdlib.h>

//define the node type
typedef struct stack {
	int data;
	struct stack* next;
} node;

//declare head of list and a temporary pointer
node* top = NULL;
node* temp = NULL;

void push(int d) {
    // 1. Create new node with the give d value
    node* temp = (node*)malloc(sizeof(node));
    temp -> data = d;

    // 2. Add the newly created node form step 1 to the front of the list (top of stack)
    temp -> next = top;
    top = temp;

    // reset temp to null
    temp = NULL;
}

int pop() {
    int val = 0;
    if(top != NULL) {
        temp = top;
        top = top -> next;
        temp -> next = NULL;
        val = temp -> data;
        // reset temp to null
        temp = NULL;
    } else {
        val = 0;
        printf("Error: attempt to remove a null node\n");
    }
    return val;
}

int isEmpty() {
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int value;
    value = pop();
    printf("pop value: %d\n", value);
    push(1);
    push(2);
    push(3);
    value = pop();
    printf("pop value: %d\n", value);
    push(4);
    push(5);
    value = pop();
    printf("pop value: %d\n", value);
    value = pop();
    printf("pop value: %d\n", value);
    push(6);
    value = pop();
    printf("pop value: %d\n", value);
    value = pop();
    printf("pop value: %d\n", value);

    return 0;
}
