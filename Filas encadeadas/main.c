// gcc main.c filaEnc.c -o main 
#include <stdio.h>
#include <stdlib.h>
#include "filaEnc.h"

//============PROTOTIPOS===========//
int menu(node* queue);
int switchOpt(int opt, node* queue);
//============PROTOTYPES============//

int main(void)
{
    node* queue;

    startQueue(&queue);

    menu(queue);
}

int menu(node* queue)
{
    int opt;

    printf(
        "\n\tMENU\n"
        "[1] -- enfileira\n"
        "[2] -- desenfileira\n"
        "[3] -- desenfileira totalmente\n"
        "[4] -- verifica se a fila esta vazia\n"
        "[5] -- compara duas filas\n"
        "[6] -- copia a fila\n"
        "[7] -- tamanho da fila\n"
        "[8] -- printa a fila\n"
        "[0] -- mostra o menu\n"
        "[-1] -- para a execucao do programa\n"
        "\n"
        );

    printf("\nEscolha sua opcao: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case -1:
        exit(0);
    case 0:
        return menu(queue);
        break;
    default:
        return switchOpt(opt, queue);
        break;
    }
}

int switchOpt(int opt, node* queue)
{
    int data, exec;

    switch (opt)
    {
    case 1:
        printf("Insira o dado: ");
        scanf("%d", &data);

        enqueue(&queue, data);
        printQueue(queue);
        break;

    case 2:
        if (emptyQueue(queue))
        {
            printf("A fila esta vazia!\n");
        } else {
            dequeue(&queue);
            emptyQueue(queue) ? printf("A fila foi esvaziada\n") : printQueue(queue);
        }
        break;

    case 3:
        if (emptyQueue(queue))
        {
            printf("A fila esta vazia!\n");
        } else {
            totalDequeue(&queue);
            emptyQueue(queue) ? printf("Fila esvaziada co sucesso\n") : printf("Algo ocorreu mal\n");
        }
        break;

    case 4:
        if (emptyQueue(queue))
        {
            printf("A fila esta vazia!\n");
        } else printf("A fila nao esta vazia\n");

        break;
    
    case 5:
        printf("Eu nao posso fazer isso por voce, mas pode testar ess funcionalidade usando a funcao: queueCmp\n");
        break;
    case 6:
        printf("Eu nao posso fazer isso por voce, mas pode testar ess funcionalidade usando a funcao: queueCpy\n");
        break;
    case 7:
        printf("A fila possui %d itens\n", sizeOfQueue(queue));
        break;
    case 8: 
        printQueue(queue);
        break;
    default:
        printf("Opcao INVALIDA!!!\n Tente novamente\n");
        return menu(queue);
        break;
    }

    return menu(queue);
}