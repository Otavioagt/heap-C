#include "heap.h"
#include <stdio.h>

int main() {
    tipo_heap heap;
    inicializaHeap(&heap);

    // Exemplo de uso
    tipo_dado_heap dado1 = {3, 'A'};
    tipo_dado_heap dado2 = {2, 'B'};
    tipo_dado_heap dado3 = {5, 'C'};

    insereHeap(&heap, dado1);
    insereHeap(&heap, dado2);
    insereHeap(&heap, dado3);

    printf("Removido: %c\n", removeHeap(&heap).dado); // Deve ser C
    printf("Removido: %c\n", removeHeap(&heap).dado); // Deve ser A
    printf("Removido: %c\n", removeHeap(&heap).dado); // Deve ser B

    return 0;
}
