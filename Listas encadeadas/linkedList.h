#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#endif
// struct responsible for the linked list
/*--------------------------------------*/
// struct responsável pela lista encadeada
typedef struct linkedList
{
    // dado a ser inserido
    /*------------------*/
    // data to be insert
    int data;

    // ponteiro para a estrutura
    // responsavel por guardar as proximas posicoes
    /*--------------------------------------------*/
    // pointer to the struct
    // responsible for save the next positions
    struct linkedList* next;
}node;

void startList(node** list);

int emptyList(node* list);

int insertInIndex(node** list, int data, int index);

void printList(node* list);

int lenLinkedList(node* list);

int elementIndex(node* list, int item);



