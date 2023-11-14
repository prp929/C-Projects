/*
 Assignment 6 C_Unix
 11/27/2022
    This program is intended to demonstrate the passing of functions as well as to practice dynamic memory management.
    It relies on arraylist.c, arraylist.h, student.c, and student.h
 */

#include <stdio.h>
#include "arraylist.h"
#include "student.h"
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

//Constants
const int numStudents = 20; //CHANGE AS NEEDED

//Prototypes
Student* populateArrayWithStudents(ArrayList *list);
double genRandomGPA();
void printList(ArrayList *list, char *buf);


//ENTER MAIN
int main(void){
    //Initialize variables
    srand(time(0));
    ArrayList *list = arraylist_new();
    set_element_free_function(&student_free, list);
    arraylist_set_compare_to_function(&compareGPA, list);
    char *buf = (char*)malloc(50*sizeof (char));

    //Start doing things
    printf("\nPaul Pezold, 7005981640\n\n");
    populateArrayWithStudents(list);

    //print og list
    printf("************************* Original List: *************************\n");
    printList(list, buf);

    //Print first sort
    printf("\n************************* GPA Sorted List: ************************\n");
    sort(list);
    printList(list, buf);

    //Sort again by last name and print results
    printf("\n********************** Last Name Sorted List: **********************\n");
    arraylist_set_compare_to_function(compareNames, list);
    sort(list);
    printList(list, buf);

    //free up the ol mem bank
    free(buf);
    arraylist_free(list);

    return 0;
}
//END MAIN

//************************************** FUNCTIONS ********************************************************

//fill out the arraylist
Student* populateArrayWithStudents(ArrayList *list){
    char *fn[] = {"James", "Robert", "John", "Mike", "Dave", "Will", "Rick", "Joe",
                  "Thom", "Dan","Pat", "Jen", "Linda", "Eliza", "Barb", "Lucy",
                  "Sue", "Jess", "Sarah", "Min"};
    char *ln[] ={"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller",
                 "Davis", "Schmidt", "Winston","Bishop", "Day", "Cecilia", "Ferguson",
                 "Reagan", "Wilson", "Spike", "Jet", "Faye", "Edward"};
    if(list) {
        for (int i = 0; i < numStudents; i++) {
            Student *s = student_new();
            list->elements[i] = s;
            student_setFName(s, fn[i]);
            student_setLName(s, ln[i]);
            student_setGPA(s, genRandomGPA());
            arraylist_add(s, list);
        }
    }
}

//generate gpas between 1.50 and 4.00
double genRandomGPA() {
    int lower = 150, upper = 400;
    return (rand() % (upper - lower + 1) + 150) / 100.0;
}

//print the student list
void printList(ArrayList *list, char *buf){
    for(int i = 0; i < list->length; i++){
        student_toString((Student*)(list->elements[i]), buf);
        printf("%s\n", buf);
    }
}

//for testing of the compareTo method as pointed to by arraylist
void testCompTo(ArrayList *list){
    int q = numStudents;
    for(int i = 0; i < q; i++){
        for(int j = 0; j<q; j++){
            int t = compareTo(list, i, j);
            printf("CompVal: %d  GPAi: %f  GPAj %f\n", t, ((Student*)list->elements[i])->gpa, ((Student*)list->elements[j])->gpa);
        }
        printf("***\n");
    }
}


