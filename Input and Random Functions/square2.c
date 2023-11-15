#include <stdio.h>

int main(void){

  // int n = 99;
   int myNum;
  // printf("Enter your number, no decimal: ");
  // scanf("%d", &myNum); //put this info into mem location of myNum / pointer
  // printf("My Num is %d at location %d\n and the second is %d\n" , myNum,(int)&myNum, n*n);
   while(1){
      int temp;
      printf("Enter your number, 0 to quit: ");
      scanf("%d", &temp);
         if (temp ==0)
            break;
      printf("You entered %d\n", temp);
   }
   printf("\n");
   return (0);
   
}//end main
