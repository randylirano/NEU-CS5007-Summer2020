/*
CS5007
Homework 4 - Problem 2: FSM for legal number
2020/06/02
Randy Lirano
*/

// This program analyze the given input to check if it's a valid hex numbers combination

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int state = 0;

int i = 0;

int length;

char input[50] = "0Xabcdefg01234567";

int main () {
    length = strlen(input);

    for(i = 0; i < length; i++) {
        // Report current state and input
        printf("In state %d - ", state);
        printf("input %c - ", input[i]);

        switch(state) {
            case 0:
                // Initial state
                if(input[i] == '0') {
                    state = 1;
                } else {
                    state = 4;
                }
                break;
            case 1:
                if((input[i] == 'X') || (input[i] == 'x')) {
                    state = 2;
                } else {
                    state = 4;
                }
                break;
            case 2:
                if((('0' <= input[i]) && (input[i] <= '9')) || (('A' <= input[i]) && (input[i] <= 'F')) || (('a' <= input[i]) && (input[i] <= 'f'))) {
                    state = 3;
                } else {
                    state = 4;
                }
                break;
            case 3:
                if((('0' <= input[i]) && (input[i] <= '9')) || (('A' <= input[i]) && (input[i] <= 'F')) || (('a' <= input[i]) && (input[i] <= 'f'))) {
                    state = 3;
                } else {
                    state = 4;
                }
                break;
            case 4:
                // Rejecting state
                state = 4;
                break;
            default:
                printf("illegal state! - ");
                break;
        }

        // report new state
        printf("new state %d\n", state);
    }

    if (state == 3) {
      printf("\n|%s| IS a legal number\n", input);
    } else {
      printf("\n|%s| is NOT a legal number\n", input);
    }
}
