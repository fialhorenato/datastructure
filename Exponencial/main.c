/*
 * main.c
 *
 *  Created on: 23/08/2010
 *      Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int exponencial(int base, int expoente) {

	if (expoente == 0)
		return 1;

	else if (expoente == 1)
		return base;

	else if (expoente > 1)
		return base * exponencial(base, expoente - 1);

}


int main(void) {
	int a = 2, b = 3;
	fflush(stdin);
	printf("Resultado: %d", exponencial(a, b));
	return EXIT_SUCCESS;
}
