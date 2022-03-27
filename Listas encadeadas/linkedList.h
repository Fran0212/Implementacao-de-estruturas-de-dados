#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKDLIST_H
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

// inicializa a lista
/*-----------------*/
// Initialize a list
void startList(node** list);

// verifica se a lista esta vazia
/*-----------------------------*/
// verifies if the list is empty
int emptyList(node* list);

// insere de acordo com o indice
/*----------------------------*/
// insert according to the index
int insertInIndex(node** list, int data, int index);

// printa a lista
/*-------------*/
// prints the list
void printList(node* list);

// retorna o tamanho da lista
/*------------------------*/
// Returns the list size
int lenLinkedList(node* list);

// retorna o indice do elemento
/*---------------------------*/
// Returns the element index
int elementIndex(node* list, int item);

// remove o elemento de acordo com o indice
/*---------------------------------------*/
// Removes the element according to the index
int removeInIndex(node** list, int index);

// remove o item de acordo com o valor
/*----------------------------------*/
// Removes the item according to the value
int removeItem(node** list, int data);

// retorna o elemento no indice inserido
/*------------------------------------*/
// Returns the element in the inserted index
int elementInIndex(node* list, int index);

// compara listas
/*-------------*/
// Compare lists
int equalList(node* listOne, node* listTwo);

// esvazia as listas
/*---------------*/
// Empty the lists
int fullToEmpty(node** list);

// copia uma lista em outra
/*----------------------*/
// Copies a list on another
int listCpy(node** source, node** destination);

#endif