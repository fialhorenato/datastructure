/*
 * Main.c
 *
 *  Created on: 27/10/2010
 *      Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>

struct Lista {
	char dado;
	struct Lista *prox;
	struct Lista *ant;
};

typedef struct Lista TLista;

TLista* inicializa() {
	return NULL;
}

TLista* insere(TLista* lista, char ch) {
	TLista* novo = (TLista *) malloc(sizeof(TLista));
	novo -> dado = ch;

	if (lista == NULL) {
		novo -> prox = inicializa();
		novo -> ant = inicializa();
		printf("INSERINDO OS DADOS:\t");
		printf("DADO : %c \t ENDERECO: %p \t ANTERIOR: %p \t PROXIMO: %p \n",
				novo->dado, novo, novo -> ant, novo -> prox);
	} else {

		novo -> ant = lista;
		novo -> ant -> prox = novo;
		novo -> prox = inicializa();
		printf("INSERINDO OS DADOS:\t");
		printf("DADO : %c \t ENDERECO: %p \t ANTERIOR: %p \t PROXIMO: %p \n",
				novo->dado, novo, novo -> ant, novo -> ant -> prox);
	}

	return novo;

}

void imprime(TLista* lista) {

	TLista* aux;

	aux = lista;

	while (aux != NULL) {
		printf("IMPRESSÃO DE DADOS:\t");
		printf("DADO : %c \t ENDERECO: %p \t ANTERIOR: %p \t PROXIMO: %p \n",
				aux->dado, aux, aux -> ant, aux -> prox);
		aux = aux->ant;
	}

}

void imprime2(TLista* lista) {

	TLista* aux;

	aux = lista;

	while (aux -> ant != NULL) {
		aux = aux->ant;
	}

	while (aux != NULL) {
		printf("IMPRESSÃO DE DADOS:\t");
		printf("DADO : %c \t ENDERECO: %p \t ANTERIOR: %p \t PROXIMO: %p \n",
				aux->dado, aux, aux -> ant, aux -> prox);
		aux = aux -> prox;
	}

}

TLista* remove_meio(TLista *lista, char ch) {
	TLista *aux = lista;

	while (aux != NULL) {
		if (aux -> dado == ch) {
			if (aux -> ant == NULL) {
				aux -> prox -> ant = inicializa();
			} else if (aux -> prox == NULL) {
				aux->ant->prox = inicializa();
			} else {
				aux -> ant -> prox = aux -> prox;
				aux -> prox -> ant = aux -> ant;
			}
			free(aux);
			return lista;
		}
		aux = aux -> ant;
	}
	return aux;

}

int main(int argc, char **argv) {
	TLista *listac = inicializa();
	listac = insere(listac, 'f');
	listac = insere(listac, 'a');
	listac = insere(listac, 'c');
	listac = insere(listac, 'e');
	listac = insere(listac, '-');
	listac = insere(listac, 'f');
	listac = insere(listac, 'u');
	listac = insere(listac, 'm');
	listac = insere(listac, 'e');
	listac = insere(listac, 'c');
	printf("\n");
	imprime(listac);
	printf("\n");
	imprime2(listac);
	listac = remove_meio(listac, 'm');
	printf("\n");
	imprime2(listac);

	listac = remove_meio(listac, 'f');
	printf("\n");
	imprime2(listac);

	listac = remove_meio(listac, 'c');
	printf("\n");
	imprime2(listac);

	listac = remove_meio(listac, 'e');
	printf("\n");
	imprime2(listac);

	listac = remove_meio(listac, 'u');
	printf("\n");
	imprime2(listac);

	listac = remove_meio(listac, '-');
	printf("\n");

	imprime2(listac);

	return EXIT_SUCCESS;
}

