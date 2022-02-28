#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

node* initStack()
{
    // aloca um espaco na memoria para a pilha
    node *init = (node*) malloc(sizeof(node));

    // coloca um dado vazio 
    // pois pilhas devem ser inicializadas com NULL
    init = NULL;

    // retorna um ponteiro para a pilha
    return init;
}


int emptyStack(node* stack)
{
    // verifica se a pilha esta vazia
    if (stack == NULL)
    {
        printf("\n\t\tPilha vazia\n");
    } else printf("\n\t\tA pilha nao esta vazia\n\n");
    return stack == NULL;
}


node* stackUp(node* stack, int data)
{
    // um espaco novo eh alocado para receber o dado
    node* new = (node*) malloc(sizeof(node));

    // o topo recebe o dado do usuario
    new->top = data;

    // o proximo item recebe a pilha 
    new->next = stack;

    // pilha eh atualizada
    stack = new;

    return stack;
}


node* pop(node* stack)
{
    // auxRemove eh usado para que, ao remover,
    // o encadeamento nao seja perdido
    int auxRemove;

    // auxiliar recebe o topo
    auxRemove = stack->top;

    // pilha recebe o proximo
    stack = stack->next;

    return stack;
}

int sizeStack(node* stack)
{
    // size guardara o tamanho
    int size = 0;

    // copia da pilha
    node* cpyStack = stack;

    // enquanto cpyStack nao for nulo
    while (cpyStack != NULL)
    {
        // tamanho eh implementado em 1
        size++;

        // cpyStack eh atualizada para o proximo item
        cpyStack = cpyStack->next;
    }

    return size;
}


void subTop(node* stack)
{
    // como ao fazer um push, next guarda a pilha intereira
    // eh so printar o topo da pilha guardada em next, para obtermos o subtopo
    printf("\nO subtop eh: %d\n\n", stack->next->top);
}


node* countPop(node* stack, int count)
{
    // itera x vezes
    for (int i = 0; i <= count; i++)
    {
        // verifica se a pilha esta vazia
        if (emptyStack(stack)) return stack;
        // caso contrario remove o item
        else stack = pop(stack);
    }

    return stack;
}


node* freeStack(node* stack)
{
    // enquanto stacl nao for nulo
    while (stack != NULL)
    {
        // um item eh removido
        stack = pop(stack);
    }

    return stack;
}


int base(node* stack)
{
    // copia da pilha para iteracao
    node* cpyStack = stack;

    // enquanto a copia nao for nula
    while (cpyStack != NULL)
    {
        // verifica se o proximo espaco de memoria eh nulo
        if (cpyStack->next == NULL)
        {
            // se for
            // o topo da ultima pilha eh retornado
            return cpyStack->top;
        }

        // cpyStack eh atualizado com o proximo item
        cpyStack = cpyStack->next;
    }
}


void printStack(node* stack)
{
    // copia para iteracao
    node* cpyStack = stack;

    printf("\n\n\n\n");
    // enquanto nao for nulo
    while (cpyStack != NULL)
    {
        // o topo da pilha aramazenado em next eh printado
        printf("\t\t[%d]\n", cpyStack->top);

        // cpyStack eh atualizada
        cpyStack = cpyStack->next;
    }
    printf("\n\n\n\n");
}



int menu( void )
{
    // mostra os itens do menu
    printf("[0] -> para sair do programa\n");
    printf("[1] -> para empilhar\n");
    printf("[2] -> para desempilhar um unico elemento\n");
    printf("[3] -> para desempilhar N elementos\n");
    printf("[4] -> para obter o tamanho da pilha\n");
    printf("[5] -> para consultar o subtopo\n");
    printf("[6] -> para consultar a base\n");
    printf("[7] -> para limpar a pilha\n");
    printf("[8] -> para printar a pilha\n");
    printf("[9] -> para verificar se a pilha esta vazia\n");
}
