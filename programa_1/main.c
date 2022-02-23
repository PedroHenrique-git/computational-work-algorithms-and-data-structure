#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define MAX 5

struct TLista {
    int elementos[MAX];
    int totalDeElementos;
    int estaOrdernada;
} typedef Lista;

int buscaBinaria(Lista *, int );
void mergeSort(Lista *);
void mergeSortRec(int , int , int [], int);
void junta(int, int, int, int, int [], int);
void bubbleSort(int []);

void inicializaLista (Lista * lista) {
    lista->totalDeElementos = 0;
    lista->estaOrdernada = 0;
    for(int i = 0; i < MAX; i++) {
        lista->elementos[i] = -1;
    }
}

void mostrarLista (Lista * lista) {
    const int totalDeElementos = lista->totalDeElementos;

    if(totalDeElementos == 0) {
        printf("\nA lista esta vazia!!\n\n");
        return;
    }

    printf("\n");
    for(int i = 0; i < totalDeElementos; i++) {
        printf("Elemento %d da lista: %d\n", i + 1, lista->elementos[i]);
    }
    printf("\n");
}

void inserir(Lista * lista, int elemento) {
    const int totalDeElementos = lista->totalDeElementos;

    if( totalDeElementos == MAX ) {
       printf("\nA lista ja est� cheia!!\n");
       return;
    }

    if( totalDeElementos == 0 ) {
        lista->elementos[0] = elemento;
    } else {
        for(int i = MAX; i >= 0; i--) {
            lista->elementos[i] = lista->elementos[i - 1];
        }
        lista->elementos[0] = elemento;
    }

    lista->totalDeElementos = totalDeElementos + 1;
    lista->estaOrdernada = 0;
}

int main()
{

    Lista * lista = (Lista *)malloc(sizeof(Lista));
    int elementoASerInserido, elementoASerBuscado;
    int opcao;
 
    inicializaLista(lista);

    do {
        printf("0 - Encerrar o programa\n1 - Exibir todos os elementos da lista\n2 - Inserir elemento no inicio lista\n4 - Remover elemento\n5 - Buscar elemento\n6 - Ordenar lista\n");

        printf("\nDigite a opcao desejada: ");
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
                inserir(lista, elementoASerInserido);
                printf("\n");
            break;
             case 3:
                printf("opcao 3");
            break;
             case 4:
                printf("opcao 4");
            break;
             case 5:
                if(lista->totalDeElementos == 0) {
                    printf("\nA lista esta vazia \n\n");
                    break;
                }

                if(lista->estaOrdernada == 0) {
                    printf("\nA lista deve estar ordena para executar esta acao\n\n");
                } else {
                    printf("\nDigite o elemente que voce deseja pesquisar: ");
                    scanf("%d", &elementoASerBuscado);
                    int index = buscaBinaria(lista, elementoASerBuscado);
                    index == -1 ? printf("\n O elemento que voce pesquisou nao esta na lista\n\n") : printf("\n O elemento esta na posicao: [%d]\n\n", index);
                }
            break;
             case 6:
                mergeSort(lista);
                printf("\nA lista for ordenada corretamento\n\n");
            break;
        }
    } while(opcao != 0);

    //getch();
    free(lista);

    return 0;
}

/** ALGORITMO DE BUSCA **/
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


/** ALGORITMO DE ORDENACAO O(n log2 n) **/
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
