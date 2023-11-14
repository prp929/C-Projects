/*
 Assignment 6 C_Unix
 11/27/2022
    This program is intended to demonstrate the passing of functions as well as to practice dynamic memory management.
    It relies on arraylist.c, arraylist.h, student.c, and student.h
    My contributions are at the very bottom--two methods of comparison for Student struct members.
 */

#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_SIZE 20
#define MAX_TOSTRING_SIZE 60

typedef struct {
   unsigned long id;
   char *fname;
   char *lname;
   double gpa;
} Student;

Student *student_new();
void student_free(void *s);
void student_setFName(Student *s, char *fn);
void student_setLName(Student *s, char *ln);
void student_setGPA(Student *s, double gpa);
unsigned long student_Id(Student *s); //return student's ID number
double student_Gpa(Student *s); //return GPA
void student_fName(Student *s, char *buf); //return pointer to first name
void student_lName(Student *s, char *buf); //return pointer to last name
void student_toString(Student *s, char *buf);

//My additions:
int compareGPA(void *a, void *b);
int compareNames(void* a, void* b);

#endif
