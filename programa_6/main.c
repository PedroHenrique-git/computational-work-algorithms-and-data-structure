#include <stdio.h>
#include <stdlib.h>

struct TDoublyNode {
    int elemento;
    struct TDoublyNode * next;
    struct TDoublyNode * prev;
} typedef DoublyNode;

struct TListaDuplamenteEncadeada {
    DoublyNode * head;
    DoublyNode * tail;
    int quantidadeDeElementos;
} typedef ListaDuplamenteEncadeada;

void inicializaListaDuplamenteEncadeada(ListaDuplamenteEncadeada * listaDuplamenteEncadeada) {
   listaDuplamenteEncadeada->head = NULL;
   listaDuplamenteEncadeada->quantidadeDeElementos = 0;
}

void inserirElemento(ListaDuplamenteEncadeada * listaDuplamenteEncadeada, int elemento) {
    DoublyNode * doublyNode = (DoublyNode *) malloc(sizeof(DoublyNode));
    doublyNode->next = NULL;
    doublyNode->prev = NULL;
    doublyNode->elemento = elemento;

    if(listaDuplamenteEncadeada->head == NULL) {
        listaDuplamenteEncadeada->head = doublyNode;
        listaDuplamenteEncadeada->tail = doublyNode;
    } else {
        DoublyNode * current = listaDuplamenteEncadeada->head;
        DoublyNode * previous;


        while(current != NULL) {
            if(elemento > current->elemento) {
                previous = current;
                break;
            }

            current = current->next;
        }

        if(previous->prev == NULL) {
            previous = current;
            previous->next = doublyNode;
            doublyNode->prev = previous;
        } else {
            current = previous->next;
            doublyNode->next = current;
            previous->next = doublyNode;
            current->prev = doublyNode;
            doublyNode->prev = previous;
        }
    }

    listaDuplamenteEncadeada->quantidadeDeElementos += 1;
}

void exibeFila(ListaDuplamenteEncadeada * listaDuplamenteEncadeada) {
    DoublyNode * current  = listaDuplamenteEncadeada->head;

    int i = 0;
    for(i = 0; i < listaDuplamenteEncadeada->quantidadeDeElementos  && current != NULL; i++) {
        printf("\nNext values => %d\n", current->elemento);

        current = current->next;
    }

    int j = 0;
    for(j = 0; j < listaDuplamenteEncadeada->quantidadeDeElementos  && current != NULL; j++) {
        printf("\nPrevious values => %d\n", current->elemento);

        current = current->prev;
    }
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
                exibeFila(listaDuplamenteEncadeada);
            break;
            case 2:
                printf("\nDigite um elemento a ser inserido na lista: ");
                scanf("%d", &elementoASerInserido);
                inserirElemento(listaDuplamenteEncadeada, elementoASerInserido);
            break;
            case 3:
               
            break;
        }
    } while(opcao != 0);

    free(listaDuplamenteEncadeada);
    return 0;
}
