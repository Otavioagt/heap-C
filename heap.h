#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>

#define TAM_HEAP 20

// Definir a estrutura de armazenamento
struct est_dado_heap {
    int prioridade;
    char dado;
};
typedef struct est_dado_heap tipo_dado_heap;

// Definir a estrutura que representa a tabela heap
struct est_heap{
    int qtd;
    tipo_dado_heap heap[TAM_HEAP];
};
typedef struct est_heap tipo_heap;

// Protótipos de funções
void inicializaHeap(tipo_heap*);
int filhoEsqHeap(int);
int filhoDirHeap(int);
int paiHeap(int);
void sobeHeap(tipo_heap*, int);
void desceHeap(tipo_heap*, int);
void insereHeap(tipo_heap*, tipo_dado_heap);
tipo_dado_heap removeHeap(tipo_heap*);

#endif 
