#include <stdio.h>
#include <stdlib.h>

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
void startList(node** list);

// verifica se a lista esta vazia
int emptyList(node* list);

// insere de acordo com o indice
int insertInIndex(node** list, int data, int index);

// printa a lista
void printList(node* list);

// retorna o tamanho da lista
int lenLinkedList(node* list);

// retorna o indice do elemento
int elementIndex(node* list, int item);

// remove o elemento de acordo com o indice
int removeInIndex(node** list, int index);

// remove o item de acordo com o valor
int removeItem(node** list, int data);

// retorna o elemento no indice inserido
int elementInIndex(node* list, int index);

// compara listas
int equalList(node* listOne, node* listTwo);

// esvazia as listas
int fullToEmpty(node** list);

// copia uma lista em outra
int listCpy(node** source, node** destination);

