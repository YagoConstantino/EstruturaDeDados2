#ifndef _LISTA_H
#define _LISTA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int data;
    struct elem *next;
    struct elem *prev;

}Elem;

typedef struct lista
{
    Elem *head;
    Elem *tail;
    int size;

}Lista;

//Basico
Lista* createLista();
void destroyLista(Lista *l);
void insertFront(int dat,Lista *l);
void insertBack(int dat,Lista *l);
void removeFront(Lista *l);
void removeback(Lista *l);
void printLista(Lista *l);
int getSizeLista(Lista *l);

//*Utils*/
int sum(Lista *l);
int in(Lista*l,int k);
int position(Lista*l,int k);
Lista* merge(Lista *A,Lista *B);
int maxValue(Lista *l);
int minValue(Lista*l);
int similar(Lista*A,Lista*B);
Lista* copy(Lista* l);
Lista* unite(Lista *A, Lista *B);
void revertList(Lista *l);
void printReverse(Lista *l);

void printArray(int* V,int n);

//Avançados
/*
 * Remover todas as ocorrências
    Escreva void removeAll(Lista *l, int k) que elimine todos os nós cujo data == k de uma lista, ajustando ponteiros e size.
*/
void removeAll(Lista *l, int k);

/*
*Buscar e substituir
Implemente void replace(Lista *l, int old, int new) que percorra l e troque cada ocorrência de old por new. 
*/
void replace(Lista *l, int old, int new);

/*
 * Extrair sublista
Crie Lista* subList(Lista *l, int start, int count) que retorne uma nova lista com count elementos 
começando da posição start (0‑based). Trate indices inválidos (negativos, fora do alcance).
 */
Lista* subList(Lista *l, int start, int count);

/*
*Intercalar duas listas
Lista* weave(Lista *A, Lista *B) que combine elementos alternados: primeiro um de A, 
depois um de B, e assim por diante. Se uma acabar antes, anexa o restante da outra.
*/
Lista* weave(Lista *A, Lista *B);

/**
 * Conversão para vetor
int* toArray(Lista *l) retorna um array de inteiros (alocado dinamicamente) com todos os valores em ordem, 
e Lista* fromArray(int *v, int n) faz o inverso.
*/
int* toArray(Lista *l);

/**
 * Conversão para vetor
int* toArray(Lista *l) retorna um array de inteiros (alocado dinamicamente) com todos os valores em ordem, 
e Lista* fromArray(int *v, int n) faz o inverso.
*/
Lista* fromArray(int *v, int n);


#endif