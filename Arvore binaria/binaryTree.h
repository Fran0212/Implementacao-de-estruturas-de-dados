#include <stdio.h>
#include <stdlib.h>

#ifndef BINARYTREE_H
#define BINARYTREE_H

/*======DISPOSICAO DE VALORES======*/
/**
 *  se (valor < valorAtualDoNo)
 *  {
 *      esquerda = valor;
 *  } caso contrario {
 *      direita = valor;
 * }
 * 
 * =====================================
 * 
 * if (valor >= actualNodeValue)
 * {
 *      left = valor;
 * } else {
 *      right = valor;
 * }
 */
/*=======VALUES DISPOSITION=======*/

// estrutura responsavel pela arvore
/*-------------------------------*/
// structure responses for the tree
typedef struct binaryTree
{
    // dado de cada no
    /*--------------*/
    // data of each node
    int data;

    // referencia pra direita
    /*--------------------*/
    // reference to the right
    struct binaryTree* right;

    // referencia pra esquerda
    /*----------------------*/
    // reference to the left
    struct binaryTree* left;

    // referencia pro pai do no
    /*-----------------------*/
    // reference to the father of the node
    struct binaryTree* father;
}node;

// referencia pra raiz
/*-----------------*/
// reference to the root
node* root;

// inicializa a arvore
/*-----------------*/
// starts the tree
void startTree(node** tree);

// verifica se esta vazia
/*--------------------*/
// verifies if is empty
int isEmpty(node* tree);

// verifica se eh raiz
/*------------------*/
// verifies if is root
int isRoot(node* tree);

// verifica se eh um no
/*------------------*/
// verifies if is a node
int isNode(node* tree);

// verifica se eh uma folha
/*----------------------*/
// verifies if is a node
int isLeaf(node* tree);

// insere valores
/*-------------*/
// inserts values
void insert(node** tree, int data);

// procura valores
/*-------------*/
// search values
node* search(node* tree, int data);

// retorna o maior valor
/*-------------------*/
// returns the biggest value
node* max(node* tree);

// retorna o menor valor
/*-------------------*/
// returns the least value
node* min(node* tree);

// retorna o sucessor
/*-----------------*/
// returns the sucessor
node* sucessor(node* tree, int data);

// retorna o predecessor
/*-------------------*/
// returns the predecessor
node* predecessor(node* tree, int data);

// retorna a altura
/*---------------*/
// returns the height
int height(node* tree);

// remove o no
/*----------*/
// removes the node
int removeNode(node** tree, int data);

// printa a arvore
/*--------------*/
// prints the tree
void printTree(node* tree);
#endif