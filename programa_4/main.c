#include <stdio.h>
#include <stdlib.h>

struct TNode {
    int elemento;
    struct TNode * next;
} typedef Node;

struct TFilaEncadeada {
    Node * head;
    int quantidadeDeElementos;
} typedef FilaEncadeada;

void inicializaFilaEncadeada(FilaEncadeada * filaEncadeada) {
    filaEncadeada->head = NULL;
    filaEncadeada->quantidadeDeElementos = 0;
}

void exibeFila(FilaEncadeada * filaEncadeada) {
    if(filaEncadeada->head == NULL) {
        printf("\nA fila esta vazia!!\n");
        return;
    }

    Node * current = filaEncadeada->head;
    int i = 0;
    for(i; i < filaEncadeada->quantidadeDeElementos && current != NULL; i++) {
        printf("\n Elemento [%d] da fila = %d\n", i + 1, current->elemento);
        current = current->next;
    }
}

void enqueue(int elemento, FilaEncadeada * filaEncadeada) {
    Node * node = (Node *) malloc(sizeof(Node));
    node->elemento = elemento;
    node->next = NULL;

    if(filaEncadeada->head == NULL) {
        filaEncadeada->head = node;
    } else {
        Node * current = filaEncadeada->head;

        while(current->next != NULL) {
            current = current->next;
        }

        current->next = node;
    }

    filaEncadeada->quantidadeDeElementos += 1;
}

int dequeue(FilaEncadeada * filaEncadeada) {    
    if(filaEncadeada->quantidadeDeElementos == 0) {
        filaEncadeada->head = NULL;
        printf("\nA lista esta vazia!!\n");
        return;
    }

    int value;
    Node * current = filaEncadeada->head;
    value = current->elemento;
    filaEncadeada->head = current->next;

    filaEncadeada->quantidadeDeElementos -= 1;
    printf("\nQuantidade de elementos %d\n", filaEncadeada->quantidadeDeElementos);
    return value;
}

int consulta(int elemento, FilaEncadeada * filaEncadeada) {
    int i = 0;
    Node * current = filaEncadeada->head;

    for(i; i < filaEncadeada->quantidadeDeElementos && current != NULL; i++) {
        printf("\n Elemento [%d] da fila = %d\n", i + 1, current->elemento);

        if(elemento == current->elemento) {
            return i;
        }

        current = current->next;
    }

    return -1;
}

int main()
{    
    FilaEncadeada * filaEncadeada = (FilaEncadeada *) malloc (sizeof(FilaEncadeada));
    int opcao, elementoASerInserido, elementoASerConsultado, elementoEncontrado;

    inicializaFilaEncadeada(filaEncadeada);

    do {
        printf("\n0 - Encerrar o programa\n1 - Exibir todos os elementos da fila\n2 - Operacao 'Enqueue'\n3 - Operacao 'Dequeue'\n4 - Operacao 'Consulta'\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando programa...");
            break;
            case 1:
                if(filaEncadeada->head == NULL) {
                    printf("\nFila vazia!!!\n");
                    break;
                }

                exibeFila(filaEncadeada);
            break;
            case 2:
                printf("\nDigite o elemento que voce deseja inserir: ");
                scanf("%d", &elementoASerInserido);
                enqueue(elementoASerInserido, filaEncadeada);
                printf("\nElemento inserido com sucesso..\n");
            break;
            case 3:
                if(filaEncadeada->head == NULL) {
                    printf("\nFila vazia!!!\n");
                    break;
                }

                printf("\nElemento %d removido com sucesso...\n", dequeue(filaEncadeada));
            break;
            case 4:
                if(filaEncadeada->head == NULL) {
                    printf("\nFila vazia!!!\n");
                    break;
                }

                printf("\n Digite o elemento que voce deseja encontrar: ");
                scanf("%d", &elementoASerConsultado);
                printf("\n");

                elementoEncontrado = consulta(elementoASerConsultado, filaEncadeada);

                if(elementoEncontrado == -1) {
                    printf("\nElemento nao encontrado...\n");
                } else {
                    printf("\nElemento encontrado no indice [%d]...\n", elementoEncontrado);
                }
            break;
        }
    } while(opcao != 0);

    free(filaEncadeada);
    return 0;
}
