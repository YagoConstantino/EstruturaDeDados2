#include "Lista.h"
#include <stdlib.h>
Lista *createLista()
{
    Lista *nova= (Lista*)malloc(sizeof(Lista));
    if(nova != NULL)
    {
        nova->head = NULL;
        nova->tail = NULL;
        nova->size = 0;
    
        return nova;
    }
    else
    {
        printf("Erro ao alocar a Lista \nRetornado Nulo\n");
        return NULL;
    }
}

void destroyLista(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para destroyLista nula\n\n");
        return;
    }
    Elem* aux1 = l->head;
    while (aux1)
    {
        Elem* aux2 = aux1;
        aux1 = aux1->next;
        free(aux2);
    }
    free(l);
    
}

void insertFront(int dat, Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para inserFront é Nula\n");
        return;
    }
    Elem *novo = (Elem*)malloc(sizeof(Elem));
    novo->data = dat;
    novo->prev = NULL;

    if(l->head == NULL)
    {
        novo->next = NULL;
        l->head = l->tail = novo;
    }
    else
    {
        l->head->prev = novo;
        novo->next = l->head;
        l->head = novo;
    }
    l->size++;
}

void insertBack(int dat, Lista *l)
{ 
    if(l == NULL)
    {
        printf("Lista passada para insertBack é nula \n");
        return;
    }
    Elem *novo = (Elem*)malloc(sizeof(Elem));
    novo->data = dat;
    novo->next = NULL;

    if(l->head == NULL)
    {
        novo->prev = NULL;
        l->head = l->tail = novo;
    }
    else
    {
        l->tail->next = novo;
        novo->prev = l->tail;
        l->tail = novo;
    }
    l->size++;
}

void removeFront(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para removeFront é nula\n");
        return;
    }

    if(l->head == NULL)
    {
        printf("Lista passada para removeFront é vazia\n");
        return;
    }

    if(l->head == l->tail)
    {
        Elem* aux = l->head;
        l->head = l->tail = l->head->next;
        free(aux);
    }
    else
    {
        Elem* aux =l->head;
        l->head = l->head->next;
        free(aux);
    }
    l->size--;
}

void removeback(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para removeback é Nula\n\n");
        return;
    }

    if(l->head == NULL)
    {
        printf("Lista passada para removeback está vazia \n\n");
        return;
    }

    Elem *aux = l->tail;
    l->tail = aux->prev;
    if (l->tail != NULL) {
        l->tail->next = NULL;
    } else {
        // lista ficou vazia → head deve ser NULL
        l->head = NULL;
    }
    free(aux);
    l->size--;
}

void printLista(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para PrintLista é Nula\n");
        return;
    }

    Elem* aux = l->head;
    while(aux)
    {
        printf("%d ",aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int getSizeLista(Lista *l)
{
    if(l ==NULL)
    {
        printf("Lista passada para getSizeLista é Nula, retornado 0\n\n");
        return 0; 
    }
    return l->size;
}

int sum(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para sum é Nula, retornado 0\n\n");
        return 0;
    }
    Elem *aux = l->head;
    int cont = 0;
    while(aux)
    {
        cont += aux->data;
        aux = aux->next;
    }
    return cont;
}

int in(Lista *l, int k)
{
    if(l == NULL)
    {
        printf("Lista passada para in é Nula, retornado 0\n\n");
        return 0;
    }

    Elem *aux = l->head;
    while (aux)
    {
        if(aux->data == k) return 1;
        aux = aux->next;
    }
    return 0;
    
}

int position(Lista *l, int k)
{
    if(!in(l,k))
    {
        printf("Valor passado não existe dentro da Lista, retornando -1\n");
        return -1;
    }

    Elem *aux = l->head;
    int cont = 0;
    while (aux)
    {
        if(aux->data == k)
            return cont;

        cont++;
        aux = aux->next;
    }
    return -1;
    
}

Lista *merge(Lista *A, Lista *B)
{
    Elem *pA = (A ? A->head : NULL);
    Elem *pB = (B ? B->head : NULL);

    Lista* C = createLista();
    if (!C) return NULL;

    // 2) Comparar o campo data, não o ponteiro do nó
    while (pA && pB)
    {
        if (pA->data < pB->data)
        {
            insertBack(pA->data, C);
            pA = pA->next;
        }
        else
        {
            insertBack(pB->data, C);
            pB = pB->next;
        }
    }
    // 3) Caso ainda reste elemento em A ou B, copia o restante
    while (pA)
    {
        insertBack(pA->data, C);
        pA = pA->next;
    }
    while (pB)
    {
        insertBack(pB->data, C);
        pB = pB->next;
    }
    return C;
}

int maxValue(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para maxValue é nula, retornando -1\n");
        return -1;
    }
    if(l->head == NULL)
    {
        printf("Lista passada para maxValue é vazia, retornando -1\n");
        return -1;
    }

    int max = l->head->data;
    Elem*aux = l->head;

    while(aux)
    {
        if(aux->data > max)
            max = aux->data;

        aux = aux->next;
    }
    return max;
}

