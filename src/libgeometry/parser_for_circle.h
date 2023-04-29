#ifndef PARSER_FOR_CIRCLE_H
#define PARSER_FOR_CIRCLE_H
#include <stdio.h>
#include <stddef.h>
typedef struct
{
	char *name;
	double y;
	double x;
	double diameter;
	double square;
	double perimeter;

} Circle;

void strlower(char* string);
void getdatacircle(char* string, int countfig, Circle *circle);
int readfile(char* string, Circle *circle, int countfig, const char* patch);
void conclusion(Circle *circle, int countfig);
#endif //PARSER_FOR_CIRCLE_H
