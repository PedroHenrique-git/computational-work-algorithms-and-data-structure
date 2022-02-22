#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 50

struct TLista {
    int elementos[MAX];
    int totalDeElementos;

} typedef Lista;

/** ALGORITMO DE BUSCA **/
int buscaElemento(int v[], int n) {
    int min = 0, max = MAX - 1, meio;

    while(min <= max) {
        meio = (min + max) / 2;

        if(v[meio] == n) {
            return meio;
        } else {
            if(n < v[meio]) {
                max = meio - 1;
            } else {
                min = meio + 1;
            }
        }
    }

    return -1;
}
/** FIM ALGORITMO DE BUSCA **/


/** ALGORITMO DE ORDENACAO O(n log2 n) **/
void mergeSort(int v[]) {
    mergeSortRec(0, MAX - 1, v, MAX);
}

void mergeSortRec(int esq, int dir, int v[], int dimensao) {
    if( esq < dir ) {
        printf("(%d, %d) \n", esq, dir);
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
/** FIM ALGORITMO DE ORDENACAO O(n log2 n) **/

/** ALGORITMO DE ORDENACAO O(n^2) **/
void bubbleSort(int v[]) {
    int trocou = 1, aux = 0;

    while(trocou == 1) {
        trocou = 0;
        for(int i = 1; i < MAX; i++) {
            if(v[i] < v[i - 1]) {
                aux = v[i];
                v[i] = v[i - 1];
                v[i - 1] = aux;
                trocou = 1;
            }
        }
    }
}
/** FIM DE ORDENACAO O(n^2) **/


void inicializaLista (Lista * lista) {
    for(int i = 0; i < MAX; i++) {
        lista->elementos[i] = i;
    }
}


void mostrarLista (Lista * lista) {
    printf("\n");

    for(int i = 0; i < MAX; i++) {
        printf("Elemento %d da lista: %d\n", i + 1, lista->elementos[i]);
    }

    printf("\n");
}

void inserir(Lista * lista) {}

int main()
{
    Lista * lista = (Lista *) malloc(sizeof(Lista));
    int elementoASerInserido;
    int opcao;
 
    inicializaLista(lista);

    do {
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando programa...");
            break;
            case 1:
                mostrarLista(lista);
            break;
             case 2:
                printf("\nDigite o elemento a ser inserido na lista: ");
                scanf("%d", &elementoASerInserido);
                inserir(lista);
                printf("\n");
            break;
             case 3:
                printf("opcao 3");
            break;
             case 4:
                printf("opcao 4");
            break;
             case 5:
                printf("opcao 5");
            break;
             case 6:
                printf("opcao 6");
            break;
        }
    } while(opcao != 0);

    getch();
    free(lista);

    return 0;
}
