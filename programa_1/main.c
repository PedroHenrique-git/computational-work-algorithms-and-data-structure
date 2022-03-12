#include <stdio.h>
#include <stdlib.h>
#include "tipo-lista.h"
#include "bubble-sort.h"
#include "merge-sort.h"
#include "busca-binaria.h"

void inicializaLista (Lista * lista) {
    lista->totalDeElementos = 0;
    lista->estaOrdernada = 0;
    for(int i = 0; i < MAX; i++) {
        lista->elementos[i] = 0;
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
       printf("\nA lista ja esta cheia!!\n");
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

void remover(Lista * lista, int elemento) {
    const int totalDeElementos = lista->totalDeElementos;
    int indexDoElemento = buscaBinaria(lista, elemento);

    if( totalDeElementos == 0 ) {
        printf("\nA lista esta vazia!!\n\n");
        return;
    }

    if( indexDoElemento == -1 ) {
        printf("\nO elemento nao existe na lista!!\n\n");
        return;
    }

    if( totalDeElementos > 1 ) {
      for(int i = indexDoElemento + 1; i < totalDeElementos; i++) {
        lista->elementos[i - 1] = lista->elementos[i];
      }
    }

    lista->totalDeElementos = totalDeElementos - 1;
    lista->estaOrdernada = 0;
    printf("\nElemento removido!!\n");
}

int main()
{

    Lista * lista = (Lista *)malloc(sizeof(Lista));
    int elementoASerInserido, elementoASerBuscado, elementoASerRemovido;
    int opcao;

    inicializaLista(lista);

    do {
        printf("0 - Encerrar o programa\n1 - Exibir todos os elementos da lista\n2 - Inserir elemento no inicio lista\n3 - Ordenar lista (BubbleSort)\n4 - Remover elemento\n5 - Buscar elemento\n6 - Ordenar lista (MergeSort) \n");

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

                if(buscaBinaria(lista, elementoASerInserido) != -1) {
                    printf("\nO elemento ja existe na lista!!\n\n");
                    break;
                }

                inserir(lista, elementoASerInserido);
                printf("\n");
            break;
            case 3:
                bubbleSort(lista);
                printf("\nA lista foi ordenada corretamento!!\n\n");
            break;
            case 4:
                if( lista->estaOrdernada == 0 ) {
                    printf("\nVoce deve ordenar a lista para remover um elemento!!\n\n");
                    break;
                }

                printf("\nDigite o elemento a ser removido da lista: ");
                scanf("%d", &elementoASerRemovido);
                remover(lista, elementoASerRemovido);
                printf("\n");
            break;
            case 5:
                if(lista->totalDeElementos == 0) {
                    printf("\nA lista esta vazia \n\n");
                    break;
                }

                if(lista->estaOrdernada == 0) {
                    printf("\nA lista deve estar ordena para executar esta acao!!\n\n");
                } else {
                    printf("\nDigite o elemente que voce deseja pesquisar: ");
                    scanf("%d", &elementoASerBuscado);
                    int index = buscaBinaria(lista, elementoASerBuscado);
                    index == -1 ? printf("\n O elemento que voce pesquisou nao esta na lista\n\n") : printf("\n O elemento esta na posicao: [%d]\n\n", index);
                }
             break;
             case 6:
                mergeSort(lista);
                printf("\nA lista foi ordenada corretamento!!\n\n");
             break;
             default:
                printf("\nOpcao invalida!!\n\n");
             break;
        }
    } while(opcao != 0);

    free(lista);

    return 0;
}

