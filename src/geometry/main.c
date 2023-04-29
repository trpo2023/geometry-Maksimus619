#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <parser_for_circle.h>
#include <errors.h>

int main(int argc, char *argv[])
{
	const char *patch = argv[1]; 
	char* string = NULL;
	Circle circle[50];
	int countfig = 0;
	countfig = readfile(string, circle, countfig, patch);
	conclusion(circle, countfig);
	return 0;
}
