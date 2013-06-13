/*
 * Main.c
 *
 *  Created on: 23/10/2010
 *      Author: Renato
 */

#include <stdlib.h>
#include <stdio.h>

struct Lista {
	char dado;
	struct Lista *prox;
};

typedef struct Lista TLista;

// ===============================================================

TLista* inicializa() {
	return NULL;
}

// ===============================================================

TLista* insere(TLista *lista, char ch) {
	TLista* novo = (TLista *) malloc(sizeof(TLista));
	TLista *aux = lista;

	if (lista == NULL)
		novo -> prox = novo;
	else {
		while (aux -> prox != lista) {
			aux = aux -> prox;
		}
		aux -> prox = novo;
		novo -> prox = lista;
	}
	novo -> dado = ch;
	return novo;
}

// ===============================================================

void imprime(TLista *lista) {
	TLista *aux = lista;

	if (lista == NULL) {

	} else {
		do {
			printf("--> %c ---> %p\n", aux -> dado, aux);
			aux = aux -> prox;
		} while (aux != lista);
	}

}

// ===============================================================

void imprimeRec(TLista *lista, TLista *ref) {

	if (lista -> prox != ref) {
		printf("--> %c ---> %p\n", lista -> dado, lista);
		imprimeRec(lista -> prox, ref);
	} else {
		printf("--> %c ---> %p\n", lista -> dado, lista);
	}
}

// ===============================================================

TLista* busca(TLista *lista, char ch) {
	TLista *ref = lista;
	do {
		if (ref -> dado == ch) {
			return ref;
		}
		ref = ref -> prox;
	} while (ref != lista);

	return lista;
}

// ===============================================================


TLista* remove(TLista *lista, char ch) {
	TLista *ref = lista;
	do {
		if (ref -> dado == ch) {
			free(ref);

		}
		ref = ref -> prox;
	} while (ref != lista);

	return ref;
}

// ===============================================================
TLista* busca_rec(TLista *lista, char ch, TLista *ref) {
	if (lista -> prox != ref) {
		if (lista -> dado == ch) {
			return lista;
		}
		return busca_rec(lista->prox, ch, ref);
	} else {
		return lista;
	}

}

// ===============================================================

TLista *libera(TLista *lista) {
	TLista *aux = lista;
	TLista *ref = lista;
	do {
		aux = lista -> prox;
		free(lista);
		lista = aux;
	} while (lista != ref);

	return NULL;
}
// ===============================================================

int listavazia(TLista *lista) {
	return lista == NULL;
}

// ===============================================================

int main(int argc, char **argv) {
	TLista* listac;
	listac = inicializa();
	listac = insere(listac, 'f');
	listac = insere(listac, 'u');
	listac = insere(listac, 'm');
	listac = insere(listac, 'e');
	listac = insere(listac, 'c');
	imprime(listac);
	printf("\n");
	imprimeRec(listac, listac);
	printf("%c -- %p\n", busca(listac, 'u') -> dado, busca(listac, 'u'));
	printf("%c -- %p\n", busca_rec(listac, 'u', listac) -> dado, busca_rec(
			listac, 'u', listac));
	printf("%d\n", listavazia(listac));
	//listac = libera(listac);
	imprimeRec(listac, listac);
	printf("%d\n", listavazia(listac));
	return EXIT_SUCCESS;
}
