/*
 * ListaCircular.c
 *
 *  Created on: 20/10/2010
 *      Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>

struct Lista {
	char dado;
	struct Lista *prox;
};

typedef struct Lista TLista;

TLista* insere(TLista* lista, char ch) {
	TLista* novo = (TLista *) malloc(sizeof(TLista));
	novo->dado = ch;
	novo->prox = lista;
	return novo;
}

int vazia(TLista *lista) {
	if (lista != NULL)
		return 0;
	else
		return 1;
}

int main(int argc, char **argv) {
	return EXIT_SUCCESS;
}

