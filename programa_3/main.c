#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "pilha.h"

void inicializaPilha(Pilha * pilha) {
    int i = 0; 

    pilha->quantidadeDeElementos = 0;
    for(i; i < MAX; i++) {
        pilha->elementos[i] = 0;
    }
}

void push(int elemento, Pilha * pilha) {
    pilha->elementos[pilha->quantidadeDeElementos] = elemento;
    pilha->quantidadeDeElementos += 1;
}

int pop(Pilha * pilha) {
    if(pilha->quantidadeDeElementos == 0) {
        return -1;
    }

    int elemento = pilha->elementos[pilha->quantidadeDeElementos - 1];
    pilha->elementos[pilha->quantidadeDeElementos - 1] = 0;
    pilha->quantidadeDeElementos -= 1;
    return elemento;
}

int consulta(Pilha *pilha) {
    if(pilha->quantidadeDeElementos == 0) {
        return -1;
    }

    return pilha->elementos[pilha->quantidadeDeElementos - 1];
}

void exibePilha(Pilha *pilha) {
    int i = 0;
    
    if(pilha->quantidadeDeElementos == 0) {
        printf("\nA pilha esta vazia!!\n");
        return;
    }

    for(i; i < pilha->quantidadeDeElementos; i++) {
        printf("\nElemento [%d]: %d\n", i, pilha->elementos[i]);
    }
}

int main()
{
    Pilha * pilha = (Pilha *)malloc(sizeof(Pilha));
    int opcao, elementoASerInserido, elementoRemovido, topoDaPilha;

    inicializaPilha(pilha);

    do {
        printf("\n0 - Encerrar o programa\n1 - Exibir todos os elementos da pilha\n2 - Operacao 'Push'\n3 - Operacao 'Pop'\n4 - Operacao 'Consulta'\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando programa...");
            break;
            case 1:
                exibePilha(pilha);
                printf("\n");
            break;
            case 2:
                if(pilha->quantidadeDeElementos == MAX) {
                    printf("\nA pilha ja esta cheia!!!\n");
                    break;
                }

                printf("\nDigite o elemento que voce deseja inserir: ");
                scanf("%d", &elementoASerInserido);
                push(elementoASerInserido, pilha);
                printf("\nElemento inserido com sucesso...\n\n");
            break;
            case 3:
                elementoRemovido = pop(pilha);

                if(elementoRemovido == -1) {
                    printf("\n A pilha já esta vazia!!!\n");
                } else {
                    printf("\nElemento %d removido do topo com sucesso...\n\n", elementoRemovido);
                }
            break;
            case 4:
                topoDaPilha = consulta(pilha);

                if(topoDaPilha == -1) {
                    printf("\n A pilha esta vazia!!!\n");
                } else {
                    printf("\nElemento no topo da pilha: %d\n", consulta(pilha));
                }
            break;
        }
    } while(opcao != 0);
    
    free(pilha);
    return 0;
}
