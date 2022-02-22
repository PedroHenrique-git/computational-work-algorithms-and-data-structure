#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 50

struct TLista {
    int elementos[MAX];
    int totalDeElementos;

} typedef Lista;

void inicializaLista (Lista * lista) {
    for(int i = 0; i < MAX; i++) {
        lista->elementos[i] = -1;
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
    Lista lista;
    int elementoASerInserido;
    int opcao;

    inicializaLista(&lista);

    do {
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando programa...");
            break;
            case 1:
                mostrarLista(&lista);
            break;
             case 2:
                printf("\nDigite o elemento a ser inserido na lista: ");
                scanf("%d", &elementoASerInserido);
                inserir(&lista);
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
    return 0;
}
