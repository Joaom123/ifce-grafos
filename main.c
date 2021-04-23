#include <stdio.h>
#include <stdlib.h>
#include "lista_de_adjacencias.h"


int main() {
    grafo *grafo = cria_grafo();
    adiciona_vertice(grafo, 1);
    adiciona_vertice(grafo, 2);
    adiciona_vertice(grafo, 3);
    adiciona_vertice(grafo, 9);

    adiciona_aresta(grafo, 2, 3);
    adiciona_aresta(grafo, 1, 3);
    imprime_grafo(grafo);

    printf("--------------------------------------\n");

    remove_aresta(grafo, 1, 3);
    imprime_grafo(grafo);

    return 0;
}
