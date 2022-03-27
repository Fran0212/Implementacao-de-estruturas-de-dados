#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void startList(node** list)
{
    // lista eh inicializada
    /*--------------------*/
    // List is initialized
    *list = NULL;
}

int emptyList(node* list)
{
    // verifica se a lista esta vazia
    /*-----------------------------*/
    // verifies if the list is empty
    return list == NULL;
}

int insertInIndex(node** list, int data, int index)
{
    // alocacao do novo no
    /*-------------------*/
    // allocation of the new node
    node* new = (node*)malloc(sizeof(node*));

    // dado eh atribuido
    /*----------------*/
    // data is assigned
    new->data = data;

    // auxiliar 
    node* aux = *list;

    // posicao
    /*-------*/
    // position
    int indexCount = 0;

    // verifica se a lista esta vazia e se o indice eh zero
    // pois se ela estiver vazia o unico jeito de inserir eh no incio
    /*-------------------------------------------------------------*/
    // Checks if the list is empty and if the index is zero
    // because if it is empty the only way to insert eh in the beginning
    if (emptyList(*list) && index != 0) return 0;

    // verifica se o indice eh possivel
    /*--------------------------------*/
    // Checks if the index is possible
    if (index > lenLinkedList(*list)) return 0;
    
    // switch para certos atalhos
    /*-------------------------*/
    // switch para certos atalhos
    switch (index)
    {
        // se o indice for 0 ... 
        /*----------------*/
        // If the index is 0 ... 
        case 0:
            // o proximo recebe a lista
            /*-----------------------*/
            // The next one receives the list
            new->next = *list;

            // lista recebe o novo
            /*------------------*/
            // List receives the new
            *list = new;
            break;
        case -1:
            // itera ate o ultimo item
            /*----------------------*/
            // iterate to the last item
            while (aux->next != NULL)
            {
                // auxiliar eh atualizado
                /*---------------------*/
                // auxiliar is refreshed
                aux = aux->next;
            }

            // o proximo em relacao ao novo recebe NULL
            /*---------------------------------------*/
            // Next in relation to the new receives NULL
            new->next = aux->next;

            // proximo recebe o novo
            /*--------------------*/
            // Next receives the new
            aux->next = new;
            break;
        default:
            // procura o item ateh achar o index
            /*--------------------------------*/
            // search for the item until it finds the index
            while (indexCount != index-1)
            {
                // a posicao do elemento eh incrementada
                /*------------------------------------*/
                // The position of the element is incremented
                indexCount++;

                // aux eh atualizado
                /*----------------*/
                // aux is refreshed
                aux = aux->next;
            }

            // mesmo raciocinio de troca do case anterior
            /*----------------------------------------*/
            // Same reasoning of exchange as in the previous case
            new->next = aux->next;
            aux->next = new;
            break;
        }
}

void printList(node* list)
{
    // copia da lista
    /*-------------*/
    // List copy
    node* cpyList = list;

    // enquanto cpyList for diferente de NULL ...
    /*----------------------------------------*/
    // While cpylist is different from NULL ...
    while (cpyList != NULL)
    {
        // printa o dado da lista 
        /*--------------------*/
        // Prints the list data
        printf("{%d}--->", cpyList->data);

        // cpyList eh atualizado
        /*-------------------*/
        // cpyList is refreshed
        cpyList = cpyList->next;
    }
    printf("NULL\n");
}

int lenLinkedList(node* list)
{
    // tamanho
    /*-----*/
    // size
    int size = 0;

    // enquanto list nao for nula ...
    /*------------------------*/
    // While List is not null ...
    while (list != NULL)
    {
        // tamanho eh incrementado
        /*---------------------*/
        // size is incremented
        size++;

        // list eh atualizada
        /*----------------*/
        // List is updated
        list = list->next;
    }

    // retorna o tamanho
    /*----------------*/
    // returns the size
    return size;
}

int elementIndex(node* list, int element)
{
    // index do elemento
    /*----------------*/
    // index do elemento
    int index = 0;

    // copia da lista
    /*------------*/
    // List copy
    node* cpyList = list;

    // enquanto cpyList nao for nulo ...
    /*--------------------------------*/
    // While cpylist is not null ...
    while (cpyList != NULL)
    {
        // se o dado atual for o elemento buscado
        // retorna o indice
        /*-------------------------------------*/
        // if the current data is the element sought
        // Returns the index
        if (cpyList->data == element) return index;

        // caso contrario
        // indece eh incrementado
        /*---------------------*/
        // else
        // index is incremented
        index++;

        // cpyList eh iterado
        /*-----------------*/
        // cpyList is iterate
        cpyList = cpyList->next;
    }

    // retorna -1 em caso de erro
    /*-------------------------*/
    // Returns -1 in case of error
    return -1;
}

