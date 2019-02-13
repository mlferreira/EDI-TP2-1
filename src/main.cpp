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
#include "Cardapio.h"
using namespace std;


void menu(int m);
void subMenu(int m, TCelula* pPrato);


TLista *Cardapio;
string strAux;
int intAux;
char charAux;
TLista *lAux;
TCelula *cAux = new TCelula[sizeof(TCelula)];
TItem *iAux = new TItem[sizeof(TItem)];


int main(){
	int m=0;
	Cardapio = TLista_Inicia();

	while(m!=9){
		cout << endl <<
			"\t1- Adicionar novo prato" << endl << 
			"\t2- Buscar prato" << endl << 
			"\t3- Imprimir cardapio" << endl <<
			"\t9- SAIR" << endl << endl << 
			"Digite a opcao desejada: ";
		cin >> m;

		menu(m);

	}




	return 0;
}

void menu(int m){

	switch (m){

		case 1:
			charAux = 'S';
			lAux = TLista_Inicia();

			while((charAux != 'N') && (charAux != 'n')){
				cout << "Digite o codigo do ingrediente: "; 
					cin >> intAux; iAux->codigo = intAux;
				cout << "Digite o nome do ingrediente: "; 
					getline(cin, strAux); getline(cin, strAux); iAux->nome = strAux;

				TLista_Insere(lAux, *iAux);

				cout << "Adicionar outro ingrediente (S/N)? "; cin >> charAux;
			}

			cout << "Digite o codigo do prato: "; 
				cin >> intAux; iAux->codigo = intAux;
			cout << "Digite o nome do prato: "; 
				getline(cin, strAux); getline(cin, strAux); iAux->nome = strAux;

			adicionarPrato(Cardapio, *iAux, lAux);
			break;

		case 2:
			cout << endl <<
				"\t1- Busca por nome" << endl << 
				"\t2- Buscar por codigo" << endl << 
				"\t0- VOLTAR" << endl << endl << 
				"Digite a opcao desejada: ";
			cin >> m;

			switch(m){
				case 1:
					cout << "Digite o nome do Prato: ";
					getline(cin, strAux); getline(cin, strAux);
					cAux = buscaEImprimePrato(Cardapio, strAux, 0);
					if(cAux != NULL)
						subMenu(m, cAux);
					break;
				case 2:
					cout << "Digite o codigo do Prato: ";
					cin >> intAux;
					strAux.clear();
					cAux = buscaEImprimePrato(Cardapio, strAux, intAux);
					if(cAux != NULL)
						subMenu(m, cAux);
					break;
			}

			break;

		case 3:
			imprimeCardapio(Cardapio);
			break;
		
	}


}

void subMenu(int m, TCelula* pPrato){

	while(m!=0){
		cout << endl << 
			"\t1- Imprimir lista de ingredientes" << endl << 
			"\t2- Adicionar novo ingrediente" << endl << 
			"\t3- Remover ingrediente" << endl << 
			"\t4- Apagar prato" << endl << 
			"\t0- VOLTAR AO MENU PRINCIPAL" << endl << endl << 
			"Digite a opcao desejada: ";
		cin >> m;

		switch (m){

			case 1:
				imprimePrato(pPrato);
				break;

			case 2:
				cout << "Digite o codigo do ingrediente: "; 
					cin >> intAux; iAux->codigo = intAux;
				cout << "Digite o nome do ingrediente: "; 
					getline(cin, strAux); getline(cin, strAux); iAux->nome = strAux;

				TLista_Insere(pPrato->ingredientes, *iAux);
				break;

			case 3:
				cout << endl <<
					"\t1- Busca por nome" << endl << 
					"\t2- Buscar por codigo" << endl << 
					"\t0- VOLTAR" << endl << endl << 
					"Digite a opcao desejada: ";
				cin >> m;

				switch(m){
					case 1:
						cout << "Digite o nome do ingrediente: ";
							getline(cin, strAux); getline(cin, strAux); 
						if(buscaItem(pPrato->ingredientes, strAux, 0, &cAux)){
							apagarIngrediente(pPrato->ingredientes, cAux);
						}
						else{cout << "Ingrediente nao encontrado!" << endl;}
						break;

					case 2:
						cout << "Digite o codigo do ingrediente: ";
							cin >> intAux; strAux.clear();
						if(buscaItem(pPrato->ingredientes, strAux, intAux, &cAux)){
							apagarIngrediente(pPrato->ingredientes, cAux);
						}
						else{cout << "Ingrediente nao encontrado!" << endl;}
						break;
				}
				break;
			case 4:
				apagarPrato(Cardapio, pPrato);
				menu(0);
				break;

		}

	}


}