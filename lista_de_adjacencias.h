//
// Created by joaomarcus on 22/04/2021.
//

#ifndef GRAFOS_IFCE_LISTA_DE_ADJACENCIAS_H
#define GRAFOS_IFCE_LISTA_DE_ADJACENCIAS_H

/* */
typedef struct nodo {
    int valor;
    struct nodo *proximo;
} nodo;

/* O grafo é representado por uma lista de adjacências */
typedef struct grafo {
    int numero_de_vertice;
    int numero_de_aresta;
    nodo **lista_adjacencia; // ponteiro pra o vetor de listas de adjacencias, array de nodos do tamanho do número de vértices
} grafo;


/* Cria um grafo vazio. Importante notar que a lista de adjacencia tem cabeça. */
grafo *cria_grafo() {
    grafo *grafo = malloc(sizeof(*grafo));

    grafo->numero_de_vertice = 0;
    grafo->numero_de_aresta = 0;
    grafo->lista_adjacencia = (nodo**)malloc(sizeof(nodo**)); // inicia-se apenas com uma posição

    return grafo;
}

/* Retorna 0 se o vértice não existe, caso contrário 1 */
int verifica_se_vertice_existe(grafo *grafo, int valor) {
    for(int i = 0; i < grafo->numero_de_vertice; i++){
        if(grafo->lista_adjacencia[i]->valor == valor)
            return 1;
    }
    return 0;
}

/* Adiciona um vértice no grafo */
void adiciona_vertice(grafo *grafo, int valor) {
    nodo *novo_vertice = malloc(sizeof(nodo*));
    novo_vertice->valor = valor;
    novo_vertice->proximo = NULL;

    // Não podemos adicionar um vértice que já existe
    int vertice_existe = verifica_se_vertice_existe(grafo, valor);

    if(vertice_existe) {
        printf("O vértice %d já existe.\n", valor);
        return ;
    }

    grafo->numero_de_vertice++;
    grafo->lista_adjacencia = realloc(grafo->lista_adjacencia, sizeof(nodo**)*(grafo->numero_de_vertice));
    grafo->lista_adjacencia[grafo->numero_de_vertice - 1] = novo_vertice;
}

/**/
void adiciona_nodo_ao_vertice(nodo *no, int valor) {
    nodo *novo_nodo = malloc(sizeof(nodo));
    novo_nodo->valor = valor;

    novo_nodo->proximo = no->proximo;
    no->proximo = novo_nodo;
}

/**/
void adiciona_aresta(grafo *grafo, int valor_vertice_1, int valor_vertice_2) {
    // Verifica existência dos vértices
    if(!verifica_se_vertice_existe(grafo, valor_vertice_1)) {
        printf("O vértice %d não existe.\n", valor_vertice_1);
        return ;
    }

    if(!verifica_se_vertice_existe(grafo, valor_vertice_2)) {
        printf("O vértice %d não existe.\n", valor_vertice_2);
        return ;
    }

    //Verifica existência da aresta
    // TODO: verificar se a aresta já existe

    grafo->numero_de_aresta++;
    for(int i = 0; i < grafo->numero_de_vertice; i++){
        if(grafo->lista_adjacencia[i]->valor == valor_vertice_1)
            adiciona_nodo_ao_vertice(grafo->lista_adjacencia[i], valor_vertice_2);
        if(grafo->lista_adjacencia[i]->valor == valor_vertice_2)
            adiciona_nodo_ao_vertice(grafo->lista_adjacencia[i], valor_vertice_1);
    }
}

/**/
void remove_aresta(grafo *grafo, int valor_vertice_1, int valor_vertice_2) {
    // Verifica existência dos vértices
    if(!verifica_se_vertice_existe(grafo, valor_vertice_1)) {
        printf("O vértice %d não existe.\n", valor_vertice_1);
        return ;
    }

    if(!verifica_se_vertice_existe(grafo, valor_vertice_2)) {
        printf("O vértice %d não existe.\n", valor_vertice_2);
        return ;
    }

    //Verifica existência da aresta
    // TODO: verificar se a aresta já existe

    for(int i = 0; i < grafo->numero_de_vertice; i++){
        if(grafo->lista_adjacencia[i]->valor == valor_vertice_1) {
            nodo *nodo1 = grafo->lista_adjacencia[i];
            nodo *nodo2;

            while (nodo1 != NULL && nodo1->valor != valor_vertice_2){
                nodo2 = nodo1;
                nodo1 = nodo1->proximo;

            }

            if (nodo1 != NULL){
                nodo2->proximo = nodo1->proximo;
                free(nodo1);
            }
        }

        if(grafo->lista_adjacencia[i]->valor == valor_vertice_2) {
            nodo *nodo1 = grafo->lista_adjacencia[i];
            nodo *nodo2;

            while (nodo1 != NULL && nodo1->valor != valor_vertice_1){
                nodo2 = nodo1;
                nodo1 = nodo1->proximo;

            }

            if (nodo1 != NULL){
                nodo2->proximo = nodo1->proximo;
                free(nodo1);
            }
        }


    }
}

void imprime_vertices(grafo *grafo) {
    for(int i = 0; i < grafo->numero_de_vertice; i++){
        printf("%d\n", grafo->lista_adjacencia[i]->valor);
    }
}

void imprime_grafo(grafo *grafo) {
    for(int i = 0; i < grafo->numero_de_vertice; i++){
        for (nodo *nodo = grafo->lista_adjacencia[i]; nodo != NULL; nodo = nodo->proximo){
            printf("%d -> ", nodo->valor);
        }
        printf("\n");
    }
}

/* Recebe um grafo G com n vértices, representado através de um LA. Se o grafo for conexo
 * devolve 1; caso contrário, devolve 0 */
int conexo(grafo G, int i) {

    return 0;
}

#endif //GRAFOS_IFCE_LISTA_DE_ADJACENCIAS_H
