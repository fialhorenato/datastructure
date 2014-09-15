/*
 * main.c
 *
 *  Created on: 16/08/2010
 *  Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(void) {
	int i;
	fflush(stdin);
	scanf("%d", &i);
	printf("%d", fib(i));
	return EXIT_SUCCESS;

}

int fib(int n) {

	if (n == 1) {
		return 0;
	} else if (n == 2) {
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}
