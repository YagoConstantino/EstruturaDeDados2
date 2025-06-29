#include "revisao.h"

int maior(int a,int b)
{
    return a > b ?a :b;
}

Arvore *cria_arv_vaziaRev() {
    return NULL;
}

Arvore *criaArvoreRev(int info, Arvore *e, Arvore *d) {
    Arvore *nova = (Arvore *)malloc(sizeof(Arvore));
    if (nova == NULL) return NULL; // Verificação de alocação
    nova->info = info;
    nova->esq = e;
    nova->dir = d;
    return nova;
}

Arvore *inserirRev(Arvore *a, int info) {
    if (a == NULL) {
        a = criaArvoreRev(info, NULL, NULL);
    } else if (a->info > info) {
        a->esq = inserirRev(a->esq, info); // Corrigido: atualiza a->esq
    } else {
        a->dir = inserirRev(a->dir, info); // Corrigido: atualiza a->dir
    }
    return a;
}

int buscarRev(Arvore *a, int v) {
    if (a == NULL) return 0;
    if (a->info == v) return 1;
    if (a->info > v) return buscarRev(a->esq, v);
    return buscarRev(a->dir, v);
}

Arvore *removerRev(Arvore *a, int info) {
    if (a == NULL) return NULL;
    if (a->info > info) {
        a->esq = removerRev(a->esq, info);
    } else if (a->info < info) {
        a->dir = removerRev(a->dir, info);
    } else {
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            a = NULL;
        } else if (a->esq == NULL) {
            Arvore *temp = a->dir;
            free(a);
            a = temp;
        } else if (a->dir == NULL) {
            Arvore *temp = a->esq;
            free(a);
            a = temp;
        } else {
            // Encontra o predecessor (maior na subárvore esquerda)
            Arvore *temp = a->esq;
            while (temp->dir != NULL) {
                temp = temp->dir;
            }
            a->info = temp->info; // Copia o valor do predecessor
            temp->info = info;
            a->esq = removerRev(a->esq, info); // Remove o predecessor
        }
    }
    return a;
}

void arv_liberaRev(Arvore *a) {
    if (a != NULL) {
        arv_liberaRev(a->esq);
        arv_liberaRev(a->dir);
        free(a);
    }
}

int buscarIteRev(Arvore *a, int v) {
    while (a != NULL) {
        if (a->info == v) return 1;
        else if (a->info > v) a = a->esq;
        else a = a->dir;
    }
    return 0;
}

void desOrderRev(Arvore *a) {
    if (a != NULL) {
        desOrderRev(a->dir);
        printf("%d ", a->info);
        desOrderRev(a->esq);
    }
}

void inOrderRev(Arvore *a)
{
    if(a != NULL)
    {
        inOrderRev(a->esq);
        printf("%d ",a->info);
        inOrderRev(a->dir);
    }
}

void preOrderRev(Arvore *a)
{
    if( a != NULL)
    {
        printf("%d ",a->info);
        preOrderRev(a->esq);
        preOrderRev(a->dir);
    }
}

void posOrderRev(Arvore *a)
{
    if(a != NULL)
    {
        posOrderRev(a->esq);
        posOrderRev(a->dir);
        printf("%d ",a->info);
    }
}

int minimoRev(Arvore *a)
{
    if(a == NULL) return -1;
    if(a->esq == NULL) return a->info;
    if(a->esq) return minimoRev(a->esq);
}

int minimoIteRev(Arvore *a)
{
    if(a == NULL) return -1;
    while(a->esq)
        a = a->esq;

    return a->info;
}

int maximoRev(Arvore *a)
{
    if(a == NULL) return -1;
    if(a->dir == NULL) return a->info;
    if(a->dir) return maximoRev(a->dir);
}

int maximoIteRev(Arvore *a)
{
    if(a == NULL) return -1;
    while(a->dir)
        a = a->dir;

    return a->info;
}

int maiorRamoRev(Arvore *a)
{
    if(a == NULL) return 0;
    return maior(maiorRamoRev(a->esq),maiorRamoRev(a->dir)) + a->info;
}

int pertence_arvRev(Arvore *a, int c)
{
    if(a == NULL) return 0;
    if(a->info == c) return 1;

    return pertence_arvRev(a->esq,c) || pertence_arvRev(a->dir,c);
}

int conta_nosRev(Arvore *a)
{
    if(a == NULL) return 0;
    return conta_nosRev(a->esq) + conta_nosRev(a->dir) +1;
}

int calcula_altura_arvoreRev(Arvore *a)
{
    if(a == NULL) return -1;

    return maior(calcula_altura_arvoreRev(a->esq),calcula_altura_arvoreRev(a->dir)) +1;
}

int conta_nos_folhaRev(Arvore *a)
{
    if(a == NULL) return 0;
    if(a->esq == NULL && a->dir == NULL) return 1;

    return conta_nos_folhaRev(a->esq) + conta_nos_folhaRev(a->dir);
}

int max_arvoreRev(Arvore *a)
{
    if(a == NULL) return 0;

    return maior(a->info,maior(max_arvoreRev(a->esq),max_arvoreRev(a->dir)));
}

int verifica_arvore_cheiaRev(Arvore *a)
{
    if(a == NULL) return 1;
    if(a->esq == NULL && a->dir == NULL) return 1;
    if(a->esq != NULL && a->dir != NULL) 
        return verifica_arvore_cheiaRev(a->esq) && verifica_arvore_cheiaRev(a->dir);

    return 0;
}

int ancestralRev(Arvore *a, int e1, int e2)
{
    if(pertence_arvRev(a,e1)&&pertence_arvRev(a,e2))
    {
        if(e1 < a->info && e2<a->info)
            return ancestralRev(a->esq,e1,e2);
        
        else if (e1 > a->info && e2 > a->info)
            return ancestralRev(a->dir,e1,e2);

        else
            return a->info;    
    }
    return 0;
}

Arvore *constroi_balanceado(int v[], int esq, int dir)
{
    if (esq > dir) 
        return NULL;

    int meio = (esq+dir)/2;
    Arvore* nova = criaArvoreRev(v[meio],NULL,NULL);

    nova->esq = constroi_balanceado(v,esq,meio-1);
    nova->dir = constroi_balanceado(v,meio+1,dir);
    return nova;
}

Arvore *espelha_arvoreRev(Arvore *a)
{
    if(a == NULL) return NULL;

    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    novo->info = a->info;

    novo->esq = espelha_arvoreRev(a->dir);
    novo->dir = espelha_arvoreRev(a->esq);
    return novo;
}

Arvore *copiaArvoreRev(Arvore *a)
{
    if(a == NULL) return NULL;
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    novo->info = a->info;

    novo->esq = copiaArvoreRev(a->esq);
    novo->dir = copiaArvoreRev(a->dir);
    return novo;
}