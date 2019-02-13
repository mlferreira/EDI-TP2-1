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
#include "TLista.h"
using namespace std;


TLista* TLista_Inicia(){
    TLista *pLista = new TLista[sizeof(TLista)];

    pLista->pPrimeiro = NULL;
    pLista->pUltimo = NULL;

    return pLista;
}

int TLista_EhVazia(TLista* pLista){
    return (pLista->pPrimeiro == NULL);
}

int TLista_Insere(TLista* pLista , TItem x){
    TCelula *novo = new TCelula[sizeof(TCelula)];
    novo->item = x;
    novo->pProx = NULL;
    if(TLista_EhVazia(pLista)){
        pLista->pPrimeiro = novo;
        pLista->pUltimo = novo;
    }else{
        pLista->pUltimo->pProx = novo;
        pLista->pUltimo = novo;
    }
	return 1;
}

int TLista_RetiraPrimeiro(TLista* pLista, TItem* pX){
    if(TLista_EhVazia(pLista)){
        return 0;
    }
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux->item;
    pLista->pPrimeiro->pProx =  pAux->pProx;
    return 1;
}



