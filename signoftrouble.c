// Assingment 1
// Taylor Winn

#include <stdio.h>
#include <stdlib.h>     // including important libraries 
#include <string.h>
#include <stdbool.h>

int main(){     // creating the main function as type int in order to return as 0

    int determineNum(char one[], char two[]);   // including the function header for the funtion that determines the number of chacters needed to create second string

    int strsize = 100002;       // creating variable for the initial size of the string with size 100,002 
    char *inpt1;    // creating a pointer to a character variable for input and output
    char *inpt2;

    inpt1 = (char*)malloc(sizeof(char) * strsize);  // allocating memory for both input and output variables via malloc, size is still 100,002
    inpt2 = (char*)malloc(sizeof(char) * strsize);


    if(inpt1 == NULL || inpt2 == NULL){ // making sure the memory was allocated correctly
        printf("not allocated");
    }

    printf("enter first sequence: ");   // prompting input for first string
    fgets(inpt1, strsize, stdin);   // storing the first string in input variable inpt1
    printf("enter second sequence: ");
    fgets(inpt2, strsize, stdin);
    
    strsize = strlen(inpt1);    // redefining the size in order to reduce memory allocated, new size will be the length of the string inputted
    inpt1 = realloc(inpt1, strsize * sizeof(char)); // reallocating memory using realloc function
    strsize = strlen(inpt2);
    inpt2 = realloc(inpt2, strsize * sizeof(char));
    if(inpt1 == NULL || inpt2 == NULL){ // making sure the memory was reallocated
        printf("error allocating");
    }


    printf("\n%d characters needed", determineNum(inpt1, inpt2));   // returning the value (answer) given by the determineNum function

    free(inpt1);    // freeing the memory for both of the dynamic character arrays 
    free(inpt2);
return 0;
}

int determineNum(char one[], char two[]){   // defining the determineNum function as type int to return the answer, taking the two input strings as parameters
    int i = 0;
    int freq[127] = { 0 };  // creating a frequency array containing 127 indexs, that is the decimal conversion of character max
    while(one[i] != '\0'){  // while not at the end of the string, the loop will execute (through every character)
        freq[one[i] - 'A']++;   // increment the frequency array accordingly 
        i++;
    }

    puts("");

    int count = 0;  // doing the same for the second input string
    int j = 0;
    int nfreq[127] = { 0 };
    while(two[j] != '\0'){
        nfreq[two[j] - 'A']++;
        j++;
    }
    for(int i = 0; i < 127; i++){   // for loop to loop through the frequency array indexs
        if(freq[i] != 0 || nfreq[i] != 0){  // executes as long as there is actually a value stored at that index, meaning the character was included in the string
            // printf("\n%d - %d", nfreq[i], freq[i]);
            int test = nfreq[i] - freq[i];  // test variable to check how many characters are missing 
            if(test > 0){
                count += test;; // add the nessesary characters to the overall count needed to complete the string
            }
        }
    }
    return count;   // return the answer to the main function

    // will return 0 if the number of character in the first string was greater than the number needed in the second (you cannot need negative characters)
}

