#ifndef PILHA_H
#define PILHA_H

typedef struct stack
{
    // top indica o topo da pilha
    int top;

    // next indica o proximo item da pilha
    struct stack* next;
}node;

// inicializacao da pilha
node* initStack();

// empilha a pilha
node* stackUp(node* stack, int data);

// verifica se a pilha está vazia
int emptyStack(node* stack);

// retira o topo
node* pop(node* stack);

// retorna o tamanho da pilha
int sizeStack(node* stack);

// printa o subtopo
void subTop(node* stack);

// da pop x vezes na pilha
node* countPop(node* stack, int count);

// esvazia a pilha
node* freeStack(node* stack);

// consulta a base
int base(node* stack);

// printa a pilha
void printStack(node* stack);

// "interface" do programa
int menu(void);
#endif