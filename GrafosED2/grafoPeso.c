#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
   int peso;
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
            
            printf("%d w(:%d) ",aux->id,aux->peso);
            aux = aux->next;
        }
        printf("\n\n");
    }
}

void inserirGrafoAdj(GrafoA* Ga,int origem,int destino,int peso)
{
    NoA* novo = (NoA*)malloc(sizeof(NoA));
    novo->id = destino;
    novo->next = NULL;
    novo->peso = peso;

    
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
   inserirGrafoAdj(Ga,0,1,1);
   inserirGrafoAdj(Ga,0,3,5);
   inserirGrafoAdj(Ga,1,3,8);
   inserirGrafoAdj(Ga,2,0,5);
   inserirGrafoAdj(Ga,2,3,4);
   inserirGrafoAdj(Ga,3,3,6);
   inserirGrafoAdj(Ga,3,4,3);
   inserirGrafoAdj(Ga,4,2,7);
   inserirGrafoAdj(Ga,4,5,9);
   inserirGrafoAdj(Ga,5,0,2);

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
void inserirGrafoM(GrafoM* graf,int origem,int destino,int peso)
{
    if(origem >= graf->V || destino >= graf->V)
    {
        printf("Valores fora dos limites \n");
        return;
    }
    else
    {
        graf->Mat[origem][destino] = peso;
    }
   graf->E++;
}

void popularGrafoM(GrafoM *Gm)
{
   inserirGrafoM(Gm,0,1,1);
   inserirGrafoM(Gm,0,3,5);
   inserirGrafoM(Gm,1,3,8);
   inserirGrafoM(Gm,2,0,5);
   inserirGrafoM(Gm,2,3,4);
   inserirGrafoM(Gm,3,3,6);
   inserirGrafoM(Gm,3,4,3);
   inserirGrafoM(Gm,4,2,7);
   inserirGrafoM(Gm,4,5,9);
   inserirGrafoM(Gm,5,0,2);
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

void numeroArestasM(GrafoM* Gm,int no)
{
   if(no>Gm->V || no < 0)
   {
      printf("aresta fora do grafo\n\n");
      return;
   }
   int cont = 0;
   for(int i = 0;i<Gm->V;i++)
   {
      if(Gm->Mat[i][no]!= 0)
         cont++;
   }
   printf("Número de arestas incidentes no Vértice %d: %d\n\n",no,cont);
}

void numeroSaidasM(GrafoM *Gm,int no)
{
   if(no>Gm->V || no < 0)
   {
      printf("aresta fora do grafo\n\n");
      return;
   }
   int cont = 0;

   for(int i = 0;i<Gm->V;i++)
   {
      if(Gm->Mat[no][i] != 0)
         cont++;
   }
   printf("Número de Saidas de arestas no Vétice %d: %d\n\n",no,cont);
}

void verticesAdjacentesM(GrafoM *Gm,int no)
{
   if(no>Gm->V || no < 0)
   {
      printf("aresta fora do grafo\n\n");
      return;
   }
   int i;
   printf("Vértices adjacentes ao vértice %d: ",no);
   for(i = 0;i<Gm->V;i++)
   {
      if(Gm->Mat[no][i] != 0)
      {
         printf("%d ",i);
      }
   }
   printf(".\n\n");
}

void numeroArestasAdj(GrafoA* Ga,int no)
{
   if(no>Ga->V || no < 0)
   {
      printf("aresta fora do grafo\n\n");
      return;
   }
   int cont = 0;
   int i;
   for(i=0;i<Ga->V;i++)
   {
      NoA *aux = Ga->Adj[i];
      while(aux != NULL)
      {
         if(aux->id == no)
            cont++;
            
         aux = aux->next;
      }
   }
   printf("Número de arestas incidentes no Vértice %d: %d\n\n",no,cont);
}

void numeroSaidasAdj(GrafoA *Ga,int no)
{
   if(no>Ga->V || no < 0)
   {
      printf("aresta fora do grafo\n\n");
      return;
   }

   int cont = 0;
   NoA *aux = Ga->Adj[no];
   while (aux != NULL)
   {
      cont++;
      aux = aux->next;
   }

   printf("Número de arestas incidentes no Vértice %d: %d\n\n",no,cont);
}

void verticesAdjacentesAdj(GrafoA *Ga,int no)
{
   if(no > Ga->V || no < 0)
   {
      printf("aresta fora do grafo\n\n");
      return;
   }

   printf("Vértices adjacentes ao vértice %d: ",no);
   NoA *aux = Ga->Adj[no];
   while (aux)
   {
      printf("%d ",aux->id);
      aux = aux->next;
   }
   printf(".\n\n");

}

int qtdArestasM(GrafoM *Gm)
{
   return Gm->E;
}

int qtdArestaAdj(GrafoA *Ga)
{
   return Ga->E;
}

/* */
int main () {

   int Va = 6; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);
   popularListaAdjcente(Ga);
   imprimirGrafoAdj(Ga);
   numeroArestasAdj(Ga,3);
   numeroSaidasAdj(Ga,4);
   numeroSaidasAdj(Ga,5);
   numeroSaidasAdj(Ga,2);
   verticesAdjacentesAdj(Ga,3);
   verticesAdjacentesAdj(Ga,4);
   verticesAdjacentesAdj(Ga,5);
   verticesAdjacentesAdj(Ga,30);
    
   int Vm = 6; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);
   inicializaMatriz(Gm);
   popularGrafoM(Gm);
   imprimirGrafoM(Gm);
   numeroArestasM(Gm,3);
   numeroSaidasM(Gm,4);
   numeroSaidasM(Gm,5);
   numeroSaidasM(Gm,2);
   verticesAdjacentesM(Gm,2);
   verticesAdjacentesM(Gm,3);
   verticesAdjacentesM(Gm,4);
   

   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}
