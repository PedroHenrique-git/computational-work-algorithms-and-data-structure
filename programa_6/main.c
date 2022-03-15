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

int verificaSeElementoJaExiste(ListaDuplamenteEncadeada * listaDuplamenteEncadeada, int elemento) {
    DoublyNode * current =  listaDuplamenteEncadeada->head;

    while(current != NULL) {
        if(current->elemento == elemento) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

void inserirElemento(ListaDuplamenteEncadeada * listaDuplamenteEncadeada, int elemento) {
    
    if(verificaSeElementoJaExiste(listaDuplamenteEncadeada, elemento) == 1) {
        printf("\nEsse elemento ja esta na lista\n");
        return;
    }

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
    int i = 0;

    while(current != NULL) {
        printf("\n Elemento [%d] => %d \n", i, current->elemento);
        i++;
        current = current->next;
    }
}

int removerElemento(ListaDuplamenteEncadeada * listaDuplamenteEncadeada, int elemento) {
    DoublyNode * current =  listaDuplamenteEncadeada->head;
    int elementoRemovido;

    if( verificaSeElementoJaExiste(listaDuplamenteEncadeada, elemento) == 0 ) {
        printf("\n Esse elemento nao esta na lista \n");
        return -1;
    }

    if(current->elemento == elemento && current->next == NULL) {
        listaDuplamenteEncadeada->head = NULL;
        free(current);
    } else if(current->elemento == elemento) {
        current->next->prev = NULL;
        listaDuplamenteEncadeada->head = current->next; 
        free(current);
    } else {
        while(current != NULL && current->elemento != elemento) {
            current = current->next;
        }

        if(current->next == NULL) {
            current->prev->next = NULL;
            free(current);
            return 1;
        }

        if (current->next != NULL) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return 1;
        }

    }

    return 1;
}

int main()
{
    ListaDuplamenteEncadeada  * listaDuplamenteEncadeada = (ListaDuplamenteEncadeada *) malloc (sizeof(ListaDuplamenteEncadeada));
    int opcao, elementoASerInserido, elementoASerRemovido;

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
                    printf("\nA lista esta vazia!!\n");
                    break;
                }

                exibiElementos(listaDuplamenteEncadeada);
            break;
            case 2:
                printf("\nDigite um elemento: ");
                scanf("%d", &elementoASerInserido);
                inserirElemento(listaDuplamenteEncadeada, elementoASerInserido);
            break;
            case 3:
                if(listaDuplamenteEncadeada->head == NULL) {
                    printf("\nA lista ja esta vazia!!\n");
                    break;
                }

                printf("\nDigite o elemento que voce quer remover: ");
                scanf("%d", &elementoASerRemovido);
                int result = removerElemento(listaDuplamenteEncadeada, elementoASerRemovido);
                
                if(result == 1) {
                    printf("\n Elemento removido com sucesso... \n");
                } else {
                    printf("\n Erro ao remover elemento... \n");
                }
            
            break;
        }
    } while(opcao != 0);

    free(listaDuplamenteEncadeada);
    return 0;
}