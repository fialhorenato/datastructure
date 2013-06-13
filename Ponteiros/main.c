/*
 * main.c
 *
 *  Created on: 01/09/2010
 *      Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>

void soma (int *x, int *y) {
	printf ("%d" , *x + *y);
}

int main(int argc, char **argv) {
int x  = 10, y = 20;

soma (&x,&y);


return 0;

}
