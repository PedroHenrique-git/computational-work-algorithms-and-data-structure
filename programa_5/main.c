#include <stdio.h>
#include <stdlib.h>

struct TNode {
    int valor;
    struct TNode * next;
} typedef Node;

struct TLista {
    Node * head;
} typedef Lista;

Lista * criarLista() {
    Lista * lista = (Lista *)malloc(sizeof(Lista));
    lista->head = NULL;
    return lista;
}

Node * criarNode(int elemento) {
    Node * node = (Node *)malloc(sizeof(Node));
    node->valor = elemento;
    node->next = NULL;
    return node;
}

int verificaSeElementoJaExiste(Lista * lista, int elemento) {
    if(lista->head == NULL) {
     //printf("HEAD --> %d", lista->head->next->valor);
     return 0;
    }

    Node * current = lista->head;

    while(current->next != lista->head) {
        if(current->valor == elemento) return 1;
        current = current->next;
    }

    return 0;
}

Node * inserirElemento(Lista * lista, int elemento) {
    Node * novoNoh = criarNode(elemento);
    Node * current = lista->head;

    if(lista->head == NULL) {
        novoNoh->next = novoNoh;
        lista->head = novoNoh;
    } else if(current->valor >= novoNoh->valor) {
        while(current->next != lista->head)
            current = current->next;

        current->next = novoNoh;
        novoNoh->next = lista->head;
        lista->head = novoNoh;
    } else {
        while(current->next != lista->head && current->next->valor < novoNoh->valor)
            current = current->next;

        novoNoh->next = current->next;
        current->next = novoNoh;
    }

    return lista->head;
}

void mostrarLista(Lista * lista) {
    if(lista->head == NULL) {
        printf("\nA lista esta vazia!\n\n");
        return;
    }

    int i = 0;
    Node * node = lista->head;

    while(node->next != lista->head) {
        printf("\nelemento %d da lista: %d", i, node->valor);
        node = node->next;
        i++;
    }

    printf("\nelemento %d da lista: %d", i, node->valor);

    printf("\n\n");
}

int main()
{
    int opcao, elemento;
    Lista * lista = criarLista();

    do {
        printf("0 - Encerrar o programa\n1 - Exibir todos os elementos da lista\n2 - Inserir elemento\n3 - Remover elemento\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("\nEncerrando programa...\n\n");
            break;
            case 1:
                mostrarLista(lista);
            break;
            case 2:
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &elemento);

                if(verificaSeElementoJaExiste(lista, elemento)) {
                    printf("\nElemento ja existe na lista!\n\n");
                    break;
                }

                inserirElemento(lista, elemento);
                printf("\n");
            break;
            case 3:
            break;
            default:
                printf("\nOpcao invalida!\n\n");
        }
    } while(opcao != 0);

    free(lista);
}
