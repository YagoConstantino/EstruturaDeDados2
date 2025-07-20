#include <stdio.h>
#include "sorting.c"
int printVetor(int*V,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",V[i]);
    }
    printf("\n\n");
}

int main()
{
    int vetor[10] = { 11,23,5,4,6,98,3,13,46,77};
    printVetor(vetor,10);
    //bubble_sort(vetor,10);
    //bubble_recursivo(vetor,10,0);
    //selection_sort(vetor,10);
    //selectionSortRecursivo(vetor,10,0);
    //insertionSort(vetor,10);
    //quickSort(vetor,0,9);
    mergesort(vetor,0,10);
    printVetor(vetor,10);
    return 0;
}