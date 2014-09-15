/*
  Nome : Trabalho AAi EDI
  Autores: Renato Fialho e Thalles Pereira
  Data: 30/06/10 22:51
  Descricao: Trabalho Auto Instrucional de Estrutura de Dados I
*/

// INCLUSÃO DE BIBLIOTECAS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define TRUE 0

typedef struct Figurinha {
	int quantidade;
	struct Figurinha *prox;
};
// PROTÓTIPO DAS FUNCOES

void criaalbum ();
void adicionafigurinha ();
void removefigurinha ();
void trocafigurinha ();

//  INT MAIN ()
int main () {
	char escolha;

// LIMPA A TELA E FAZ O MENU
    system ("cls");
    printf ("\t\tDigite o que voce deseja fazer:\n\n");
    printf ("\t1 - Criar Album\n");
    printf ("\t2 - Adicionar Figurinhas\n");
    printf ("\t3 - Remover Figurinhas\n");
    printf ("\t4 - Trocar Figurinhas\n");
    printf ("\t5 - Sair do Programa\n");
    escolha = getch();

// SWITCH NA VARIAVEL ESCOLHA PARA FAZER OS CASES
    switch (escolha) {

           // CASO 1 :  CRIA O ALBUM NA FUNCAO CRIAALBUM()
           case '1' : {
                criaalbum();
                break;
                }

                // CASO 2 : ADICIONA FIGURINHAS AO ALBUM
                case '2': {
                     adicionafigurinha();
                     break; }

                     // CASO 3 : REMOVE FIGURINHAS DO ALBUM
                     case '3': {
                          //removefigurinha();
                          break; }

                          // CASO 4 : VAR
                          RE 2 ARQUIVOS E PROCURA POSSIVEIS TROCAS ENTRE OS ALBUNS
                          case '4': {
                               //trocafigurinha();
                               break; }

                               // CASO 5 : SAI DO PROGRAMA E RETORNA 0 PARA A FUNCAO
                               case '5': {
                                  system ("pause");
                                         return 0;

                                // CASO NAO ESTEJA ENTRE 1 E 5, APARECE ERRO!
                                 default : {
                                      printf ("Erro!");
                                      getch();
                                      main();
                                      break;
                                      }
                                 }
                                 }


}

// FUNCAO DE CRIAR ALBUM

void criaalbum () {
     char escolha , nomedoalbum [128], nomedono[128], endereco[128], telefone[128], data[20];
     FILE *album;
     FILE *albuns;
     int i;


                 // DIGITE O NOME DO DONO
                 printf ("Digite o nome do dono do album\t");
                 fgets (nomedono,128,stdin);

                 // DIGITE O ENDERECO DO DONO
                 printf ("Digite o endereco do dono do album\t");
                 fgets (endereco,128,stdin);

                 // DIGITE O TELEFONE DO DONO
                 printf ("Digite o telefone do dono do album\t");
                 fgets (telefone,128,stdin);

                 // DIGITE A DATA DE NASCIMENTO DO DONO
                 printf ("Digite a data de criacao do album\t");
                 fgets (data,20,stdin);

                 // ABRE O ARQUIVO ALBUNS.TXT PARA APPEND
                 albuns = fopen("albuns.txt", "a+");

                 //CONCATENA, RETIRA O /N E CRIA A DONODOALBUM
                 nomedono[strlen(nomedono)-1] = '\0';
                 sprintf (nomedoalbum,"%s.txt", nomedono);

                 // ABRE UM NOVO ARQUIVO COM O NOME DO DONO.TXT
                 album = fopen (nomedoalbum , "w");

                 // CRIA UM INDICE NO ALBUNS.TXT
                 fprintf (albuns, "%s\n", &nomedoalbum);

                 // GRAVA NO NOME DO DONO.TXT O CABECALHO
                 fprintf (album, "\t Nome do dono: %s \n\n \t Endereco do dono: %s \n \t Telefone do dono: %s \n \t Data de nascimento do dono: %s \n", nomedono, endereco, telefone, data);

                 // GERA O INDICE DE FIGURINHAS
                 fprintf (album, "\n\n\n000,0\n00,0\n");
                 for (i = 1; i < 639;i++) {
                 fprintf (album,"%d,0\n",i);
                 }

                 // FECHA OS ARQUIVOS
                 fclose(albuns);
                 fclose (album);

                 main();
     }


// FUNCAO DE ADICIONAR FIGURINHAS

void adicionafigurinha() {
     char numerofigurinha[10], numerodefigurinhas[10], nomedoalbum[128], teste[200];
     int auxiliar;
     FILE *album;

     // DIGITE O NOME DO DONO DO ALBUM PARA FAZER UMA REFERENCIA NO ARQUIVO
     printf ("Digite o nome do dono do album que voce quer adicionar:\t");
     fgets (nomedoalbum,10,stdin);

     // DIGITE O NÚMERO DA FIGURINHA
     printf ("Digite o número da figurinha que você quer adicionar:\t");
     fgets (numerofigurinha,10,stdin);

     // DIGITE QUANTAS FIGURINHAS
     printf ("Digite o número de figurinhas que você quer adicionar:\t");
     fgets (numerodefigurinhas,10,stdin);

     //JUNTA PARA ACHAR O NOME DO ALBUM
     nomedoalbum[strlen(nomedoalbum)-1] = '\0';
     sprintf (nomedoalbum,"%s.txt", nomedoalbum);
     album = fopen(nomedoalbum,"r+");

     // TRANSFORMA O NUMERO DA FIGURINHA EM INT
     auxiliar = atoi(numerofigurinha);

     // PROCURA NO ARQUIVO A FIGURINHA
     fseek(album,auxiliar-10,2);

     // MUDA OS DADOS NO ARQUIVO
     fprintf (album,"%d,%s", auxiliar,numerodefigurinhas);

     // FECHA O ARQUIVO
     fclose (album);

     main();
     }


