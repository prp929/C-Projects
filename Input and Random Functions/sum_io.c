//Hmwk 1: A program to receive ten ints and sum them

#include <stdio.h>

int main(void){
   printf(" your name \n" );
   int sum = 0;
   for(int i = 1; i < 11; i++){
      int temp;
      printf("[%d] Gimme an int: ", i );
      scanf("%d", &temp);
      //printf("\n");
      sum += temp; 
   }
   printf("The sum of those ten glorious numbers is %d. Now go away and\nleave me alone.\n", sum);
   return(0);
}//end main
