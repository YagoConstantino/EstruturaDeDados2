#include <stdio.h>
#include <stdlib.h>
#include "revisao.h"

int main() {
    Arvore *root = cria_arv_vaziaRev();
    int valores[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(valores) / sizeof(valores[0]);

    // Testar insercao
    for (int i = 0; i < n; i++) {
        root = inserirRev(root, valores[i]);
    }
    printf("Arvore após inserções (in-order): ");
    inOrderRev(root);
    printf("\n");

    // Testar buscas
    printf("Buscar 15: %s\n", buscarRev(root, 15) ? "Encontrado" : "Não encontrado");
    printf("Buscar 100: %s\n", buscarRev(root, 100) ? "Encontrado" : "Não encontrado");

    // Testar mínimo e máximo
    printf("Minimo iterativo: %d\n", minimoIteRev(root));
    printf("Maximo iterativo: %d\n", maximoIteRev(root));

    // Testar altura e contagem de nós
    printf("Altura da arvore: %d\n", calcula_altura_arvoreRev(root));
    printf("Total de nós: %d\n", conta_nosRev(root));
    printf("Nós folha: %d\n", conta_nos_folhaRev(root));

    // Testar verificacao de árvore cheia
    printf("Árvore é cheia? %s\n", verifica_arvore_cheiaRev(root) ? "Sim" : "Não");

    // Testar ancestral
    int a = 5, b = 15;
    printf("Menor ancestral comum de %d e %d: %d\n", a, b, ancestralRev(root, a, b));

    // Testar remoção
    root = removerRev(root, 10);
    printf("Arvore após remover 10 (in-order): ");
    inOrderRev(root);
    printf("\n");

    // Testar espelhamento
    Arvore *espelho = espelha_arvoreRev(root);
    printf("Espelho (in-order): ");
    inOrderRev(espelho);
    printf("\n");

    // Testar copia
    Arvore *copia = copiaArvoreRev(root);
    printf("Cópia (pre-order): ");
    preOrderRev(copia);
    printf("\n");

    // Testar construção balanceada a partir de vetor ordenado
    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    Arvore *bal = constroi_balanceado(sorted, 0, 6);
    printf("Árvore balanceada (level-order approximado via in-order): ");
    inOrderRev(bal);
    printf("\n");

    // Liberar memória
    arv_liberaRev(root);
    arv_liberaRev(espelho);
    arv_liberaRev(copia);
    arv_liberaRev(bal);

    return 0;
}
