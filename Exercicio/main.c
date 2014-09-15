/*
 * main.c
 *
 *  Created on: 13/09/2010
 *      Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrLen (char *str) {
	int cont = 0;
	while (*str) {
		str++;
		cont++;
	}
	return cont;
}

void StrCpy(char *destino, char *origem) {
	while (*origem) {
		*destino = *origem;
		destino++;
		origem++;
	}
	*destino = '\0';

}

void StrCat(char *destino, char *origem) {
	while (*destino) {
		destino++;
	}
	while (*origem) {
		*destino = *origem;
		origem++;
		destino++;
	}
	*destino = '\0';

}

int StrCmp (char *str1, char *str2) {

	while (*str1 == *str2) {
		str1++;
		str2++;
	}
    printf ("%c",*str1);
    printf ("%c",*str2);
	if (*str1 == *str2) { return 1; } else {return 0;}


}

int strend (char *dest, char *origem) {
	int cont;
	while (*dest) {
		dest++;
	}

	cont = StrLen(origem);

	while (cont > 0) {
		cont--;
		dest--;
	}

	while (*origem == *dest) {
		origem++;
		dest++;

		if (*origem != *dest) { return 0; }
	}
	return 1;
}


int main(int argc, char **argv) {
char str[100] = "FACE";
char stra[100] = "FACE";
char str2[100] = "/FUMEC";
char strb[100] = "ABACAXI";
char strc[100] = "AXI";

printf("Strlen do sistema = %d\n", strlen(str));
printf("Strlen pessoal = %d\n", StrLen(str));

//strcpy (str,str2);
//printf ("Teste strcopy = %s\n", str);
//StrCpy (str,str2);
//printf ("Teste strcopy = %s\n", str);
//StrCat (str,str2);
//printf ("Teste strCat = %s\n", str);


printf("Teste Cmp = %d\n", StrCmp(str,stra));
printf("Teste end = %d\n", strend(strb,strc));




return EXIT_SUCCESS;
}
