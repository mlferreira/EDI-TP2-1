# Sistema para Registro de Pratos Gastronômicos

Trabalho prático de Estrutura de Dados I, com o objetivo principal de fundamentar os conceitos de listas encadeadas, filas e pilhas promovendo a utilização correta dos espaços de memória.

## Definição do Problema

Desenvolver um sistema para o registro de pratos gastronômicos e os seus ingredientes, assumindo que o computador onde será implantado este programa não tem tamanho de memória suficiente e, portanto, o sistema deve aproveitar deste recurso da melhor forma. 

Como o número de ingredientes em cada prato é variado, usar uma representação em forma de matriz de tamanho fixo não é viável, pois haveriam espaços de memória não utilizados. 

Tanto o  prato quanto os ingredientes possuem dois campos: código (int) e nome (string).

### Funções

* Adicionar um prato com todos os seus ingredientes.
* Apagar um prato com todos os seus ingredientes
* Dado o nome ou código de um prato, imprimir a sua lista de ingredientes.
* Dado o nome ou código de um prato, adicionar um ingrediente.
* Dado o nome ou código de um prato, eliminar qualquer ingrediente mediante seu
codigo ou nome.
* Dado o nome ou código de um prato, imprimir a sua lista de ingredientes.
* Imprimir a lista completa de pratos e ingredientes

## Instalação e Execução


### Linux

```
make all
```

```
make run
```

### Windows

```
g++ -o tp2ex1 src/main.cpp src/Cardapio.h src/TLista.h src/TLista.cpp
```

```
tp2ex1
```