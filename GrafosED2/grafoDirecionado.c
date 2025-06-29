#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

void imprimirGrafoAdj(GrafoA* Ga)
{
    int i;
    printf("Grafo Lista Adjacente\n");

    for(i = 0;i<Ga->V;i++)
    {
        NoA *aux = Ga->Adj[i];
        printf("%d -> ",i);
        if(aux == NULL) printf("null");
        while(aux != NULL)
        {
            
            printf("%d ",aux->id);
            aux = aux->next;
        }
        printf("\n");
    }
}

void inserirGrafoAdj(GrafoA* Ga,int origem,int destino)
{
    NoA* novo = (NoA*)malloc(sizeof(NoA));
    novo->id = destino;
    novo->next = NULL;

    
    if(Ga->Adj[origem] == NULL)
    {
        Ga->Adj[origem] =  novo;
    }
    else
    {
        NoA* aux = Ga->Adj[origem];
        while(aux->next != NULL)
        {
        aux = aux->next;
        }
        aux->next = novo;
    }
    Ga->E++;
}

void popularListaAdjcente(GrafoA* Ga)
{
   inserirGrafoAdj(Ga,0,1);
   inserirGrafoAdj(Ga,0,5);
   inserirGrafoAdj(Ga,1,2);
   inserirGrafoAdj(Ga,1,3);
   inserirGrafoAdj(Ga,2,0);
   inserirGrafoAdj(Ga,2,4);
   inserirGrafoAdj(Ga,3,2);
   inserirGrafoAdj(Ga,4,3);
   inserirGrafoAdj(Ga,5,4);

}
/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

void imprimirGrafoM(GrafoM* graf)
{
    int i,j;
    printf("Grafo Matriz de Adjacencia\n    ");
    for(i = 0;i<graf->V;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(i =0;i<graf->V;i++)
    {
        printf("%d   ",i);
        for(j = 0;j<graf->V;j++)
        {
            printf("%d ",graf->Mat[i][j]);
        }
        printf("\n");
    }
}

void inicializaMatriz(GrafoM* graf)
{
    int i,j;
    for(i = 0;i<graf->V;i++)
    {
        for(j = 0;j<graf->V;j++)
            graf->Mat[i][j] = 0;
    }
}
void inserirGrafoM(GrafoM* graf,int origem,int destino)
{
    if(origem >= graf->V || destino >= graf->V)
    {
        printf("Valores fora dos limites \n");
        return;
    }
    else
    {
        graf->Mat[origem][destino] = 1;
    }
}

void popularGrafoM(GrafoM *Gm)
{
   inserirGrafoM(Gm,0,1);
   inserirGrafoM(Gm,0,5);
   inserirGrafoM(Gm,1,2);
   inserirGrafoM(Gm,1,3);
   inserirGrafoM(Gm,2,0);
   inserirGrafoM(Gm,2,4);
   inserirGrafoM(Gm,3,2);
   inserirGrafoM(Gm,4,3);
   inserirGrafoM(Gm,5,4);
}
/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}


/* */
int main () {

   int Va = 10; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);
   popularListaAdjcente(Ga);
   imprimirGrafoAdj(Ga);
    
   int Vm = 6; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);
   inicializaMatriz(Gm);
   popularGrafoM(Gm);
   imprimirGrafoM(Gm);
   

   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}
