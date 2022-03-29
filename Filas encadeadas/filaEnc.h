#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    // dado a ser inserido
    /*-----------------*/
    // data to be inserted
    int data;

    // ponteiro para o proximo
    /*---------------------*/
    // pointer to the next
    struct queue* next;
}node;

// inicializa a fila
/*----------------*/
// Initializes the queue
void startQueue(node** queue);

// verifica se a fila esta vazia
/*----------------------------*/
// verifies if the queue is empty
int emptyQueue(node* queue);

// enfileira um item
/*----------------*/
// queues an item
int enqueue(node** queue, int data);

// printa a fila
/*-------------*/
// prints the queue
void printQueue(node* queue);

// desenfileira um item
/*-------------------*/
// dequeue an item
int dequeue(node** queue);

// desenfileira totalmente
/*----------------------*/
// totally dequeue
int totalDequeue(node** queue);

// tamanho da fila
/*--------------*/
// queue size
int sizeOfQueue(node* queue);

// compara duas filas
/*----------------*/
// Compare two rows
int queueCmp(node* queueOne, node* queueTwo);

// copia uma lista em outra
/*-----------------------*/
// Copies a list on another
int queueCpy(node** source, node** destination);

