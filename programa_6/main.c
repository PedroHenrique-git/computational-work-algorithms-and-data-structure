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

void inserirElemento(ListaDuplamenteEncadeada * listaDuplamenteEncadeada, int elemento) {
    DoublyNode * node = ( DoublyNode * ) malloc(sizeof( DoublyNode ));
    node->elemento = elemento;
    node->next = NULL;
    node->prev = NULL;

    DoublyNode * current =  listaDuplamenteEncadeada->head;

    if(listaDuplamenteEncadeada->head == NULL) {
        listaDuplamenteEncadeada->head = node;
    } else if(elemento < listaDuplamenteEncadeada->head->elemento)  {
        node->next = current;
        current->prev = node;
        listaDuplamenteEncadeada->head = node;
    } else {
        DoublyNode * aux;

        while(current != NULL && elemento > current->elemento) {
            aux = current;
            current = current->next;
        }

        if(aux->next == NULL) {
            aux->next = node;
            node->prev = aux;
            return;
        }

        if(aux->next != NULL) {
            aux->next = node;
            node->prev = aux;
            node->next = current;
            current->prev = node;
            return;
        }
    }

    listaDuplamenteEncadeada->quantidadeDeElementos += 1;
}

void exibiElementos(ListaDuplamenteEncadeada * listaDuplamenteEncadeada) {
   DoublyNode * current =  listaDuplamenteEncadeada->head;

   while(current != NULL) {
        printf("\n %d \n", current->elemento);
        current = current->next;
   }

   printf("\nDe trás para frente\n");
   while(current != NULL) {
        printf("\n %d \n", current->elemento);
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
                exibiElementos(listaDuplamenteEncadeada);
            break;
            case 2:
                printf("\nDigite um elemento: ");
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