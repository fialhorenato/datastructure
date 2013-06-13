/*
 * mdc.c
 *
 *  Created on: 16/08/2010
 *      Author: 1A213703939
 */
#include <stdio.h>
#include <stdlib.h>

int mdc (int n,int m);


int main (void) {
	int n, m;
	fflush (stdin);
	scanf ("%d",&n);
	fflush (stdin);
	scanf ("%d",&m);
	printf("%d",mdc(n,m));
	return EXIT_SUCCESS;
}

int mdc(int n , int m) {
	if (n % m == 0) {
		return m;
	} else {
	return mdc (m , n % m);
	   }
}
