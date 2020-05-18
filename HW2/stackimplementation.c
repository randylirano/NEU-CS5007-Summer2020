/*
CS5007
Homework 2 - Problem 2: Stack Implementation
2020/05/18
Randy Lirano
*/

// This program implements stack using array.
#include <stdio.h>

int stack[100];
int top = -1;

int push(int v){
    if (top >= 99){
        printf("ERROR: Stack capacity exceeded\n");
        return 0;
    } else {
        top++;
        stack[top] = v;
        return 0;
    }
}

int pop(){
    if (top < 0){
        printf("ERROR: Stack is empty\n");
        return 0;
    } else {
        return stack[top--];
    }
}

int isEmpty(){
    if (top < 0){
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int value;
    value = pop();
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
