#include <stdio.h>
#include <stdlib.h>
#include "revisao.h"  // Certifique-se de que o cabeçalho está correto

int main() {
    /*
    Arvore *arvore = cria_arv_vaziaRev();

    // Inserção de valores
    arvore = inserirRev(arvore, 50);
    arvore = inserirRev(arvore, 30);
    arvore = inserirRev(arvore, 70);
    arvore = inserirRev(arvore, 20);
    arvore = inserirRev(arvore, 40);
    arvore = inserirRev(arvore, 60);
    arvore = inserirRev(arvore, 80);

    // Teste 1: Mínimo e máximo
    printf("=== Mínimo e Máximo ===\n");
    printf("Mínimo (recursivo): %d\n", minimoRev(arvore));      // Deve retornar 20
    printf("Mínimo (iterativo): %d\n", minimoIteRev(arvore));  // Deve retornar 20
    printf("Máximo (recursivo): %d\n", maximoRev(arvore));      // Deve retornar 80
    printf("Máximo (iterativo): %d\n\n", maximoIteRev(arvore));// Deve retornar 80

    // Teste 2: Maior ramo (função corrigida)
    printf("=== Maior Ramo ===\n");
    printf("Soma do maior ramo: %d\n\n", maiorRamoRev(arvore)); // Deve retornar 260 (50 + 70 + 80)

    // Teste 3: Remoção do mínimo e novo mínimo
    printf("=== Após remover 20 ===\n");
    arvore = removerRev(arvore, 20);
    printf("Novo mínimo (recursivo): %d\n", minimoRev(arvore)); // Deve retornar 30
    printf("Soma do maior ramo: %d\n\n", maiorRamoRev(arvore)); // Deve retornar 250 (50 + 70 + 80)

    printf("%d \n",pertence_arvRev(arvore,15));
    printf("%d \n",pertence_arvRev(arvore,30));

    printf("%d \n",conta_nosRev(arvore));

    printf("Altura da arvore %d \n",calcula_altura_arvoreRev(arvore));
    printf("Nos folhas : %d \n",conta_nos_folhaRev(arvore));

    arv_liberaRev(arvore);*/

    /*Arvore *arvore2 = cria_arv_vaziaRev();

    // Construção da árvore de exemplo:
    //       50
    //     /    \
    //   30     70
    //  /  \   /  \
    //20  40 60   80
    arvore2 = inserirRev(arvore2, 50);
    arvore2 = inserirRev(arvore2, 30);
    arvore2 = inserirRev(arvore2, 70);
    arvore2 = inserirRev(arvore2, 20);
    arvore2 = inserirRev(arvore2, 40);
    arvore2 = inserirRev(arvore2, 60);
    arvore2 = inserirRev(arvore2, 80);

    // Testes
    printf("=== Testes do Ancestral Comum (LCA) ===\n");

    // Caso 1: Ambos na subárvore esquerda (LCA = 30)
    printf("LCA de 20 e 40: %d\n", ancestralRev(arvore2, 20, 40)); // Deve retornar 30

    // Caso 2: Um na esquerda e outro na direita (LCA = 50)
    printf("LCA de 20 e 60: %d\n", ancestralRev(arvore2, 20, 60)); // Deve retornar 50

    // Caso 3: Ambos na subárvore direita (LCA = 70)
    printf("LCA de 60 e 80: %d\n", ancestralRev(arvore2, 60, 80)); // Deve retornar 70

    // Caso 4: Um dos nós é a raiz (LCA = 50)
    printf("LCA de 50 e 80: %d\n", ancestralRev(arvore2, 50, 80)); // Deve retornar 50

    // Caso 5: Nó pai e filho (LCA = 30)
    printf("LCA de 20 e 30: %d\n", ancestralRev(arvore2, 20, 30)); // Deve retornar 30

    // Caso 6: Elemento não existe na árvore
    printf("LCA de 10 e 20: %d\n", ancestralRev(arvore2, 10, 20)); // Deve retornar 0

    // Caso 7: Ambos elementos não existem
    printf("LCA de 10 e 90: %d\n", ancestralRev(arvore2, 10, 90)); // Deve retornar 0

    arv_liberaRev(arvore2);
    
    return 0;*/

    
     // 1) Cria árvore vazia

     // 1) Testes para ehABB
    printf("=== Testes de ehABB (BST Validação) ===\n");

    // Teste 1: Árvore vazia
    Arvore *e1 = cria_arv_vaziaRev();
    printf("Árvore vazia: %s\n", ehABB(e1) ? "É ABB" : "Não é ABB");

    // Teste 2: Árvore de um nó
    Arvore *e2 = criaArvoreRev(10, NULL, NULL);
    printf("Árvore de um nó (10): %s\n", ehABB(e2) ? "É ABB" : "Não é ABB");

    // Teste 3: BST válida via inserções
    Arvore *e3 = cria_arv_vaziaRev();
    int vals3[] = {8, 3, 10, 1, 6, 9, 14};
    for (int i = 0; i < 7; i++) {
        e3 = inserirRev(e3, vals3[i]);
    }
    // Deve ser ABB
    printf("BST válida (8,3,10,1,6,9,14): %s\n", ehABB(e3) ? "É ABB" : "Não é ABB");

    // Teste 4: Árvore que viola a propriedade
    //      8
    //     / \
    //    3   7  <-- 7 < 8 mas está à direita
    Arvore *e4 = criaArvoreRev(8,
                      criaArvoreRev(3, NULL, NULL),
                      criaArvoreRev(7, NULL, NULL));
    printf("Árvore inválida (7 no lado direito de 8): %s\n", ehABB(e4) ? "É ABB" : "Não é ABB");
    Arvore *a = cria_arv_vaziaRev();

    // 2) Insere um conjunto de valores para formar uma BST balanceada
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        a = inserirRev(a, vals[i]);
    }

    // 3) Exibe percursos da árvore
    printf("Percursos da árvore:\n");
    printf(" In-order:  "); inOrderRev(a);  printf("\n");
    printf(" Pre-order: "); preOrderRev(a); printf("\n");
    printf(" Post-order:"); posOrderRev(a); printf("\n\n");

    // 4) Busca de elementos
    printf("Busca de elementos:\n");
    printf("  Existe 40? %s\n", pertence_arvRev(a, 40) ? "Sim" : "Não");
    printf("  Existe 25? %s\n\n", pertence_arvRev(a, 25) ? "Sim" : "Não");

    // 5) Mínimo e máximo (recursivo e iterativo)
    printf("Mínimo e Máximo:\n");
    printf("  Min rec: %d\n",  minimoRev(a));
    printf("  Min ite: %d\n",  minimoIteRev(a));
    printf("  Max rec: %d\n",  maximoRev(a));
    printf("  Max ite: %d\n\n", maximoIteRev(a));

    // 6) Soma do maior ramo
    printf("Maior ramo (soma): %d\n\n", maiorRamoRev(a));

    // 7) Remove o menor valor e mostra novo mínimo
    a = removerRev(a, minimoIteRev(a));
    printf("Após remover o menor:\n");
    printf("  Novo min rec: %d\n", minimoRev(a));
    printf("  Soma do maior ramo: %d\n\n", maiorRamoRev(a));

    // 8) Estatísticas gerais
    printf("Estatísticas:\n");
    printf("  Número de nós: %d\n",        conta_nosRev(a));
    printf("  Altura da árvore: %d\n",      calcula_altura_arvoreRev(a));
    printf("  Nós-folha: %d\n",            conta_nos_folhaRev(a));
    printf("  É árvore cheia? %s\n\n",     verifica_arvore_cheiaRev(a) ? "Sim" : "Não");

    // 9) Ancestral Comum Mais Baixo (LCA)
    printf("Ancestral Comum (LCA):\n");
    printf("  LCA de 20 e 40: %d  (esperado: 30)\n", ancestralRev(a, 20, 40));
    printf("  LCA de 20 e 60: %d  (esperado: 50)\n", ancestralRev(a, 20, 60));
    printf("  LCA de 60 e 80: %d  (esperado: 70)\n", ancestralRev(a, 60, 80));
    printf("  LCA de 10 e 90: %d  (esperado: -1)\n\n", ancestralRev(a, 10, 90));

    // 10) Espelha e exibe o percurso in-order da cópia invertida
    Arvore *esp = espelha_arvoreRev(a);
    printf("In-order da árvore espelhada: ");
    inOrderRev(esp);
    printf("\n\n");

    // 11) Libera toda a memória
    arv_liberaRev(a);
    arv_liberaRev(esp);

    return 0;
}
