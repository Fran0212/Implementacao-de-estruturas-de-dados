#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "linkedList.h"

// protótipos
/*---------*/
// prototypes
void menu(node* list);
void userMenu(node* list);


int main(void)
{
    setlocale(LC_ALL, "portuguese");
    node* list;
    startList(&list);

    menu(list);
}

void menu(node* list)
{
    // mostra os itens do menu
    printf("\n");
    printf("\t[0] -> para sair do programa\n");
    printf("\t[1] -> para adicionar um elemento\n");
    printf("\t[2] -> para remover um elemento num determinado índice\n");
    printf("\t[3] -> para remover um elemento\n");
    printf("\t[4] -> para obter o tamanho da lista\n");
    printf("\t[5] -> para consultar o indice de um elemento\n");
    printf("\t[6] -> para consultar o elemento num determinado índice\n");
    printf("\t[7] -> para comparar duas listas\n");
    printf("\t[8] -> para transferir dados entre listas\n");
    printf("\t[9] -> para limpar a lista\n");
    printf("\t[10] -> para printar a lista\n");
    printf("\t[11] -> para verificar se a lista esta vazia\n\n");

    return userMenu(list);
}

void userMenu(node* list)
{
    // opção dada pelo usuário
    int opt;
    // indice e elemento da lista
    int index, element;

    printf("\tIsira sua opção: ");
    scanf("%d", &opt);
    printf("\n");

    switch (opt)
    {
        case 0:
            exit(0);
        case 1:
            printf("\tIsira o índice: ");
            scanf("%d", &index);

            printf("\t\nInsira o elemento que voce deseja inserir: ");
            scanf("%d", &element);

            if (!insertInIndex(&list, element, index)) printf("\n\tNao foi possível concluir a operação\n");

            return menu(list);
        case 2:
            printf("\tIsira o índice: ");
            scanf("%d", &index);

            if (!removeInIndex(&list, index)) printf("\n\tNao foi possível concluir a operação\n");

            return menu(list);
        case 3:
            printf("\tInsira o elemento que voce deseja remover: ");
            scanf("%d", &element);

            if (!insertInIndex(&list, element, index)) printf("\n\tNao foi possível concluir a operação\n");

            return menu(list);
        case 4:
            if (lenLinkedList(list) == 0)
            {
                printf ("\tA lista ainda está vazia!\n");
            } else printf("\tO tamanho da lista ?: %d\n", lenLinkedList(list));

            return menu(list);
        case 5:
            printf("\tInsira o elemeto a ser consultado: ");
            scanf("%d", &element);

            index = elementIndex(list, element);

            if (index < 0)
            {
                printf("\n\tElemento não encontrado!\n");
            } else printf("\n\tO índice do elemento %d ? %d\n", element, index);

            return menu(list);
        case 6:
            printf("\tIsira o índice a ser consultado: ");
            scanf("%d", &index);

            element = elementIndex(list, index);

            if (element == 0)
            {
                printf("\n\tO índice não foi encontrado\n");
            } else printf("\n\tO elemento no índice %d ? %d\n", index, element);

            return menu(list);
        case 7:
            printf("\n\tDesculpe, eu não consigo fazer isso por você...\n");
            printf("\tMas você pode tentar manualmente usando a função equalList\n");
            return menu(list);
        case 8:
            printf("\n\tDesculpe, eu não consigo fazer isso por você...\n");
            printf("\tMas você pode tentar manualmente usando a função listCpy\n");
            return menu(list);
        case 9:
            if (!fullToEmpty(&list))
            {
                printf("\n\tA lista j? está vazia\n");
            } else printf("\n\tLista esvaziada com sucesso\n");

            return menu(list);
        case 10:
            printf("\t");
            printList(list);

            return menu(list);
        case 11:
            printf("%s", emptyList(list) ? "\n\tSim, a lista está vazia\n" : "\n\tnão, a lista não está vazia\n");
        default:
            printf("\n\tOpção invalida\n");

            return menu(list);
    }
}