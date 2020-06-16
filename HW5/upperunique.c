/*
CS5007
Homework 5 - Problem 1: Unique Uppercase
2020/06/08
Randy Lirano
*/

/*
This program repeatedly as for user input until user provide a quit command.
Convert user input into uppercase, and keep track for unique letters used.
The unique letters will then be printed along with its hex code.
*/

#include <stdio.h>
#include <string.h>

// Maximum length of string in this program
#define STRLENGTH 1000

// User input from console will be stored in userInput variable
char userInput[STRLENGTH];

char uniqueLetter[STRLENGTH];

// Character pointer to check the first appearance of character in String
char *chPointer;

// Quit command that will terminate the program from prompting input from user
char quitCommand[5] = "QUIT\n";

// Check to see if user put the quit program command
int quitProgram;

// Index for looping
int i;

int main() {
    // Querry for user input at least once
    printf("input a string (QUIT for done): ");
    fgets(userInput, STRLENGTH, stdin);

    // Convert provided input into upper case
    for (i = 0; i < strlen(userInput); i++) {
        if (('a' <= userInput[i]) && (userInput[i] <= 'z')) {
            userInput[i] = userInput[i] - 0x20;
        } else {
            userInput[i] = userInput[i];
        }
    }

    // Check for quit command
    quitProgram = strcmp(userInput, quitCommand);

    // While quit command not provided
    while (quitProgram != 0) {
        // Print the provided user input
        printf("The provided input: %s\n", userInput);

        // Iterate the input to check for unique character
        // and store the character into uniqueLetter array
        for (i = 0; i < strlen(userInput); i++) {
            chPointer = strchr(uniqueLetter, userInput[i]);
            if (chPointer == NULL) {
                char char2str[2] = "";
                char myChar = userInput[i];
                char2str[0] = myChar;
                strcat(uniqueLetter, char2str);
            }
        }

        // Print out the uniqueLetter collection, character-by-character
        for (i = 0; i < strlen(uniqueLetter); i++) {
            if (uniqueLetter[i] != '\n') {
                printf("%2c -- 0x%.2x\n", uniqueLetter[i], uniqueLetter[i]);
            } else {
                printf("\\n -- 0x%.2x\n", uniqueLetter[i]);
            }

        }

        // Empty the uniqueLetter collection for next user input
        uniqueLetter[0] = '\0';

        printf("input a string (QUIT for done): ");
        fgets(userInput, STRLENGTH, stdin);

        for (i = 0; i < strlen(userInput); i++) {
            if (('a' <= userInput[i]) && (userInput[i] <= 'z')) {
                userInput[i] = userInput[i] - 0x20;
            } else {
                userInput[i] = userInput[i];
            }
        }
        quitProgram = strcmp(userInput, quitCommand);
    }
    printf("end program");

    return 0;
}
