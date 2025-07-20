#include <stdio.h>
#include "Lista.h"

int main()
{
    Lista *list = createLista();

    insertFront(10,list);
    insertFront(20,list);
    insertFront(30,list);
    insertFront(40,list);

    printLista(list);

    printf("Soma total de %d \n",sum(list));
    removeFront(list);
    printLista(list);

    printf("42 esta ? %d \n",in(list,42));
    
    removeFront(list);
    removeFront(list);
    removeFront(list);
    removeFront(list);

    insertFront(42,list);
    printLista(list);
    printf("42 esta ? %d \n",in(list,42));

    destroyLista(list);
    destroyLista(NULL);




    Lista *A = createLista();
    Lista *B = createLista();
    if (!A || !B) {
        fprintf(stderr, "Erro ao criar listas\n");
        return EXIT_FAILURE;
    }

    // Popula A com valores ímpares: 1, 3, 5, 7
    insertBack(1, A);
    insertBack(3, A);
    insertBack(5, A);
    insertBack(7, A);

    // Popula B com valores pares: 2, 4, 6, 8
    insertBack(2, B);
    insertBack(4, B);
    insertBack(6, B);
    insertBack(8, B);

    // Imprime A e B antes do merge
    printf("Lista A: ");
    printLista(A);
    printf("Lista B: ");
    printLista(B);

    // Executa o merge
    Lista *C = merge(A, B);
    if (!C) {
        fprintf(stderr, "Erro ao fazer merge\n");
        destroyLista(A);
        destroyLista(B);
        return EXIT_FAILURE;
    }

    // Imprime o resultado
    printf("Lista C (merge): ");
    printLista(C);

    // Verifica que A e B não foram modificadas
    printf("Verificando A após merge: ");
    printLista(A);
    printf("Verificando B após merge: ");
    printLista(B);

    printf("\n%d \n",position(C,5));
    printf("\n%d \n",position(C,11));
    printf("\n maior valor : %d \n",maxValue(C));
    printf("\n menor valor : %d \n",minValue(C));

    printf("\n Similar %d \n",similar(A,B));
    printf("\n Similar %d \n",similar(A,A));
    printf("\n Similar %d \n",similar(A,C));

    printLista(C);
    printReverse(C);
    
    printf("Criando Lista D copiando Lista C\n");
    Lista* D = copy(C);
    printLista(D);

    Lista* E = createLista();
    insertBack(15,E);
    insertBack(14,E);
    insertBack(23,E);
    insertBack(35,E);
    insertBack(98,E);
    insertBack(78,E);
    insertBack(6,E);
    insertBack(10,E);
    insertBack(10,E);
    
    revertList(D);
    printLista(D);


    printLista(E);
    revertList(E);
    printLista(E);
    replace(E,10,11);
    printLista(E);

    Lista *F = subList(E,2,6);
    printLista(F);

    Lista *G = weave(E,F);
    printLista(G);

    int *v = toArray(G);
    printf("\nPrintando o array\n");
    printArray(v,G->size);

    Lista* H = fromArray(v,G->size);
    printf("\nPrintando a Lista H\n");
    printLista(H);
    // Libera todas as listas
    destroyLista(A);
    destroyLista(B);
    destroyLista(C);
    destroyLista(D);
    destroyLista(E);
    destroyLista(F);
    destroyLista(G);
    destroyLista(H);
    
    return 0;
}