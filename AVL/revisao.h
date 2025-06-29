#ifndef _REVISAO_H
#define _REVISAO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
   int info;
   int altura;
   struct node* esq;
   struct node* dir;
} No, Arvore;

/// @brief Função para retornar o maior entre dois inteiros, a e b
/// @param a Primeiro inteiro a ser comparado
/// @param b Segundo inteiro a ser comparado
/// @return  O maior entre os inteiros a e b
int maiorRev (int a, int b);

/// @brief Função que recebe uma Arvore AVL como parâmetro e retorna a altura dela 
/// @param a Arvore passada por parâmetro
/// @return Retorna um inteiro referente a altura da arvore recebida 
int alturaRev (Arvore* a);

/// @brief Função para atualizar a altura do nó baseado na maior altura entre suas sub-árvores
/// @param a Arvore que terá a altura atualizada
/// @return um Inteiro com o novo valor da altura
int atualizar_alturaRev (Arvore *a);

/// @brief Calcula o balanceamento da raiz com base na sub-árvore a esquerda e a direita
/// @param a  Árvore que será verificada
/// @return um Inteiro com o valor do balanceamento, será negativo se o desbalanço está á esquerda e positivo caso seja á direita
int balanceamentoRev (Arvore *a);

/// @brief Função para fazer uma rotação simples á esquerda, idealmente usada caso o balanceamento seja 2 e sua sub-árvore tenha o mesmo sinal
/// @param a Raiz que será rotacionada
/// @return Ponteiro para a nova raiz após a rotação
Arvore* rotacao_simples_esqRev (Arvore* a);

/// @brief Função para fazer uma rotação simples á direita, idealmente usada caso o balanceamento seja -2 e sua sub-árvore tenha o mesmo sinal
/// @param a Raiz que será rotacionada
/// @return Ponteiro para a nova raiz após a rotação
Arvore* rotacao_simples_dirRev (Arvore* a);


/// @brief Função para fazer uma rotação dupla á esquerda, idealmente usada caso o balanceamento seja 2 e sua sub-árvore tenha o sinal diferente
/// Nesse caso fará uma rotação simpes á direita na subárvore e depois uma rotação simples a esquerda na raiz
/// @param a Raiz que será rotacionada
/// @return Ponteiro para a nova raiz após a rotação
Arvore* rotacao_dupla_esqRev (Arvore* a);

/// @brief Função para fazer uma rotação dupla á direita, idealmente usada caso o balanceamento seja -2 e sua sub-árvore tenha o sinal diferente
/// Nesse caso fará uma rotação simpes á esquerda na subárvore e depois uma rotação simples á direita na raiz
/// @param a Raiz que será rotacionada
/// @return Ponteiro para a nova raiz após a rotação
Arvore* rotacao_dupla_dirRev (Arvore* a);


/// @brief Função que verifica se a Raiz a precisa de alguma rotação na sub-árvore a Direita (simples ou dupla) e a executa caso necessário
/// @param a Raiz que será verificada e possivelmente rotacionada
/// @return ponteiro para a Raiz modificada
Arvore* atualizar_fb_dirRev (Arvore *a);

/// @brief Função que verifica se a Raiz a precisa de alguma rotação na sub-árvore á Esquerda (simples ou dupla) e a executa caso necessário
/// @param a Raiz que será verificada e possivelmente rotacionada
/// @return ponteiro para a Raiz modificada
Arvore* atualizar_fb_esqRev (Arvore *a);


/// @brief Função que insere um novo nó na Arvore a, está função além de inserir na posição correta seguindo o principio de uma Árvore
/// Binária também balanceia a sub-árvore que recebeu essa nova inserção, mantendo toda a Árvore balanceada
/// @param a Raiz para a Árvore que receberá a inserção
/// @param info Valor a ser armazenado no novo nó
/// @return Ponteiro para a Raiz da Árvore receptora após a inserção
Arvore* inserirRev (Arvore *a, int info);

/// @brief Função para remover um nó da Árvore a que tenha o valor armazenada igual a info, além de remover o nó essa função também 
// rebalanceia a sub-árvore que teve seu nó removido para manter toda a Árvore balanceada
/// @param a Raiz para a Árvore que receberá a inserção
/// @param info Valor do nó que deve ser removido
/// @return Ponteiro para a Raiz da Árvore receptora após a inserção
Arvore* removerRev (Arvore *a, int info);

//void imprimir_in_orderRev (Arvore* a, int nivel);


/// @brief Função para criar uma Árvore vazia /// Sem parâmetros
/// @return NULL
Arvore* cria_arv_vaziaRev ();

/// @brief Função para criar um novo Nó da Árvore
/// @param info Valor a ser armazenado no novo Nó
/// @param e Ponteiro para a sub-Árvore á esquerda do novo Nó
/// @param d Ponteiro para a sub-Árvore á direita do novo Nó
/// @return Ponteiro para o novo Nó
Arvore *criaArvoreRev(int info, Arvore *e, Arvore *d);

/// @brief Função para Desalocar todos os Nós da Arvore recebida por parametro 
/// @param a Árvore a ser Desalocada
void arv_liberaRev (Arvore* a);

