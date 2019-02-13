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

#include <iostream>
#include <string>
#include "TLista.h"
using namespace std;


// ● Adicionar um prato com todos os seus ingredientes.
void adicionarPrato(TLista* cardapio, TItem prato, TLista* ingred){

	TLista_Insere(cardapio, prato);
	cardapio->pUltimo->ingredientes = ingred;

}

// ● Apagar um prato com todos os seus ingredientes
void apagarPrato(TLista* pLista, TCelula* pPrato){
	TCelula *x = new TCelula[sizeof(TCelula)];
	x = pLista->pPrimeiro;

	while(x->pProx->item.codigo != pPrato->item.codigo){
		x = x->pProx;
	}

	x->pProx = pPrato->pProx;

	delete[] pPrato->ingredientes;
	delete[] pPrato;

}

//busca um prato ou ingrediente e armazena a celula no *pX
bool buscaItem(TLista *pLista, string pNome, int pCodigo, TCelula* *pX){
	TCelula *x = pLista->pPrimeiro;

	while(x->pProx != NULL){
		if((x->item.codigo == pCodigo) || (x->item.nome == pNome)){
			*pX = x;
			return true;
		}
		x = x->pProx;
	}

	if((x->item.codigo == pCodigo) || (x->item.nome == pNome)){
		*pX = x;
		return true;
	}
	
	return false;
}

//imprimir a sua lista de ingredientes.
void imprimePrato(TCelula* a){

	cout << "[" << a->item.codigo << "] " << a->item.nome << ": " << endl;

	a = a->ingredientes->pPrimeiro;

	while(a->pProx != NULL){
		cout << "    [" << a->item.codigo << "] " << a->item.nome << endl;
		a = a->pProx;
	}
	cout << "    [" << a->item.codigo << "] " << a->item.nome << endl;

}

//usa o busca item pra achar o prato e deopis chama o imprimePrato
TCelula* buscaEImprimePrato(TLista *pLista, string pNome, int pCodigo){

	TCelula *x = new TCelula[sizeof(TCelula)];

	if(buscaItem(pLista, pNome, pCodigo, &x)){
		cout << endl << "    [" << x->item.codigo << "] " << x->item.nome << endl;
	}else{
		cout << endl << "PRATO NAO ENCONTRADO" << endl;
		return NULL;
	}

	return x;
	
}

// ● Dado o nome ou código de um prato, adicionar um ingrediente.
void adicionarIngrediente(TLista* pCardapio, TItem ingred, string nomePrato, int codPrato){
	TCelula *pX = new TCelula[sizeof(TCelula)];

	buscaItem(pCardapio, nomePrato, codPrato, &pX);

	TLista_Insere(pX->ingredientes, ingred);

}

// ● Dado o nome ou código de um prato, eliminar qualquer ingrediente mediante seu codigo ou nome (primeiro terá que ser feita a validação para saber se o ingrediente existe).
void apagarIngrediente(TLista* pLista, TCelula* ingred){
	TCelula *x = new TCelula[sizeof(TCelula)];
	x = pLista->pPrimeiro;

	while(x->pProx != ingred){
		x = x->pProx;
	}

	x->pProx = ingred->pProx;

	delete[] ingred;
}

//imprime a lista completa de pratos e ingredientes
void imprimeCardapio(TLista* pLista){

	TCelula *x = pLista->pPrimeiro;

	cout << endl << "\t\tCARDAPIO: " << endl;

	while(x->pProx != NULL){
		imprimePrato(x);
		x = x->pProx;
	}

	imprimePrato(x);

}