#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct Circle
{
	char *name;
	double y;
	double x;
	double diameter;
	double square;
	double perimeter;

};
int ERRORS(int errorcode)
{
	switch(errorcode)
	{
		case 1:
			printf("Не удалось открыть файл\n");
			return -1;
		case 2:
			printf("Не удалось записать файл\n");
			return -1;
		case 3:
			printf("Неправильное название фигуры\n");
			break;
		case 4:
			printf("Нет открывающей скобки\n");
			break;
		case 5:
			printf("Закрывающей скобки нет или она расположена не в том месте\n");
			break;
		case 6:
			printf("Нет запятой\n");
			break;
		default:
			printf("Неверный код ошибки\n");
	}
	return 0;
}
void strlower(char* string)
{
	for(int i = 0; i<strlen(string); i++)
	{
		string[i] = tolower(string[i]);
	}

}
void getdatacircle(char* string, int countfig, struct Circle *circle)
{
	if(string[0] == 'c' || string[0] == 't')
	{
		if(string[0] == 'c' && string[1] == 'i' && string[2] == 'r' && string[3] == 'c' && string[4] == 'l' && string[5] == 'e')
		{
			circle[1].name = "circle";
		}
		else
		{
			int errorcode = 3;
			ERRORS(errorcode);
		}

	}

int point = 6;
int point_for_save = 0;
char save[0];
while (string[point] == ' ')
{
	point++;
}
while (string[point] != ' ')
{
	if(string[point] == '(')
	{
		point++;
	}
	else
	{
		int errorcode = 4;
		ERRORS(errorcode);
	}
	save[point_for_save] = string[point];
	point_for_save++;
	point++;
}
circle[countfig].x = atof(save);
while(string[point] == ' ')
{
	point++;
}
if(string[point] == ',')
{
	int errorcode = 6;
	ERRORS(errorcode);
}
point_for_save = 0;
char savex[point_for_save];
while(string[point] != ' ')
{
	if(string[point]==',')
	{
		break;
	}
	savex[point_for_save] = string[point];
	point_for_save++;
	point++;
}
circle[countfig].y = atof(savex);
while(string[point] == ' ')
{
	point++;
}
if(string[point] == ',')
{
	point++;
}
else
{
	int errorcode = 6;
	ERRORS(errorcode);
}
while(string[point] == ' ')
{
	point++;
}
point_for_save = 0;
char savediam[point_for_save];
while((string[point] != ' ')&&(string[point]!=')')&&string[point]!='\000')
{
	savediam[point_for_save] = string[point];
	point_for_save++;
	point++;
}
if(string[point] != ')')
{
	int errorcode = 5;
	ERRORS(errorcode);
}
circle[countfig].diameter = atof(savediam);
circle[countfig].square = (3.14*(circle[countfig].diameter/2)*(circle[countfig].diameter/2));
circle[countfig].perimeter = (2*3.14*(circle[countfig].diameter/2));
}
int readfile(char* string, struct Circle *circle, int countfig)
{
	FILE* file = fopen("fig.txt", "r");
	if(file == NULL)
	{
		int errorcode = 1;
		ERRORS(errorcode);
	}
	string = malloc(1000000);
	if(string == NULL)
	{
		int errorcode = 2;
		ERRORS(errorcode);
	}
	while(fgets(string, sizeof(string)*sizeof(char)+500, file)!=NULL)
	{
		strlower(string);
		printf("%s", string);
		getdatacircle(string, countfig, circle);
		countfig++;
	}
	fclose(file);
	return countfig;
}
void conclusion(struct Circle *circle, int countfig)
{
	for(int i = 0; i<countfig; i++)
	{
		printf("\n\nCircle %d:\n", i+1);
		printf("Point: x - %f, y - %f\n", circle[i].x, circle[i].y);
		printf("Diameter: %f\n", circle[i].diameter);
		printf("Square: %f\n", circle[i].square);
		printf("Perimeter: %f\n", circle[i].perimeter);
	}
}
int main()
{
	char* string = NULL;
	struct Circle circle[50];
	int countfig = 0;
	countfig = readfile(string, circle, countfig);
	conclusion(circle, countfig);
	return 0;
}
