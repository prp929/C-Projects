/*****************************************************
Hmwk 3: A program to scramble strings
********************Header Files***************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*********************Prototypes**************************/

void scramble_str(char *s);

/*********************ENTER MAIN**************************/

int main(void){
    printf("\n your name \n" );
    int result = 1;
    printf("Enter some strings, or bye to quit: \n");
    char myStr[50];
    char c;
    while (1) {
        int i = 0;
        /****************** Get main string *********************/
        while (1) {     //loop through input, break if you exceed buffer capacity or encounter a newline
            if (i >= 49) //fills 0 - 49 indexes at most
                break;
            scanf("%c", &myStr[i]); //store char to address of array element i
            c = myStr[i];
            if (c == '\n')
                break;
            i++;
        }//end input loop
    /****************** Handle/Scramble Main String *********************/
    myStr[i] = 0; //set string ending; fills index 49 (making it element 50 at max)
    if (!strcmp(myStr, "bye"))
        break;
    scramble_str(myStr);
    printf("%s", myStr);
    putchar('\n'); //had to look this up I guess it doesn't like to printf a single char
    fflush(stdin); //gets rid of any char overflow if more than 30 chars were attempted
    }//end main loop
    printf("I'll be back.");
    return(0);
}//end main

/**********************EXIT MAIN*********************

***********************Functions*********************/
void scramble_str(char *s){
    int p1, p2, len = strlen(s);
    char temp, c1, c2;
    srand(time(0));
    for(int i = 0; i < 1000; i++){ //arbitrary number of swaps
        p1 = rand() % len;
        p2 = rand() % len;
        temp = s[p1];
        s[p1] = s[p2];
        s[p2] = temp;
    }
}//end scramble_str


/**********************End Program**********************/


