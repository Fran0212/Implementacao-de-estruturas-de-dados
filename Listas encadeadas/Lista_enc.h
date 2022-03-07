#include <stdio.h>
#include <stdlib.h>

// estrutura responsavel pela lista encadeada
/*-----------------------------------------*/
// struct response for the linked list
typedef struct linkedList
{
    // dado inserido
    /*-------------*/
    // data to insert
    int data;

    // proximo item
    /*------------*/
    // next item
    struct linkedList* next;
} node;

// inicializa a lista
/*------------------*/
// start the list
node* startList();

// verifica se a lista estah vazia
/*------------------------------*/
// verify if list is empty
int emptyList(node* list);

// insere um item no inicio da lista
/*--------------------------------*/
// inserts an item at the start of the list
node* insertInStart(node* list, int data);

// remove um item do inicio da lista
/*---------------------------------*/
// removes an item from the start of the list
node* removeStart(node* list);

// printa a lista no terminal
/*--------------------------*/
// prints the list at the terminal
void printList(node* list);
