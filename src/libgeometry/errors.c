#include "errors.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

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