/// @brief Função para fazer uma busca recursiva e verificar se o valor v existe dentro da Árvore a 
/// @param a Ponteiro para a Raiz da Árvore em que ocorrerá a busca
/// @param v Valor a ser buscado
/// @return 1 caso o valor exista na árvore e 0 caso não
int buscarRev (Arvore *a, int v);


/// @brief Função para fazer uma busca iterativa e verificar se o valor v existe dentro da Árvore a 
/// @param a Ponteiro para a Raiz da Árvore em que ocorrerá a busca
/// @param v Valor a ser buscado
/// @return 1 caso o valor exista na árvore e 0 caso não
int buscarIteRev(Arvore *a,int v);

/// @brief Função para printar em desOrder a Árvore a, [D,R,E]
/// @param a Ponteiro para a Raiz da Árvore que será printada
void desOrderRev(Arvore *a);

/// @brief Função para printar em inOrder a Árvore a, [E,R,D]
/// @param a Ponteiro para a Raiz da Árvore que será printada 
void inOrderRev(Arvore *a);

/// @brief Função para printar em preOrder a Árvore a, [R,E,D]
/// @param a Ponteiro para a Raiz da Árvore que será printada
void preOrderRev(Arvore *a);

/// @brief Função para printar em posOrder a Árvore a, [E,D,R]
/// @param a Ponteiro para a Raiz da Árvore que será printada
void posOrderRev(Arvore *a);


/// @brief Função para achar o menor valor  de forma recursiva de uma Árvore a
/// @param a Ponteiro para a Raiz da Árvore onde será feita a busca do menor valor
/// @return Menor valor encontrado
int minimoRev(Arvore *a);

/// @brief Função para achar o menor valor de forma iterativa de uma Árvore a
/// @param a Ponteiro para a Raiz da Árvore onde será feita a busca do menor valor
/// @return Menor valor encontrado
int minimoIteRev(Arvore *a);

/// @brief Função para achar o maior valor de forma recursiva de uma Árvore a
/// @param a Ponteiro para a Raiz da Árvore onde será feita a busca do maior valor
/// @return Maior valor encontrado
int maximoRev(Arvore *a);

/// @brief Função para achar o maior valor de forma iterativa de uma Árvore a
/// @param a Ponteiro para a Raiz da Árvore onde será feita a busca do maior valor
/// @return Maior valor encontrado
int maximoIteRev(Arvore *a);


/// @brief Função para achar o ramo com maior soma de dados guardados nos nós
/// @param a Ponteiro para a Raiz da Árvore onde será feita a busca do maior valor
/// @return Maior valor somado de ramos encontrado
int maiorRamoRev (Arvore *a);


/// @brief Verifica se um valor está presente na árvore
/// @param a Ponteiro para a raiz da árvore
/// @param c Valor a ser verificado
/// @return 1 se o valor está presente, 0 caso contrário
int pertence_arvRev (Arvore *a, int c);  

/// @brief Conta o número total de nós na árvore
/// @param a Ponteiro para a raiz da árvore
/// @return Número de nós na árvore
int conta_nosRev (Arvore *a);

/// @brief Calcula a altura da árvore
/// @param a Ponteiro para a raiz da árvore
/// @return Altura da árvore
int calcula_altura_arvoreRev (Arvore *a);

/// @brief Conta o número de nós folha na árvore
/// @param a Ponteiro para a raiz da árvore
/// @return Número de nós folha
int conta_nos_folhaRev (Arvore *a);

/// @brief Encontra o maior valor armazenado na árvore
/// @param a Ponteiro para a raiz da árvore
/// @return Maior valor encontrado
//int max_arvoreRev (Arvore *a);

/// @brief Verifica se a árvore é cheia (cada nó possui 0 ou 2 filhos)
/// @param a Ponteiro para a raiz da árvore
/// @return 1 se a árvore é cheia, 0 caso contrário
int verifica_arvore_cheiaRev (Arvore *a); 

/// @brief Encontra o ancestral comum mais baixo (LCA) de dois elementos na árvore
/// @param a Ponteiro para a raiz da árvore
/// @param e1 Primeiro elemento
/// @param e2 Segundo elemento
/// @return Valor do LCA ou -1 se algum elemento não existir na árvore
int ancestralRev (Arvore*a, int e1, int e2);

/// @brief Constrói uma árvore balanceada a partir de um array ordenado
/// @param v Array de inteiros ordenado
/// @param esq Índice inicial do subarray
/// @param dir Índice final do subarray
/// @return Ponteiro para a raiz da árvore balanceada
Arvore* constroi_balanceado (int v[], int esq, int dir);

/// @brief Espelha a árvore invertendo os filhos esquerdos e direitos
/// @param a Ponteiro para a raiz da árvore original
/// @return Ponteiro para a raiz da árvore espelhada
Arvore *espelha_arvoreRev (Arvore *a);

/// @brief Cria uma cópia exata da árvore fornecida
/// @param a Ponteiro para a raiz da árvore a ser copiada
/// @return Ponteiro para a raiz da cópia
Arvore *copiaArvoreRev(Arvore *a);

#endif