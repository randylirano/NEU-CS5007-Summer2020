/*
CS5007
Homework 3 - Problem 1: Read States
2020/05/26
Randy Lirano
*/

/*
This program reads a text file containing state abbreviation, population, and name,
and build database from it.
It will then prompt user for a state abbreviation.
If it exist, the program print out the name and population of the state;
otherwise, it will print an error message.
*/
#include <stdio.h>
#include <string.h>

//maximum length of string in this program
#define STRLENGTH 50

//number of states in our database
#define STATESIZE 52

//each record of the database is a line with
//2 letter state abbreviation
//state population (integer)
//state name - up to 3 words long (District of Columbia)
typedef struct sd {
  char abbr[2];
  int  pop;
  char name1[STRLENGTH];
  char name2[STRLENGTH];
  char name3[STRLENGTH];
} stateData;

//declare "database" to hold all the input records
stateData database[STATESIZE];

//temporary variable to read each line from the input file
char inputLine[STRLENGTH];

//user input from console will be stored in userInput variable
char userInput[4];

//variable to store comparison result between the state abbreviation
//that user provided with the available state abbreviation in data base
int compResult;

//pointers for for-loop and while-loop
int i;
int j;

//file handle for input file
FILE* dataFile;


int main() {
  //open the input file
  dataFile = fopen("statepop.txt","r");

  if (dataFile != NULL) {
    //build database from the given text file using an array
    for (i=0; i<STATESIZE; i++) {
      //for each line of input, read it in
      fgets(inputLine, STRLENGTH, dataFile);

      //split it into abbreviation, population, and state name
      sscanf(inputLine, "%s %d %s %s %s",
	     database[i].abbr,
	     &database[i].pop,
	     database[i].name1,
	     database[i].name2,
	     database[i].name3
	     );
    }

    printf("Enter state abbreviation: ");
    scanf("%s", userInput);
    compResult = strcmp(userInput,database[j].abbr);
    while(compResult != 0 && j < STATESIZE) {
        j++;
        compResult = strcmp(userInput,database[j].abbr);
    }
    if(compResult == 0) {
        printf("%s %s %s %d\n", database[j].name1, database[j].name2, database[j].name3, database[j].pop);
    } else {
        printf("No such state\n");
    }

  } else {
    //handle the error when the file doess not exist
    printf("Data file not found");
  }

  //debugging print
  printf("End of program\n");

  //close the open file and end program
  fclose(dataFile);
  return 0;
}
