/*
 ============================================================================
 Name        : Polinomio.c
 Author      : Renato
 Version     : 1.0
 Copyright   : AAi ED2 2010
 Description : AAi ED2 2010
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Polinomio Polinomio;

struct Polinomio {
	int exp;
	int coef;
	Polinomio *prox;
};

Polinomio* inicializa();
Polinomio* insere(Polinomio *lista, int coef, int exp);
void ordena(Polinomio *lista);
void imprime(Polinomio *imprime);

int main(void) {
	Polinomio *lista;
	lista = inicializa();
	lista = insere(lista, 1,2);
	lista = insere(lista, 3,4);
	lista = insere(lista, 5,6);
	lista = insere(lista, 7,8);
	lista = insere(lista, 9,1);
	lista = insere(lista, 2,3);
	lista = insere(lista, 4,5);
	imprime(lista);
	return EXIT_SUCCESS;
}

Polinomio* inicializa() {
	return NULL;
}

Polinomio* insere(Polinomio *lista, int coef, int exp) {
	Polinomio *aux = (Polinomio *) malloc(sizeof(Polinomio));
	Polinomio *novo = lista;

	if (lista == NULL) {
		aux -> prox = aux;
	} else {
		while (novo -> prox != lista) {
			novo = novo -> prox;
		}
		novo -> prox = aux;
		aux -> prox = lista;
	}

	aux -> coef = coef;
	aux -> exp = exp;
	return aux;
}

void imprime(Polinomio *lista) {
	Polinomio *aux = lista;
	do {
		printf("%dx^%d + ", aux -> coef , aux -> exp);
		aux = aux -> prox;
	} while (aux != lista);
}


