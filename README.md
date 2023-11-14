# C-Projects

-> is equivalent to the dot (.) operator in OO languages  

Data Type Sizes
	char- 1 byte/8 bits
	short- 2 bytes
	int- 4 bytes
	long- 8 
	float 4
	double 8

2^# bits is value range, signed / unsigned splits value

selection statement: if, switch, ternerary, loops, 
0 is false all else is true as bools 
argc argv[]
type casting, malloc, autocasting rules(implicit)

quiz overview:
1. char* p1, p2; is NOT == char *p1; char *p2;
2. int a = 10; int b = a*10; printf("%p", &b); //this code displays address of b; %p is pointer code
3. int alpha[10]; int *p = alpha; //in this case, alpha[3] == *(p+3)  and takes %d placeholder 
4. passing a pointer will cause persistent changes to pointer's contents
5. For the code:
	char buf[20]; // make char array 
	char *ptr = buffer; //ptr points to buffer[0] (they're the same)
	*ptr = 6 ; //value of buf[0] = 6 now
	ptr += *ptr; //ptr is now pointing to *(ptr + 6) or buf[6]
	alternately, if you had *ptr += *ptr, the answer would be buf[0] = 0x0c or 12 expressed in hexadecimal 
 
 ex. 2d array:
 int** h : an array of pointers to int arrays which are pointers
	int* 0 --> int0 int1 int2 ...
	int* 1 --> int0 int1 int2 ...
	int* 2 --> int0 int1 int2 ...
	
int **h = (int**)malloc(5*sizeof(int*)); //allocates a list of length 5 int ptrs
for loop to intiialize;
	for(int i=0; i<len; i++){
		h[i] = (int*)malloc(len*sizeof(int));
	}
to free them, you must free int* 0, int* 1, int*2... and then free int** h 
However, if the pointers were void* and pointing to an object with mallocd fields, you must free those fields first and then back out 
--string code
--take arrays and manipulate them 
--declare struct, printf stuff, use standard library function

C_Unix:
	To make header file, see example circle.h; this is functionally a class. Then see circle.c for method implementation
	To compile, you must #inlcude "circle.h" in your circle.c; then, you must link them with gcc prg1.o prgOfMethods.o -lm
	to get the file.o, simply use gcc myPrgm -m //this output is compile only; then simply link the compiled files and finally 
		run a.out
	CMakeLists.txt is where to add header file in clion
	
Arraylist in C:
	1. header file is interface like (java term) (ArrLi struct def, method headers, attributes)
	2. int is numElements; array elements are of type void** --> can be pointers to anything
		2.5. int allocatedSize is the capacity of the array 
	3. void pointer is a pointer to anything; so will have to cast things at point of use
	4. extern before a constant makes it visible everywhere
	5. next is constructor and destructor (first is pointer to arrayList w/no args; the second
		is void destructor with arg of arraylist list*)
	6. int length receive a al list* to work on/ report back numElements
	7. also type bool in the case malloc fails al_add receives list* + a pointer to some sort of object (void *element)
	8. get() is void* takes an index and returns elements from list*
	9. deleteAt is boolean (#include <stdbool.h>) and takes and arrayList* and index to deleteAt
	10. char al_toString* takes a list* and is c string
	11. memcpy(target*, source*, sizeof(elements*) //target and src shouldnt include *
	12. note that length attribute is numElements; ie length = 5 means 5 elements w/max index of 4