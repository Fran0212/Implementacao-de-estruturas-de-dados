#include <stdio.h>
#include <stdlib.h>
#include "filaEnc.h"

void startQueue(node** queue)
{
    // espaco de memoria é esvaziado
    /*---------------------------*/
    // memory space is emptied
    *queue = NULL;
}

int emptyQueue(node* queue)
{
    // verifica se a fila esta vazia
    /*----------------------------*/
    // verifies that the queue is empty
    return queue == NULL;
}

int enqueue(node** queue, int data)
{
    // declaracao do novo item
    /*-----------------------*/
    // Declaration of the new item
    node* new = (node*)malloc(sizeof(node));

    // declaracao do auxiliar de enfileiramento
    /*---------------------------------------*/
    // Declaration of enqueue assistant
    node* aux = *queue;

    // atribuicao de valores
    /*--------------------*/
    // value attribution
    new->data = data;
    new->next = NULL;

    // se a fila estiver vazia...
    /*-------------------------*/
    // If the queue is empty ...
    if (emptyQueue(aux))
    {
        // a fila original recebe a nova celula
        /*-----------------------------------*/
        // The original queue receives the new cell
        *queue = new;
    }
    // caso contrario...
    /*----------------*/
    // otherwise...
    else
    {       
        // enquanto o proximo não for nulo...
        /*------------------------------*/
        // while the next is not null...
        while (aux->next != NULL)
        {
            // o atual recebe o proximo valor
            /*-----------------------------*/
            // The current one receives the next value
            aux = aux->next;
        }
        // o proximo item recebe o novo valor
        /*---------------------------------*/
        // The next item receives the new value
        aux->next = new;
    }
}

int dequeue(node** queue)
{
    // se a fila estiver vazia retorna 0
    /*--------------------------------*/
    // If the queue is empty returns 0
    if (emptyQueue(*queue)) return 0;

    // declaracao do auxiliar de desenfileiramento
    /*---------------------------------------*/
    // Declaration of dequeue assistant
    node* aux;

    // auxiliar recebe a celula atual da fila
    /*-------------------------------------*/
    // auxiliary receives the current cell of the queue
    aux = *queue;

    // celula atual recebe a proxima
    /*----------------------------*/
    // Current cell receives the next
    *queue = (*queue)->next;

    // limpa o espaco de memoria do auxiliar
    /*------------------------------------*/
    // Clears the auxiliary memory space
    free(aux);
}

void printQueue(node* queue)
{
    // enquanto a celula não for vazia...
    /*---------------------------------*/
    // While the cell is not empty ...
    while (queue != NULL)
    {
        // imprime o dado da celula atual e ...
        /*----------------------------------*/
        // Prints the current cell data and ...
        printf("{%d} <- ", queue->data);

        // celula atual recebe o valor da proxima
        /*-------------------------------------*/
        // Current cell receives the value of the next
        queue = queue->next;
    }

    // imprime "NULL" para demonstrar o vazio
    /*-------------------------------------*/
    // Prints "NULL" to demonstrate the emptiness
    printf("NULL\n");
}


int sizeOfQueue(node* queue)
{
    // declaracao do contador
    /*---------------------*/
    // Accountant's statement
    int cont = 0;

    // enquanto a fila nao for vazia...
    /*-------------------------------*/
    // While the queue is not empty ...
    while (queue != NULL)
    {
        // fila eh atualizada
        /*-----------------*/
        // queue is refreshed
        queue = queue->next;

        // contador eh incrementado
        /*-----------------------*/
        // Increasing the counter
        cont++;
    }

    // retorna o contador
    /*-----------------*/
    // Returns the counter
    return cont;
}

int totalDequeue(node** queue)
{
    // se a fila ja estiver vazia retorna 0
    /*-----------------------------------*/
    // If the queue is already empty Returns 0
    if (emptyQueue(*queue)) return 0;

    // enquanto a fila nao for nula...
    /*------------------------------*/
    // enquanto a fila nao for nula...
    while ((*queue) != NULL)
    {
        // a celula atual recebe o valor da proxima
        /*---------------------------------------*/
        // Current cell receives the value of the next
        *queue = (*queue)->next;
    }

    return 1;
}


int queueCmp(node* queueOne, node* queueTwo)
{
    // se os tamanhos foram diferentes retorna -1
    /*-----------------------------------------*/
    // if sizes are different returns -1
    if (sizeOfQueue(queueOne) != sizeOfQueue(queueTwo)) return -1;

    // enquanto a fila nao for nula...
    /*-----------------------------*/
    // While the queue is not null ...
    while (queueOne != NULL)
    {
        // se os dados forem diferentes retorna 0
        /*------------------------------------*/  
        // If the data is different returns 0 
        if (queueOne->data != queueTwo->data)
        {
            return 0;
        }

        // as filas sao atualizadas
        /*-----------------------*/
        // The queues are updated
        queueOne = queueOne->next;
        queueTwo = queueTwo->next;
    }

    // retorna 1 se tudo ocorrer bem
    /*----------------------------*/
    // Returns 1 if everything occurs well
    return 1;
}


int queueCpy(node** source, node** destination)
{
    // se o destino nao estiver vazio
    // sera esvaziado
    /*---------------------------*/
    // is destination is not empty
    // will be emptied
    if (!emptyQueue(*destination)) totalDequeue(destination);;

    // enquanto o destino receber a fonte
    /*---------------------------------*/
    // while the destination receives the source
    while (*destination = *source)
    {
        // destino e fonte sao atualizados
        /*-----------------------------*/
        // destination and source are updated
        *destination = (*destination)->next;
        *source = (*source)->next;
    }

    // retorna a verificacao se as filas sao iguais
    /*-------------------------------------------*/
    // Returns to check if queues are equal
    return queueCmp(*source, *destination);
}