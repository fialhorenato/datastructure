/*
 * Main.c
 *
 *  Created on: 22/09/2010
 *  Author: 1A213703939
 */

#include <stdio.h>
#include <stdlib.h>

struct lista {
	char dado;
	struct lista *prox;
};

typedef struct lista TLista;

TLista* inicializa() {
	return NULL;
}

TLista* insere(TLista* lista, char ch) {

	TLista *novo; //Cria o ponteiro

	//Aloca a area
	novo = (TLista *) malloc(sizeof(TLista));
	novo->dado = ch; //grava o dado
	novo->prox = lista; //vincula o novo dado ao restante

	return novo; //devolve a nova lista com o novo e o restante
}

void imprime(TLista* lista) {

	TLista* aux;

	aux = lista;

	while (aux != NULL) {
		printf("--> %c\n", aux->dado);
		aux = aux->prox;
	}

}

void imprimeRec(TLista* lista) {

	if (lista != NULL) {
		imprimeRec(lista->prox);
		printf("--> %c\n", lista->dado);
	}

}

int listavazia(TLista *lista) {
	if (lista != NULL)
		return 0;
	else
		return 1;
}

TLista* busca(TLista* lista, char ch) {

	if (lista -> dado == ch)
		return lista;
	else
		busca(lista -> prox, ch);

}


TLista* libera_rec(TLista* lista) {
	TLista* aux = lista;
	if (aux != NULL) {
		lista = lista -> prox;
		free(aux);
		aux = lista;
		return libera_rec(aux);
	}
	return aux;

}

/* TLista* libera_rec_v2(TLista* lista) {
	TLista* aux = lista;
	if (!listavazia(aux)) {
		return libera_rec_v2(lista -> prox);
		free(aux);
	}
	return aux;

} */

TLista* remove_meio(TLista* lista, char ch) {
	TLista* aux = lista;
	TLista* aux2;
	if (aux -> dado == ch) {
		lista = lista -> prox;
		free(aux);
	}

	while (aux -> prox != NULL) {
		if (aux -> prox -> dado == ch) {
			aux2 = aux -> prox;
			aux -> prox = aux -> prox -> prox;
			free(aux2);
		} else {
			aux = aux -> prox;
		}

	}

	return lista;
}

TLista* remove_meio_rec(TLista* lista, char ch) {
	TLista* aux;
	if (lista != NULL) {
		if (lista-> dado != ch) {
			lista -> prox = remove_meio_rec(lista -> prox, ch);
		} else {
			aux = lista;
			lista = lista-> prox;
			free(aux);
		}
	}
	return lista;
}

TLista* libera(TLista* lista) {
	TLista* aux = lista;

	while (lista != NULL) {
		lista = lista -> prox;
		free(aux);
		aux = lista;
	}
	return aux;
}

TLista* remove_ini(TLista* lista) {
	TLista* aux = lista;
	if (!listavazia(aux)) {
		lista = lista->prox;
		free(aux);
	}
	return lista;
}

int main(void) {
	// CRIA A VARIÁVEL LISTA
	TLista *listax;

	//INICIALIZA A LISTA COM UM PONTEIRO EM NULL
	listax = inicializa();

	//INSERE OS DADOS NA LISTA
	listax = insere(listax, 'f');
	listax = insere(listax, 'u');
	listax = insere(listax, 'm');
	listax = insere(listax, 'm');
	listax = insere(listax, 'e');
	listax = insere(listax, 'm');
	listax = insere(listax, 'm');
	listax = insere(listax, 'm');
	listax = insere(listax, 'm');
	listax = insere(listax, 'c');

	// IMPRIME A LISTA RECURSIVAMENTE
	imprimeRec(listax);

	// SE A LISTA ESTIVER VAZIA, IMPRIME 1, SENÃO IMPRIME 0
	printf("\n--> %d\n\n", listavazia(listax));

	listax = remove_meio_rec(listax, 'm');

	// IMPRIME A LISTA RECURSIVAMENTE
	imprimeRec(listax);

	// LIBERA TODA A LISTA RECURSIVAMENTE
	listax = libera_rec(listax);

	// SE A LISTA ESTIVER VAZIA, IMPRIME 1, SENÃO IMPRIME 0
	printf("\n-->%d\n", listavazia(listax));



	return EXIT_SUCCESS;
}

