/*Header File layout: contains only method signatures and variables*/

#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct {
   double x;
   double y;
   double radius;
   int id;
} Circle;

Circle *circle_new(double x, double y, double r); //construct a new Circle
Circle *circle_randomNew(double min_x, double max_x, double min_y, double max_y, double min_r, double max_r);
void circle_initRandom(void);
int circle_overlap(Circle *c1, Circle *c2); //returns 0 if they do not overlap, otherwise 1
char *circle_toString(Circle* c);

#endif

/********************************************************************************************************/

/* Would then be implemented in a .c file as below. Note that you must use a -> to reference an object's members,
AND you must pass yourself to the method that will work on you */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "circle.h"

int circle_Id = 0;

double sqr(double d) {
   return d * d;
}

int circle_overlap(Circle *c1, Circle *c2) {
   double dx, dy, distance;
   dx = c1->x - c2->x;
   dy = c1->y - c2->y;
   distance = sqrt(sqr(dx) + sqr(dy));
   return distance < c1->radius + c2->radius;
}

Circle *circle_new(double x, double y, double r) {
   Circle *p = (Circle*)malloc(sizeof(Circle));
   p->x = x;
   p->y = y;
   p->radius = r;
   p->id = circle_Id++;
   return p;
}

Circle *circle_randomNew(double min_x, double max_x, double min_y, double max_y, double min_r, double max_r) {
   double rx = max_x - min_x;
   double ry = max_y - min_y;
   double rr = max_r - min_r;

   double random = ((double)rand()) / RAND_MAX; //between 0 and 1
   double x = random * rx + min_x;
   random = ((double)rand()) / RAND_MAX; //between 0 and 1
   double y = random * ry + min_y;
   random = ((double)rand()) / RAND_MAX; //between 0 and 1
   double r = random * rr + min_r;

   return circle_new(x, y, r);
}

void circle_initRandom() {
   srand(time(NULL));
}

char *circle_toString(Circle *c) {
   int size = 50;
   char *buf = (char*)malloc(size * sizeof(char));
   snprintf(buf, size, "Circle: id=%d, x=%.3f, y=%.3f, r=%.3f", c->id, c->x, c->y, c->radius);
   return buf;
}

