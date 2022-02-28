#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main(void)
{
    node* stack = initStack();
    int option, data, count;

    do
    {
        menu();

        printf("\nInsira sua opcao: ");
        scanf("%d", &option);

        switch (option)
        {
            case 0:
                // para a execucao do while
                break;
            case 1:
                // recebe o dado para empilhar
                fflush(stdin);
                printf("\nInsira o item: ");
                scanf("%d", &data);

                // empilha
                stack = stackUp(stack, data);
                break;
            case 2:
                if (emptyStack(stack))
                {
                    printf("\nA pilha ja esta vazia\n\n");
                    break;
                }
                // desempilha
                stack = pop(stack);
                break;
            case 3:
                if (emptyStack(stack))
                {
                    printf("\nA pilha ja esta vazia\n\n");
                    break;
                }
                // recebe a quantidade de elementos
                fflush(stdin);
                printf("\nInsira a quantidade de itens: ");
                scanf("%d", &count);
                // desempilha n elementos
                stack = countPop(stack, count);
                break;
            case 4:
                // printa o tamanho atual da pilha
                printf("\n\nO tamanho atual da pilha eh de %d itens\n\n", sizeStack(stack));
                break;
            case 5:
                // consulta o subtopo
                if (emptyStack(stack))
                {
                    printf("\nA pilha esta vazia\n\n");
                } else subTop(stack);
                break;
            case 6:
                // consulta a base da pilha
                if (emptyStack(stack))
                {
                    printf("\nA pilha esta vazia\n\n");
                } else printf("\nA base da pilha eh: %d\n\n", base(stack));
                break;
            case 7:
                // limpa a pilha
                if (emptyStack(stack))
                {
                    printf("\nA pilha ja esta vazia\n\n");
                    break;
                } else stack = freeStack(stack);

                if (emptyStack(stack)) printf("\nPilha limpa com sucesso\n\n");
                break;
            case 8:
                // printa a pilha
                if (emptyStack(stack))
                {
                    printf("\nA pilha esta vazia\n\n");
                } else printStack(stack);
                break;
            case 9:
                // verifica se a pilha está vazia
                if (emptyStack(stack))
                {
                    printf("\nA pilha esta vazia\n\n");
                } else printf("\nA pilha nao esta vazia\n\n");
                break;
            default:
                printf("\nOpcao invalida\n\n");
                break;
        }
    } while (option != 0);

    printf("Muito obrigado pelo uso");
}
