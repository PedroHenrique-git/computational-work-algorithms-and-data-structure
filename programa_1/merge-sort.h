#include "tipo-lista.h"

void mergeSort(Lista * lista) {
    mergeSortRec(0, lista->totalDeElementos - 1, lista->elementos, lista->totalDeElementos);
    lista->estaOrdernada = 1;
}

void mergeSortRec(int esq, int dir, int v[], int dimensao) {
    if( esq < dir ) {
        int meio1 = (esq + dir) / 2;
        int meio2 = meio1 + 1;
        mergeSortRec(esq, meio1, v, dimensao);
        mergeSortRec(meio2, dir, v,  dimensao);
        junta(esq, meio1, meio2, dir, v, dimensao);
    } else {
        return;
    }
}

void junta(int esq, int meio1, int meio2, int dir, int v[], int dimensao) {
    int combinacao[dimensao];

    int indEsq = esq;
    int indDir = meio2;
    int indComb = esq;

    for(int k = esq; k <= dir; k++) {
        combinacao[k] = v[k];
    }

    while(indEsq <= meio1 && indDir <= dir) {
        if ( combinacao[indEsq] <= combinacao[indDir]) {
            v[indComb] = combinacao[indEsq];
            indEsq++;
        } else {
            v[indComb] = combinacao[indDir];
            indDir++;
        }
         indComb++;
    }

    while(indEsq <= meio1) {
        v[indComb] = combinacao[indEsq];

        indEsq++;
        indComb++;
    }

    while(indDir <= dir) {
        v[indComb] = combinacao[indDir];

        indDir++;
        indComb++;
    }
}
