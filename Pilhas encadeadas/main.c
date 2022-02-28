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
                // desempilha
                stack = pop(stack);
                break;
            case 3:
                // recebe a quantidade de elementos
                fflush(stdin);
                printf("\nInsira a quantidade de itens");
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
                subTop(stack);
                break;
            case 6:
                // consulta a base da pilha
                printf("\nA base da pilha eh: %d\n\n", base(stack));
                break;
            case 7:
                // limpa a pilha
                if (emptyStack(stack))
                {
                    break;
                } else stack = freeStack(stack);
                break;
            case 8:
                // printa a pilha
                if (emptyStack(stack))
                {
                    break;
                } else printStack(stack);
                break;
            case 9:
                // verifica se a pilha está vazia
                emptyStack(stack);
                break;
            default:
                printf("\nOpcao invalida\n\n");
                break;
        }
    } while (option != 0);

    printf("Muito obrigado pelo uso");
}
