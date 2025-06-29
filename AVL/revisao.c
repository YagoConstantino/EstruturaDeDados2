#include "revisao.h"

int maiorRev(int a, int b)
{
    return a > b ?a :b;
}

int alturaRev(Arvore *a)
{
    return a == NULL ? -1 :a->altura;
}

int atualizar_alturaRev(Arvore *a)
{
    return maiorRev(alturaRev(a->esq),alturaRev(a->dir))+1;
}

int balanceamentoRev(Arvore *a)
{
    return alturaRev(a->dir) - alturaRev(a->esq);
}

Arvore *rotacao_simples_esqRev(Arvore *a)
{
    Arvore*temp = a->dir;
    a->dir = temp->esq;
    temp->esq = a;

    a->altura = atualizar_alturaRev(a);
    temp->altura = atualizar_alturaRev(temp);
    return temp;
}

Arvore *rotacao_simples_dirRev(Arvore *a)
{
    Arvore*temp = a->esq;
    a->esq = temp->dir;
    temp->dir = a;

    a->altura = atualizar_alturaRev(a);
    temp->altura = atualizar_alturaRev(temp);
    return temp;
}

Arvore *rotacao_dupla_esqRev(Arvore *a)
{
    a->dir = rotacao_simples_dirRev(a->dir);
    return rotacao_simples_esqRev(a);
}

Arvore *rotacao_dupla_dirRev(Arvore *a)
{
    a->esq = rotacao_simples_esqRev(a->esq);
    return rotacao_simples_dirRev(a);
}

Arvore *atualizar_fb_dirRev(Arvore *a)
{
    a->altura = atualizar_alturaRev(a);

    if(balanceamentoRev(a) == 2)
    {
        if(balanceamentoRev(a->dir) >= 0)
            a = rotacao_simples_esqRev(a);
        else
            a = rotacao_dupla_esqRev(a);
    }
    return a;
}

Arvore *atualizar_fb_esqRev(Arvore *a)
{
    a->altura = atualizar_alturaRev(a);

    if(balanceamentoRev(a) == -2)
    {
        if(balanceamentoRev(a->esq) <= 0)
            a = rotacao_simples_dirRev(a);

        else
            a = rotacao_dupla_dirRev(a);
    }
    return a;
}

Arvore *inserirRev(Arvore *a, int info)
{
    if(a == NULL)
    {
        a = (Arvore*)malloc(sizeof(Arvore));
        a->altura = 0;
        a->info = info;
        a->esq = NULL;
        a->dir = NULL;
    }

    else if (info < a->info)
    {
        a->esq = inserirRev(a->esq,info);
        a = atualizar_fb_esqRev(a);
    }
    else
    {
        a->dir = inserirRev(a->dir,info);
        a = atualizar_fb_dirRev(a);
    }
    return a;
}

Arvore *removerRev(Arvore *a, int info)
{
    if(a == NULL) return NULL;

    else if (info < a->info)
    {
        a->esq = removerRev(a->esq,info);
        a = atualizar_fb_dirRev(a);
    }
    else if (info > a->info)
    {
        a->dir = removerRev(a->dir,info);
        a = atualizar_fb_esqRev(a);
    }
    else
    {
        if(a->esq == NULL && a->dir == NULL)
        {
            free(a);
            a = NULL;
        }
        else if (a->esq == NULL)
        {
            Arvore *temp = a->dir;
            free(a);
            a = a->dir;
        }
        else if (a->dir == NULL)
        {
            Arvore *temp = a->esq;
            free(a);
            a = temp;
        }
        else
        {
            Arvore *temp = a->esq;
            while(temp->esq)
                temp = temp->esq;

            a->info = temp->info;
            temp->info = info;
            a->esq = removerRev(a->esq,info);

            a = atualizar_fb_dirRev(a);
        }
    }

    return a;
}

Arvore *cria_arv_vaziaRev()
{
    return NULL;
}

