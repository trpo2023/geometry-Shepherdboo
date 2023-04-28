#pragma once

#include <parser.h>

#define CIRCLE_START 6
#define TRIANGLE_START 8

void addSpaecs(int);
void skipSpaces(char *, Figure *, int *);
void fillErrorString(char *, int, char *);
double getValue(char *, int *, Figure *, char, char *);
int circleHandler(char *, Figure *, char *);
int trianglehandler(char *, Figure *, char *);
int stringHandler(char*, Figure *, char *);
