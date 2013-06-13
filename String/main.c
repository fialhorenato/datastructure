/*
 * main.c
 *
 *  Created on: 23/08/2010
 *      Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int palin(char str[], int tam) {

return (tam == 1 || str[0] == str[tam-1]) && palin(str+1,tam-2);

}

int main(void) {
	char str[100] = "arara";

	if (palin(str, strlen(str)) == 1)
		printf("Eh um palindrome!");
	else
		printf("Nao eh um palindrome!");

	return 0;
}
