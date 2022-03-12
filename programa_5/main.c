#include <stdio.h>
#include <stdlib.h>

struct TNode {
    int valor;
    struct TNode * next;
} typedef Node;

struct TLista {
    Node * tail;
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
    Node * node = lista->head;
    Node * temp = lista->head;

    for(; node != temp; node = node->next) {
        if(node->valor == elemento) return 1;
    }

    return 0;
}

void mostrarLista(Lista * lista) {
    if(lista->head == NULL) {
        printf("\nA lista esta vazia!\n\n");
        return;
    }

    int i = 0;
    Node * node = lista->head;
    Node * temp = lista->head;

    for(; node != temp; node = node->next) {
        printf("\nelemento %d da lista: %d", i, node->valor);
        i++;
    }

    printf("\n\n");
}

void inserirElemento(Lista * lista, int elemento) {
    Node * node = criarNode(elemento);

    if(lista->head == NULL) {
        lista->head = node;
        lista->head->next = lista->head;
        return;
    }

    Node * currentNode = lista->head;
    Node * temp = lista->head;

    while(currentNode != temp) {
        currentNode = currentNode->next;
    }

    currentNode->next = node;
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
