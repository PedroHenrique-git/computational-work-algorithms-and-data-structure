#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5

struct TLista {
    int elementos[MAX];
    int totalDeElementos;
    int estaOrdernada;
} typedef Lista;

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
       printf("\nA lista ja está cheia!!\n");
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
    int elementoASerInserido;
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