int minValue(Lista *l)
{
      if(l == NULL)
    {
        printf("Lista passada para minValue é nula, retornando -1\n");
        return -1;
    }
    if(l->head == NULL)
    {
        printf("Lista passada para minValue é vazia, retornando -1\n");
        return -1;
    }

    int min = l->head->data;
    Elem*aux = l->head;

    while(aux)
    {
        if(aux->data < min)
            min = aux->data;

        aux = aux->next;
    }
    return min;
}

int similar(Lista *A, Lista *B)
{
    if(getSizeLista(A) != getSizeLista(B))
        return 0;

    if(A == NULL || B == NULL)
    {
        printf("Uma das listas passadas é nula em similar, retornando -1\n ");
        return -1;
    }

    Elem *auxA = A->head;
    Elem *auxB = B->head;

    while(auxA)
    {
        if(auxA->data != auxB->data)
            return 0;

        auxA = auxA->next;
        auxB = auxB->next;
    }
    return 1;
}

Lista *copy(Lista *l)
{
    if(l == NULL) return NULL;

    Lista* nova =createLista();
    Elem *aux = l->head;

    while (aux)
    {
        insertBack(aux->data,nova);
        aux = aux->next;
    }
    return nova;
    
}

Lista *unite(Lista *A, Lista *B)
{
    if(A == NULL )
    {
        printf("Lista A passada para unite é nula, retornado B\n");
        return copy(B);
    }

    if(B == NULL )
    {
        printf("Lista B passada para unite é nula, retornado A\n");
        return copy(A);
    }

    Lista* C = createLista();
    Elem *auxA = A->head;
    while (auxA)
    {
        if(!in(C,auxA->data))
        {
            insertBack(auxA->data,C);
        }
        auxA = auxA->next;
    }
    
    Elem *auxB = B->head;

    while(auxB)
    {
        if(!in(C,auxB->data))
        {
            insertBack(auxB->data,C);
        }
        auxB = auxB->next;
    }
    return C;
    
}

void revertList(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para revertList é nula\n");
        return;
    }

    Elem* aux = l->head;

    while(aux)
    {
        Elem *proximo = aux->next;
        aux->next = aux->prev;
        aux->prev = proximo;

        aux = proximo;
    }
    Elem*aux2 = l->tail;
    l->tail = l->head;
    l->head = aux2;
}

void printReverse(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada para printReverse é Nula\n");
        return;
    }

    Elem* aux = l->tail;
    while(aux)
    {
        printf("%d ",aux->data);
        aux = aux->prev;
    }
    printf("\n");
}

void printArray(int *V, int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        printf("%d ",V[i]);
    }
    printf("\n");
}

void replace(Lista *l, int old, int new)
{
    if(l == NULL)
    {
        printf("Lista passada para replace é nula\n");
        return;
    }
    if(l->head == NULL)
    {
        printf("Lista passada para replace está vazia\n");
        return;
    }
    Elem *aux = l->head;
    while(aux)
    {
        if(aux->data==old)
        {
            aux->data = new;
        }
        aux = aux->next;
    }
}

Lista *subList(Lista *l, int start, int count)
{
    if(l == NULL)
    {
        printf("Lista passada para subList é nula\n");
        return NULL;
    }
    if(l->head == NULL)
    {
        printf("Lista passada para subList está vazia\n");
        return NULL;
    }
    if(start < 0)
    {
        printf("Inicio passado é negativo, inválido\n");
        return NULL;
    }
    if(start + count > l->size)
    {
        printf("Numero de valores a ser copiados para a sublist é maior que o tamanho da lista original\n");
        return NULL;
    }

    Lista* nova = createLista();
    int inicio = 0;
    int contador = 0;
    Elem *aux = l->head;
    while(aux)
    {
        if(inicio >= start && contador < count )
        {
            insertBack(aux->data,nova);
            contador++;
        }
        aux = aux->next;
        inicio++;
    }
    return nova;
}

Lista *weave(Lista *A, Lista *B)
{
    Lista *nova = createLista();
    Elem *auxA = A->head;
    Elem *auxB = B->head;

    int i = 0;
    while(auxA && auxB)
    {
        if(i %2 == 0)
        {
            insertBack(auxA->data,nova);
            auxA = auxA->next;            
        }   
        else
        {
            insertBack(auxB->data,nova);
            auxB = auxB->next;
        }
        
        i++;
    }

   while (auxA)
   {
        insertBack(auxA->data,nova);
        auxA = auxA->next;
   }
   while (auxB)
   {
        insertBack(auxB->data,nova);
        auxB = auxB->next;
   }
    return nova;   
}

int *toArray(Lista *l)
{
    if(l == NULL)
    {
        printf("Lista passada nula\n");
        return NULL;
    }

    int *V = (int*)malloc(sizeof(int)*l->size);

    Elem* aux = l->head;
    int i = 0;

    while (aux)
    {
        V[i] = aux->data;
        i++;
        aux = aux->next;
    }
    return V;
    
}

Lista *fromArray(int *v, int n)
{
    Lista *nova = createLista();

    int i;
    for(i = 0;i<n;i++)
    {
        insertBack(v[i],nova);
    }
    return nova;
}
