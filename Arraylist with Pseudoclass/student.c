/*
 Assignment 6 C_Unix
 11/27/2022
    This program is intended to demonstrate the passing of functions as well as to practice dynamic memory management.
    It relies on arraylist.c, arraylist.h, student.c, and student.h
    My contributions are at the very bottom--two methods of comparison for Student struct members.
 */

#include "student.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>

static unsigned long sequenceNum = 1;

Student *student_new() {
   Student *s = (Student*)malloc(sizeof(Student));
   s->fname = NULL;
   s->lname = NULL;
   s->id = 700200000 + sequenceNum++;
   return s;
}

void student_free(void *s) {
   Student *student = (Student*) s;
   if(student->fname)
      free(student->fname);
   if(student->lname)
      free(student->lname);
   free(s);
}

void student_setFName(Student *s, char *fn) {
  char *str = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
  strncpy(str, fn, MAX_NAME_SIZE - 1);
  s->fname = str;
}

void student_setLName(Student *s, char *ln) {
  char *str = (char*)malloc(sizeof(char) * MAX_NAME_SIZE);
  strncpy(str, ln, MAX_NAME_SIZE - 1);
  s->lname = str;
}

void student_setGPA(Student *s, double gpa) {
   s->gpa = gpa;
}

unsigned long student_Id(Student *s) {
   return s->id;
}

double student_Gpa(Student *s) {
   return s->gpa;
}

void student_fName(Student *s, char *buf) {
   strncpy(buf, s->fname, MAX_NAME_SIZE);
}

void student_lName(Student *s, char *buf) {
   strncpy(buf, s->lname, MAX_NAME_SIZE);
}

void student_toString(Student *s, char *buf) {
   snprintf(buf, MAX_TOSTRING_SIZE, "Student: %10s, %-10s (%9lu) [GPA: %.2f]", s->lname, s->fname, s->id, s->gpa);
}


//****************************** My CompareTo functions****************************************
//Take void pointers and cast to make the compiler happy
int compareGPA(void *a, void *b){
    Student *s1 = (Student*)a;
    Student *s2 = (Student*)b;
    int ans = 0;
    if(a && b) {
        double t = (s1->gpa) - (s2->gpa);
        ans = (int)(t*1000);
    }
    if(ans>0)
        return 1;
    if(ans<0)
        return -1;
    else
        return 0;
}

int compareNames(void* a, void* b){
    Student *s1 = (Student*)a;
    Student *s2 = (Student*)b;
    int t = 0;
    if(a && b) {
        t = strcmp(s1->lname, s2->lname);
    }
    return t;
}
