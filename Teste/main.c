/*
 * main.c
 *
 *  Created on: 20/09/2010
 *      Author: 1A213703939
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char str[], int tam) {

	char aux;

	if (tam > 1) {
		aux = str[0];
		str[0] = str[tam - 1];
		str[tam - 1] = aux;
		inverte(str + 1, tam - 2);
	}
}

int convBin(int x) {
	if (x < 2)
		return x;
	else if (x%2 == 0)
		return convBin(x/2)*10;
	else
		return convBin(x/2)*10+1;

}

int main(int argc, char **argv) {
	char str[999] = "b........................a";
	//char str[999] = "atecubanos";
	printf("%s\n", str);
	inverte(str, strlen(str));
	printf("%s\n", str);

	printf("Conversao binaria --> %d -- %d\n", 1000, convBin(1000));
	return EXIT_SUCCESS;
}

