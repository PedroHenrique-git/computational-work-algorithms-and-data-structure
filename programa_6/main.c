#include <stdio.h>
#include <stdlib.h>
struct TDoublyNode {
    int elemento;
    struct TDoublyNode * next;
    struct TDoublyNode * prev;
} typedef DoublyNode;
struct TListaDuplamenteEncadeada {
    DoublyNode * head;
    int quantidadeDeElementos;
} typedef ListaDuplamenteEncadeada;

void inicializaListaDuplamenteEncadeada(ListaDuplamenteEncadeada * listaDuplamenteEncadeada) {
   listaDuplamenteEncadeada->head = NULL;
   listaDuplamenteEncadeada->quantidadeDeElementos = 0;
}

int main()
{    
    ListaDuplamenteEncadeada  * listaDuplamenteEncadeada = (ListaDuplamenteEncadeada *) malloc (sizeof(ListaDuplamenteEncadeada));
    int opcao, elementoASerInserido, elementoASerConsultado, elementoEncontrado;

    inicializaListaDuplamenteEncadeada(listaDuplamenteEncadeada);

    do {
        printf("\n0 - Encerrar o programa\n1 - Exibir todos os elementos da lista\n2 - Inserir elemento\n3 - Remover elemento\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando programa...");
            break;
            case 1:
                if(listaDuplamenteEncadeada->head == NULL) {
                    printf("\nFila vazia!!!\n");
                    break;
                }

                //exibeFila(filaEncadeada);
            break;
            case 2:
                printf("\nDigite o elemento que voce deseja inserir: ");
                scanf("%d", &elementoASerInserido);
                //enqueue(elementoASerInserido, filaEncadeada);
                printf("\nElemento inserido com sucesso..\n");
            break;
            case 3:
                /*
                if(filaEncadeada->head == NULL) {
                    printf("\nFila vazia!!!\n");
                    break;
                }
                */

                //printf("\nElemento %d removido com sucesso...\n", dequeue(filaEncadeada));
            break;
        }
    } while(opcao != 0);

    free(listaDuplamenteEncadeada);
    return 0;
}
