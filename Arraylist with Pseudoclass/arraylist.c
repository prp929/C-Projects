/*
 Assignment 6 C_Unix
 11/27/2022
    This program is intended to demonstrate the passing of functions as well as to practice dynamic memory management.
    It relies on arraylist.c, arraylist.h, student.c, and student.h
    My contributions are at the middle/bottom--most importantly, my setter, sort, and swap functions.
 */

#include "arraylist.h"
#include <malloc.h>
#include <stdio.h>

const int ARRAYLIST_STARTING_SIZE = 10;

//
// private functions
//

bool grow(ArrayList *list) {
   if(!list) return false;

   //allocate a new array
   void **newElements = (void*) malloc(list->allocatedSize * 2 * sizeof(void*));
   if(!newElements) return false;

   //copy the elements from old to new
   // equivalent to below: memcpy(newElements, list->elements, list->length * sizeof(void*));
   for(int i = 0; i < list->length; ++i) {
      newElements[i] = list->elements[i];
   }

   //swap in the new array, deallocate the old one
   void **oldArray = list->elements;
   list->elements = newElements;
   list->allocatedSize = 2 * list->allocatedSize;
   free(oldArray);
   return true; //success!
}

//
//constructors, destructors
//
ArrayList *arraylist_new() {
   ArrayList *al = (ArrayList*) malloc(sizeof(ArrayList));
   al->length = 0;
   al->allocatedSize = ARRAYLIST_STARTING_SIZE;
   al->element_free_fn = NULL;
   al->element_compareTo_fn = NULL;
   al->elements = (void*) malloc(al->allocatedSize * sizeof(void*));
   return al;
}

void arraylist_free(ArrayList *list) {
   if(list) {
      if(list->elements) {
         for(int i = 0; i < list->length; ++i) {
            if(list->element_free_fn)
               list->element_free_fn(list->elements[i]);
            else
               free(list->elements[i]);
         }
         free(list->elements);
      }
      free(list);
   }
}

/************************ MY CONTRIBUTIONS *************************************/

int compareTo(ArrayList *list, int a, int b){
    if(isLegit(list)){
        return list->element_compareTo_fn(list->elements[a], list->elements[b]);
    }
    //every compareTo class instance will return an int based on
    //some class specific implementation that compares 2 members
    //of the list
}

//not a very efficient algo but it does the job
void sort(ArrayList *list) {
    if(isLegit(list)) {
        int len = list->length;
        for(int i = 0; i < len; i++){
            for(int j = 0; j<len; j++){
                if(compareTo(list, i, j) < 0) //flip sign and reverse the order
                    swap(list, i, j);
            }
        }
    }
}//end sort


void swap(ArrayList *list, int i, int j){
    void *temp; //(void*)malloc(sizeof(list->elements[0]));
    if(list->elements[i] && list->elements[j] ){
        temp = list->elements[i];
        list->elements[i] = list->elements[j];
        list->elements[j] = temp;
    }
    //free(temp); //didn't really need malloc but it's good practice
}

//unused; was originally going to be used in my sort algo
int findMin(ArrayList *list){
    int mIndex = 0;
    for(int i = 0; i < list->length; i++){
        if(compareTo(list, i, mIndex) < 0)
            mIndex = i;
    }
    return mIndex;
}

//I just made this because it annoyed me to look at all those conditionals
int isLegit(ArrayList *list){
    if (!list)
        return 0;
    if(!list->elements)
        return 0;
    if(!list->element_compareTo_fn)
        return 0;
    return 1;
}

//basic set function
void arraylist_set_compare_to_function(int (*compareTo)(void*, void*), ArrayList *list){
    list->element_compareTo_fn = compareTo;
}


/**************************** End my contributions ****************************************************/

void set_element_free_function(void (*fn)(void*), ArrayList *list) {
   list->element_free_fn = fn;
}

int arraylist_length(ArrayList *list) {
   return list ? list->length : -1;
}

bool arraylist_add(void *element, ArrayList *list) {
   //grow the array if necessary
   if(list->length == list->allocatedSize) {
      if(!grow(list))
         return false;
   }

   list->elements[list->length] = element;
   list->length++;
   return true;
}

void *arraylist_get(int index, ArrayList *list) {
   if(list && list->length > index)
      return list->elements[index];
   else
      return NULL;
}

bool arraylist_deleteAt(int index, ArrayList *list) {
   if(index < 0 || index >= list->length) return false;
   if(list->element_free_fn)
      list->element_free_fn(list->elements[index]);
   else
      free(list->elements[index]);
   for(int i = index; i < list->length - 1; ++i) {
      list->elements[i] = list->elements[i + 1];
   }
   list->length--;
   return true;
}

bool arraylist_truncate(int fromIndex, ArrayList *list) {
   if(fromIndex < 0 || fromIndex >= list->length) return false;
   for(int i = fromIndex; i < list->length; ++i) {
      free(list->elements[i]);
   }
   list->length = fromIndex;
   return true;
}

char *arraylist_toString(ArrayList *list) {
  int size = 50;
  char *buf = (char*) malloc(size * sizeof(char));
  snprintf(buf, size, "ArrayList: length=%d, allocated size=%d", list->length, list->allocatedSize);
  return buf;
}

