#include "tipo-lista.h"

void bubbleSort(Lista *);

void bubbleSort(Lista * lista) {
    int trocou = 1, aux = 0;

    while(trocou == 1) {
        trocou = 0;
        for(int i = 1; i < lista->totalDeElementos; i++) {
            if(lista->elementos[i] < lista->elementos[i - 1]) {
                aux = lista->elementos[i];
                lista->elementos[i] = lista->elementos[i - 1];
                lista->elementos[i - 1] = aux;
                trocou = 1;
            }
        }
    }
}
