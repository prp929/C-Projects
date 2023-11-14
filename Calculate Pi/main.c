
//Hmwk 3: A program to calculate PI to various levels of precision

/****************** Header Files ********************************/
#include <stdio.h>
#include <math.h>


/***************** Prototypes ************************************/
double leibniz_pi(int iterations);
int isEven(int n);
void printResults(double ar[][5], int count);
double getError(double myPi);
double viete_pi(int iterations);
double getTopSum(int pL);
double pow(double x, double y);

/***************** Constants ************************************/

const double PI = 4.0 * atan(1.0);



/***************** MAIN *****************************************/

int main(void){
   //Declare variables
   printf("\n700598164 Pezold Paul\n\n" );
   char *topLine[] = {"iterations", "leibniz_pi", "error" ,
                      "viete_pi", "error", "---------"};

   //Print display header
   for(int i = 0; i < 5; i++)
      printf("%-9s\t", topLine[i]);
   printf("\n");
   for(int i = 0; i < 5; i++)
      printf("%9s\t", topLine[5]);
   printf("\n");

   //Populate array
   int count = 7;
   double piVals[count][5];
   for(int i = 0; i < count; i++){
       double passVal = pow( 10.0,(double)(i) );
       piVals[i][0] = passVal;
       piVals[i][1] = leibniz_pi( (int)(passVal) );
       piVals[i][2] = getError( piVals[i][1] );
       piVals[i][3] = viete_pi( (int)(passVal) );
       piVals[i][4] = getError( piVals[i][3] );
   }

   //Print results
   printResults(piVals, count);
   printf("\n");
   //Pray you exit normally
   return(0);

 }//end main

 /******************** EXIT MAIN ********************************/



 /******************** Functions *********************************/

double leibniz_pi(int iterations){
   double ans =  0;
   int n = 1;
   for(int i = 0; i < iterations; i++){
    if (isEven(i) == 1)
      ans += 1.0/n;
    else
       ans -= 1.0/n;
    n+=2;
    }
    return(4.0*ans);
 }//end leibniz_pi



void printResults(double ar[][5], int count ){
   for (int i = 0; i < count; i++){
      for (int j = 0; j < 5; j++){
         if (j == 0 )
             printf("%9d\t", (int)(ar[i][j]) );
         else if (j == 2 || j == 4)
             printf("%2.3f%%    \t", ar[i][j]);
         else
             printf("%1.8f\t", ar[i][j]);
     }
      printf("\n");
   }

}//end printResults



int isEven(int n){
   if( n%2 == 0 )
     return 1;
   else
     return 0;
}//end isEven



double getError(double myPi){
   return ( (PI - myPi) / PI ) * 100;
}//end getError


double viete_pi(int iterations){
   //iteration limit because 1) it doesn't get more precise for value of byte sze double and
   //2) it takes to long to compile with this formula otherwise
   if(iterations > 1000)
     iterations = 1000;
   double ans = 1;
   for(int i = 0; i < iterations; i++)
      ans *= getTopSum(i) ;
   ans = pow(2.0, (iterations+1.0) ) / ans;
   return ans;
}//End viete_pi

double getTopSum(int pL){
    double ans = sqrt(2.0);
    for(int i =0; i<pL; i++){
       ans = 2+ans;
       ans = sqrt(ans);
    }
    return ans;
}//end getTopSum

