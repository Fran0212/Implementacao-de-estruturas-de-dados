#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
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
