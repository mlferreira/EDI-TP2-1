/**********************************************************************/
/*                                                                    */
/*                        Estrutura de Dados I                        */
/*                         Trabalho Pratico 2                         */
/*                                                                    */
/*                             Exercicio 1                            */
/*                                                                    */
/*                        Melina Lopes Ferreira                       */
/*                              15.2.4002                             */
/*                                                                    */
/**********************************************************************/

#ifndef TLista_h
#define TLista_h

#include <iostream>
#include <string>
using namespace std;


typedef struct{
	int codigo;
	string nome;
}TItem;

typedef struct celula{
	struct celula *pProx;
	TItem item;
	struct lista *ingredientes;
}TCelula;

typedef struct lista{
	TCelula *pPrimeiro;
	TCelula *pUltimo;
}TLista;




TLista* TLista_Inicia();

int TLista_EhVazia(TLista* pLista);

int TLista_Insere(TLista* pLista, TItem x);

int TLista_RetiraPrimeiro(TLista* pLista, TItem* pX);


#endif /* TLista_h */