int removeInIndex(node** list, int index)
{
    // auxiliar eh instanciado
    /*----------------------*/
    // assisted is instantiated
    node* aux = *list;

    // contador para verificar o indice
    /*------------------------------*/
    // Accountant to verify or index
    int countIndex = 0;

    // se a lista estiver vazia e o indice nao for 0
    // retorna 0
    /*--------------------------------------------*/
    // If the list is empty and the index is not 0
    // Returns 0
    if (emptyList(*list) && index != 0) return 0;

    // se o indice for maior que o possivel
    // retorna 0
    /*----------------------------------*/
    // If the index is greater than possible
    // Returns 0
    if (index > lenLinkedList(*list)) return 0;

    switch (index)
    {
        // primeiro indice
        /*-------------*/
        // first index
        case 0:
            // posicao atual recebe a proxima
            /*-----------------------------*/
            // Current position receives next
            *list = (*list)->next;
            return 1;

        // ultima posicao
        /*-------------*/
        // Latest Position
        case -1:
            // enquanto o item analisado nao for o penultimo ...
            /*-------------------------------------------*/
            // While the item analyzed is not the penultimate ...
            while (aux->next->next != NULL)
            {
                // auxiliar anda uma casa
                /*---------------------*/
                // auxiliary walks a house
                aux = aux->next;
            }

            // o proximo item recebe o ultimo
            /*-----------------------------*/
            // the next item receives the last
            aux->next = aux->next->next;
            return 1;
        // qualquer outra posicao
        /*---------------------*/
        // any other position
        default:
            // enquanto o contador nao estiver antes do indice
            /*---------------------------------------------*/
            // while the counter is not before the index
            while (countIndex != index-1)
                {
                    // contador eh incrementado
                    /*----------------------*/
                    // counter is incremented
                    countIndex++;

                    // auxiliar eh atualizado
                    /*---------------------*/
                    // auxiliar is updated
                    aux = aux->next;
                }

            // o proximo item recebe o seu proximo
            /*---------------------------------*/
            // the next item receives your next
            aux->next = aux->next->next;
            return 1;
    }
}

int removeItem(node** list, int data)
{
    // se o elemento nao for encontrado ele retorna 0
    /*---------------------------------------------*/
    // if the element is not found it returns 0
    if (elementIndex(*list, data) < 0) return 0;

    // auxiliar eh instanciado
    /*----------------------*/
    // auxiliar is instantiated
    node* aux = *list;

    // se o dado atual for igual ao dado inserido
    // significa que o item eh o primeiro
    /*---------------------------------------*/
    // If the current data is equal to the inserted data
    // means that the item is the first
    if (aux->data == data)
    {
        // entao eh so fazer o atual recber o valor do proximo
        /*--------------------------------------------------*/
        // So it's just doing the current one receiving the value of the next
        *list = (*list)->next;
        return 1;
    }

    // enquanto o dado for diferente
    /*---------------------------*/
    // while the data is different
    while (aux->next->data != data)
    {
        // auxiliar eh atualizado
        /*--------------------*/
        // auxiliar is updated
        aux = aux->next;
    }

    // dado eh removido
    /*--------------*/
    // data is removed
    aux->next = aux->next->next;

    return 1;
}

int elementInIndex(node* list, int index)
{
    // verifica se o indice eh possivel
    /*------------------------------*/
    // Checks if the index is possible
    if (index > lenLinkedList(list) - 1 || index < 0) return 0;

    // para i enquanto for menor que o indice
    /*------------------------------------*/
    // for I while it is smaller than the index
    for (int i = 0; i < index; i++)
    {
        // lista eh atualizada
        /*-----------------*/
        // lista is updated
        list = list->next;
    }

    // retorna o dado do indice
    /*----------------------*/
    // Returns the index data
    return list->data;
}

int equalList(node* listOne, node* listTwo)
{
    // tamanho das listas
    /*-----------------*/
    // Lists Sizes
    int sizeOne = lenLinkedList(listOne);
    int sizeTwo = lenLinkedList(listTwo);

    // se os tamanhos forem diferentes
    // retorna -1
    /*------------------------------*/
    // If the sizes are different
    // Returns -1
    if (sizeOne != sizeTwo) return -1;

    // enquanto o tamanho nao for 0
    /*--------------------------*/
    // while the size is not 0
    while (sizeOne > 0)
    {
        // se o o dado entre elas forem diferentes
        /*--------------------------------------*/
        // if the data between them are different
        if (listOne->data != listTwo->data)
        {
            // retorna 0
            /*--------*/
            // Returns 0
            return 0;
        }
        // tamanho é decrementado
        /*--------------------*/
        // size is decremented
        sizeOne--;
    }

    // retorna 1 indicando sucesso
    /*--------------------------*/
    // Returns 1 Indicating Success
    return 1;
}

int fullToEmpty(node** list)
{
    // se a lista estiver vazia retorna 0
    /*--------------------------------*/
    // If the list is empty returns 0
    if (emptyList(*list)) return 0;

    // enquanto a lista nao for nula
    /*---------------------------*/
    // While the list is not null
    while (*list != NULL)
    {
        // lista eh atualaizada
        /*------------------*/
        // list is updated
        *list = (*list)->next;
    }

    // retorna 1
    /*--------*/
    // returns 1
    return 1;
}

int listCpy(node** source, node** destination)
{
    // se o destino nao estiver vazio
    // ele sera esvaziado
    /*-----------------------------*/
    // If the destination is not empty
    // it will be emptied
    if (!emptyList(*destination)) fullToEmpty(destination);

    // enquanto a atribuicao for possivel
    /*---------------------------------*/
    // While the assignment is possible
    while (*destination = *source)
    {   
        // as listas "andarao" uma casa
        /*--------------------------*/
        // the lists "walking" a house
        *source = (*source)->next;
        *destination = (*destination)->next;
    }

    // se as listas foram diferentes
    // retorna 0
    /*----------------------------*/
    // If the lists were different
    // Returns 0
    if (!equalList(*source, *destination)) return 0;

    // retorna um indicando sucesso
    /*--------------------------*/
    // Returns an Indicating Success
    return 1;
}
