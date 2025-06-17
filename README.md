# Trabalho Prático 03 - QuickSort Não Recursivo

Este repositório contém a implementação do algoritmo QuickSort de forma não recursiva (iterativa) em linguagem C, utilizando uma estrutura de dados de pilha para gerenciar as partições.
Este repositório contém a implementação do algoritmo QuickSort de forma não recursiva (iterativa) em linguagem C, utilizando uma estrutura de dados de pilha para gerenciar as partições.

## Integrantes do Grupo:
* Fernando Souza De Riggi

## Descrição do Trabalho

O objetivo deste trabalho foi implementar o algoritmo Quick Sort de forma não recursiva, adaptando-o para utilizar uma pilha ao invés da recursão. As declarações da TAD Pilha estão em `stack.h` e suas implementações em `stack.c`.

## Estratégia da Pilha (O(log n) stack size)

Conforme discutido no enunciado do trabalho, a estratégia iterativa do QuickSort oferece uma vantagem ao estabelecer limites para o tamanho da pilha. Em contraste com a abordagem recursiva, que pode inserir duas partições na pilha de execução em ordem arbitrária, a versão iterativa verifica os tamanhos das partições antes de adicioná-las à pilha.

Nossa implementação adotou a política de priorizar a inserção dos índices da partição maior do vetor antes dos índices da partição menor. Ao fazer isso, o lado menor é processado antes do lado maior, resultando em um tamanho da pilha da ordem de $O(\log n)$. Isso é crucial para evitar estouros de pilha em casos de pior cenário com grandes conjuntos de dados, uma limitação comum da versão recursiva.

## Como Compilar e Executar

Para compilar o projeto, navegue até o diretório raiz onde estão os arquivos e execute o comando `make`:

```bash
make
```
Isso criará um executável chamado quicksort_iterativo.

Para executar o programa, utilize o seguinte comando:
```
./quicksort_iterativo
```
O programa aguardará a entrada de dados via terminal. Você deve:

    Informar o número de elementos a serem ordenados.

    Informar os elementos inteiros separados por espaço ou por linha.

Exemplo:
Entrada:
```
5
7 2 9 1 5
```
Saída esperada:
```
1 2 5 7 9
``

    O programa realiza a ordenação in-place utilizando a versão iterativa do QuickSort com o auxílio de uma pilha para controle das partições.
