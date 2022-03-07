#include <stdio.h>
#include <stdlib.h>
#include "Lista_enc.h"

node* startList()
{
    // alocacao de um espaco de memoria para o no
    /*-----------------------------------------*/
    // a new memory space is alocated for the node
    node* init = (node*)malloc(sizeof(node));

    // a inicia com um item vazio
    /*--------------------------*/
    // start with a empty item
    return init = NULL;
}


int emptyList(node* list)
{
    // verifica se a lista esta vazia
    /*------------------------------*/
    // verifie if list is empty
    return list == NULL;
}


node* insertInStart(node* list, int data)
{
    // alocacao de um espaco para o no
    /*-----------------------------------------*/
    // a new memory space is alocated for the node
    node* new = (node*) malloc(sizeof(node));

    // novo dado a ser inserido
    /*-----------------------*/
    // new data to be inert
    new->data = data;

    // proximo item da lista
    /*---------------------*/
    // next item of the list

    // // next recebe a lista inteira
    // // para que o encadeamento anterior nao seja perdido
    /*----------------------------------------------------*/
    // // next receives the entire list 
    // // to do not lost the previous link
    new->next = list;

    return new;
}

node* removeStart(node* list)
{
    // a lista recebe o proximo item
    // sobrescrevendo o anterior
    /*------------------------------*/
    // list receives the next item
    // overwriting the previous

    list = list->next;
}


void printList(node* list)
{
    // copia da lista original
    /*-----------------------*/
    // copy of the original list
    node* cpyList = list;

    // enquanto cpyList nao for vazia...
    /*-------------------------------*/
    // while cpyList do not be empty...
    while (cpyList != NULL)
    {
        // um item eh printado no terminal
        /*------------------------------*/
        // one item is printed in terminal
        printf("[%d] ", cpyList->data);

        // cpyList "anda" um item, recebendo o proximo
        /*--------------------------------------*/
        // cpyList "walks" one item, receiving the next
        cpyList = cpyList->next;
    }

    // apenas para quebrar linha
    /*-------------------------*/
    // just to break line
    printf("\n\n");
}


int sizeOfList(node* list)
{
    // se list estiver vazia...
    /*------------------------*/
    // if list is empty...
    if (!list)
    {
        // uma mensagem de erro eh printada no terminal
        /*--------------------------------------------*/
        // an error message is printed in terminal
        printf("A lista ainda está vazia\n");

        // retorna 0 indicando erro
        /*-----------------------*/
        // returns 0 indicating error
        return 0;
    } else {

        // caso contrario...
        /*-------------*/
        // else...

        // uma copia da lista eh declarada
        /*--------------------------------*/
        // a copy of the list is declarated
        node* cpyList = list;
        // size indica o tamanho da lista
        /*------------------------------*/
        // size indicate the size of the list
        int size = 0;

        // enquanto cpyList nao for nula...
        /*--------------------------------*/
        // while cpyList isn't Null...
        while (cpyList != NULL)
        {
            // o tamanho eh incrmentado em 1
            /*----------------------------*/
            // the size is incremented in one
            size += 1;
        }

        // retorna o tamanho
        /*-----------------*/
        // returns the size
        return size;
    }
}