#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdbool.h>

typedef struct {
   int length;
   int allocatedSize;
   void (*element_free_fn)(void*);
   int (*element_compareTo_fn)(void*, void*); //pointer to an int returning function that takes 2 args
   
   void **elements;
} ArrayList;

extern const int ARRAYLIST_STARTING_SIZE;
extern const char* STUDENT_ID;

//constructor and destructor and other utility
ArrayList *arraylist_new();
void arraylist_free(ArrayList *list);
int compareTo(ArrayList *list, int a, int b);
void set_element_free_function(void (*fn)(void*), ArrayList *list);
void arraylist_set_compare_to_function(int (*compareTo)(void*, void*), ArrayList *list);


//public functions
int arraylist_length(ArrayList *list); //return number of elements in the ArrayList
bool arraylist_add(void *element, ArrayList *list);
void *arraylist_get(int index, ArrayList *list);
bool arraylist_deleteAt(int index, ArrayList *list); //returns true if a delete occurs, false otherwise
bool arraylist_truncate(int fromIndex, ArrayList *list); //returns true if successful, false otherwise
char *arraylist_toString(ArrayList *list);
void sort(ArrayList *list);
void swap(ArrayList *list, int i, int j);
int isLegit(ArrayList *list); //cleaner way to tell if my list has a compareTo function
int findMin(ArrayList *list);


#endif
