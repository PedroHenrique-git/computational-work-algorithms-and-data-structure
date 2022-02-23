#include "tipo-lista.h"

int buscaBinaria(Lista * lista , int n) {
    int min = 0, max = lista->totalDeElementos - 1, meio;

    while(min <= max) {
        meio = (min + max) / 2;

        if(lista->elementos[meio] == n) {
            return meio;
        } else {
            if(n < lista->elementos[meio]) {
                max = meio - 1;
            } else {
                min = meio + 1;
            }
        }
    }

    return -1;
}
