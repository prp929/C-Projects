//Pointer Arithmetic Demo
#include <stdio.h>
#include<malloc.h>

int main()
{
    //int *myPtr = (int*)malloc(sizeof(int));
    //vPtr[someNumber] is valid tho vPtr is a pointer not an array
    int *vPtr;
    int v[10];
    vPtr = v;

    *vPtr = 1;
    vPtr += 1;
    *vPtr= 3;
    vPtr += 1;
    *vPtr = 2;

    vPtr = v;//must reset to v's loaction for use in print below

    for(int i = 0; i<10; i++){
        printf("%d: %d\n", i, *(vPtr+i));
    }

    return 0;
}