Arvore *criaArvoreRev(int info, Arvore *e, Arvore *d)
{
    Arvore* nova = (Arvore*)malloc(sizeof(Arvore));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->info = info;
    nova->altura = atualizar_alturaRev(nova);
    
    return nova;
}

void arv_liberaRev(Arvore *a)
{
    if(a != NULL)
    {
        arv_liberaRev(a->esq);
        arv_liberaRev(a->dir);
        free(a);
    }
}

int buscarRev(Arvore *a, int v)
{
    if(a == NULL) return 0;
    if(a->info == v) return 1;
    if(v < a->info) return buscarRev(a->esq,v);
    return buscarIteRev(a->dir,v);
}

int buscarIteRev(Arvore *a, int v)
{
    if(a == NULL) return 0;

    while(a != NULL)
    {
        if(a->info == v) return 1;
        else if(v < a->info) a = a->esq;
        else a = a->dir;
    }
    return 0;
}

void desOrderRev(Arvore *a)
{
    if(a != NULL)
    {
        desOrderRev(a->dir);
        printf("%d ",a->info);
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
    if(a != NULL)
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
    if(a == NULL) return 0;
    if(a->esq == NULL) return a->info;
    return minimoRev(a->esq);
}

int minimoIteRev(Arvore *a)
{
    if(a == NULL) return 0;

    while(a->esq)
        a = a->esq;

    return a->info;
}

int maximoRev(Arvore *a)
{
    if(a == NULL) return 0;
    if(a->dir == NULL) return a->info;
    return maximoRev(a->dir);
}

int maximoIteRev(Arvore *a)
{
    if(a == NULL) return 0;
    while(a->dir)
        a = a->dir;

    return a->info;
}

int maiorRamoRev(Arvore *a)
{
    if(a == NULL) return 0;

    return maiorRev(maiorRamoRev(a->esq),maiorRamoRev(a->dir)) + a->info;
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

    return 1 + maiorRev(calcula_altura_arvoreRev(a->esq),calcula_altura_arvoreRev(a->dir)) ;
}

int conta_nos_folhaRev(Arvore *a)
{
    if(a == NULL) return 0;
    if(a->esq == NULL && a->dir == NULL) return 1;

    return conta_nos_folhaRev(a->esq) + conta_nos_folhaRev(a->dir);
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
    if(a == NULL) return 0;

    if(pertence_arvRev(a,e1) && pertence_arvRev(a,e2))
    {
        if(e1 < a->info && e2 < a->info)
            return ancestralRev(a->esq,e1,e2);

        else if ( e1 > a->info && e2 > a->info)
            return ancestralRev(a->dir,e1,e2);

        return a->info;
    }
    return 0;
}

Arvore *constroi_balanceado(int v[], int esq, int dir)
{
    if(esq > dir) return NULL;
    int meio = (esq + dir)/2;

    Arvore* nova = criaArvoreRev(v[meio],NULL,NULL);

    nova->esq = constroi_balanceado(v,esq,meio-1);
    nova->dir = constroi_balanceado(v,meio+1,dir);

    return nova;
}

Arvore *espelha_arvoreRev(Arvore *a)
{
    if(a == NULL )return NULL;
    Arvore *nova = (Arvore*)malloc(sizeof(Arvore));

    nova->info = a->info;
    nova->esq = espelha_arvoreRev(a->dir);
    nova->dir = espelha_arvoreRev(a->esq);
    nova->altura = atualizar_alturaRev(nova);
    return nova;
}

Arvore *copiaArvoreRev(Arvore *a)
{
     if(a == NULL )return NULL;
    Arvore *nova = (Arvore*)malloc(sizeof(Arvore));

    nova->info = a->info;
    nova->esq = copiaArvoreRev(a->esq);
    nova->dir = copiaArvoreRev(a->dir);
    nova->altura = atualizar_alturaRev(nova);
    return nova;
}
