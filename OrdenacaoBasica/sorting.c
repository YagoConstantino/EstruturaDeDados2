#include <stdio.h>
#include <stdlib.h>
void troca(int *V,int i,int j)
{
    int aux = V[i];
    V[i] = V[j];
    V[j] = aux;
}

void bubble_sort(int *V,int n)
{
    int i,j;
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n-i-1;j++)
        {
            if(V[j]> V[j+1])
                troca(V,j+1,j);
        }
    }
}

void bubble_recursivo(int *V,int n,int i)
{
    int j;
    if(i == n-1)
        return;

    else
    {
        for(j = 0;j<n-i-1;j++)
        {
            if(V[j]> V[j+1])
                troca(V,j+1,j);
        }
        bubble_recursivo(V,n,i+1);
    }
}

void selection_sort(int *V,int n)
{
    int menor,i,j;

    for(i = 0;i<n;i++)
    {
        menor = i;
        for(j = i+1;j<n;j++)
        {
            if(V[j]<=V[menor])
            {
                menor = j;
            }
        }
        troca(V,i,menor);
    }
}

void selectionSortRecursivo(int *V,int n,int i)
{
    int j;
    if (i == n-1)
        return;
    else
    {
        int menor = i;
        for(j = i+1;j<n;j++)
        {
            if(V[j]<=V[menor])
            {
                menor = j;
            }
            
        }
        troca(V,i,menor);
        selectionSortRecursivo(V,n,i+1);
    }
}

void insertionSort(int V[], int n) {
    // j percorre do segundo elemento (índice 1) até o final
    for (int j = 1; j < n; j++) 
    {
        int key = V[j];      // 1) Guardamos o valor a inserir
        int i = j - 1;       // 2) Começamos a comparar um passo à esquerda

        // 3) Enquanto i >= 0 e o elemento à esquerda for maior que key,
        //    deslocamos esse elemento uma posição para a direita
        while (i >= 0 && V[i] > key) 
        {
            V[i + 1] = V[i];
            i--;
        }

        // 4) Agora i+1 é a posição certa para a chave
        V[i + 1] = key;
    }
}

int particionar(int *V,int esq,int dir)
{
    int pivo = V[dir];
    int i = esq -1;
    int j;
    for(j =esq;j<dir;j++)
    {
        if(V[j]<=pivo)
        {
            i++;
            troca(V,j,i);
        }
    }
    troca(V,i+1,dir);
    return i+1;
}


void quickSort(int *V,int inicio,int fim)
{
    if(inicio < fim)
    {
        int pivo = particionar(V,inicio,fim);
        quickSort(V,inicio,pivo-1);
        quickSort(V,pivo+1,fim);
    }
}

void merge(int *V,int inicio,int meio,int fim)
{
    int i = inicio;
    int j = meio;
    int tamanho = fim -inicio;
    int *temp = malloc(sizeof(int)*tamanho);
    int k = 0;
    while(i < meio && j < fim)
    {
        
        if(V[i]<= V[j])
        {
            temp[k++] = V[i++];
        }
        else
            temp[k++] = V[j++];
    }

    while (i< meio)
    {
        temp[k++] = V[i++];
    }
    while (j< fim)
    {
        temp[k++] = V[j++];
    }
    
    for(i = inicio,k=0;i<fim;i++,k++)
        V[i] = temp[k];

    free(temp);
}

void mergesort(int *V,int inicio,int fim)
{
    if (fim - inicio > 1) {
        int meio =  (fim + inicio) / 2;
        mergesort(V, inicio, meio);  // ordena a primeira metade
        mergesort(V, meio, fim);     // ordena a segunda metade
        merge(V, inicio, meio, fim); // intercala as duas metades
    }
}