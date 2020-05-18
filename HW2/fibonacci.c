/*
CS5007
Homework 2 - Problem 1: Fibonacci Number
2020/05/18
Randy Lirano
*/

// This program uses an array to store the first 90 numbers
// in the Fibonacci sequence
#include <stdio.h>

int main() {
    // Initialize an unsigned long array to hold the fibonacci values.
    // fib_0 and fib_1 will be initialized as a starting point for calculations.
    unsigned long int fib[91];
    fib[0] = 0;
    fib[1] = 1;

    // Using for loop to calculate the fibonacci values
    // from fib_2 to fib_90
    for (int i = 2; i < 91; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Using for loop to printout the value of fib_90, fib_80, ..., fib_10
    for (int i = 90; i > 9; i -= 10){
        printf("fib[%d]: %20lu\n", i, fib[i]);
    }

    return 0;
}
