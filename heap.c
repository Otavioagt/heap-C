#include "heap.h"
#include <stdio.h>

void inicializaHeap(tipo_heap *heap) {
    heap->qtd = 0;
}


int filhoEsqHeap(int indice) {
    return 2 * indice + 1;
}


int filhoDirHeap(int indice) {
    return 2 * indice + 2;
}


int paiHeap(int indice) {
    return (indice - 1) / 2;
}


void sobeHeap(tipo_heap *heap, int indice) {
    tipo_dado_heap temp;
    int pai;

    while (indice > 0) {
        pai = paiHeap(indice);
        if (heap->heap[pai].prioridade > heap->heap[indice].prioridade) {
            temp = heap->heap[pai];
            heap->heap[pai] = heap->heap[indice];
            heap->heap[indice] = temp;
            indice = pai;
        } else {
            break;
        }
    }
}


void desceHeap(tipo_heap *heap, int indice) {
    tipo_dado_heap temp;
    int filho_esq, filho_dir, filho_menor;

    while (1) {
        filho_esq = filhoEsqHeap(indice);
        filho_dir = filhoDirHeap(indice);
        filho_menor = indice;

        if (filho_esq < heap->qtd && heap->heap[filho_esq].prioridade < heap->heap[filho_menor].prioridade) {
            filho_menor = filho_esq;
        }

        if (filho_dir < heap->qtd && heap->heap[filho_dir].prioridade < heap->heap[filho_menor].prioridade) {
            filho_menor = filho_dir;
        }

        if (filho_menor != indice) {
            temp = heap->heap[indice];
            heap->heap[indice] = heap->heap[filho_menor];
            heap->heap[filho_menor] = temp;
            indice = filho_menor;
        } else {
            break;
        }
    }
}


void insereHeap(tipo_heap *heap, tipo_dado_heap dado) {
    if (heap->qtd < TAM_HEAP) {
        heap->heap[heap->qtd] = dado;
        sobeHeap(heap, heap->qtd);
        heap->qtd++;
    } else {
        printf("Heap cheia, impossível inserir.\n");
    }
}


tipo_dado_heap removeHeap(tipo_heap *heap) {
    tipo_dado_heap temp;
    if (heap->qtd > 0) {
        temp = heap->heap[0];
        heap->qtd--;
        heap->heap[0] = heap->heap[heap->qtd];
        desceHeap(heap, 0);
        return temp;
    } else {
        printf("Heap vazia, impossível remover.\n");
        return temp; 
    }
}
