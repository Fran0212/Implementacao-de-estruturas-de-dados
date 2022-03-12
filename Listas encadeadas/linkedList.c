#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void startList(node** list)
{
    // lista eh inicializada
    *list = NULL;
}

int emptyList(node* list)
{
    // verifica se a lista esta vazia
    return list == NULL;
}

int insertInIndex(node** list, int data, int index)
{
    // alocacao do novo no
    /*-------------------*/
    // alocation of the new node
    node* new = (node*)malloc(sizeof(node*));
    // auxiliar 
    node* aux = *list;
    // posicao
    int indexCount = 0;
    // dado eh atribuido
    new->data = data;

    // verifica se a lista esta vazia e se o indice eh zero
    // pois se ela estiver vazia o unico jeito de inserir eh no incio
    if (!(*list) && index != 0) return 0;

    // verifica se o indice eh possivel
    if (index > lenLinkedList(*list) - 1) return 0;
    
    // switch para certos atalhos
    switch (index)
    {
        // se o indice for 0 
        case 0:
            // o proximo do novo recebe a lista
            new->next = NULL;
            // lista recebe o novo
            (*list) = new;
            break;
        case -1:
            // itera ateh o ultimo item
            while (aux->next != NULL)
            {
                // auxiliar eh atualizado
                aux = aux->next;
            }

            // o proximo em relacao ao novo recebe NULL
            new->next = aux->next;
            // proximo recebe o novo
            aux->next = new;
            break;
        default:
            // procura o item ateh achar o index
            while (indexCount != index-1)
            {
                // a posicao do elemento eh incrementada
                indexCount++;
                // aux eh atualizado
                aux = aux->next;
            }

            // mesmo raciocinio de troca do case anterior
            new->next = aux->next;
            aux->next = new;
            break;
        }
}

void printList(node* list)
{
    // copia da lista
    node* cpyList = list;

    // enquanto cpyList for diferente de NULL
    while (cpyList != NULL)
    {
        // printa o dado da lista 
        printf("{%d} ", cpyList->data);
        // cpyList eh atuaalizado
        cpyList = cpyList->next;
    }
}

int lenLinkedList(node* list)
{
    // tamanho
    int size = 0;

    // enquanto list nao for nula
    while (list != NULL)
    {
        // tamanho eh incrementado
        size++;
        // list eh atualizada
        list = list->next;
    }

    // retorna o tamanho
    return size;
}

int elementIndex(node* list, int item)
{
    int index = 0;
    node* cpyList = list;

    while (cpyList != NULL)
    {
        index++;
        cpyList = cpyList->next;
    }

    return index;
}