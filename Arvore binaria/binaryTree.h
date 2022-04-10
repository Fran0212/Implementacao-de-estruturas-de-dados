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



typedef struct binaryTree
{
    int data;

    struct binaryTree* right;
    struct binaryTree* left;
    struct binaryTree* father;
}node;

void startTree(node** tree);

int isEmpty(node* tree);

void insert(node** tree, int data);

node* search(node* tree, int data);

int max(node* tree);

int min(node* tree);

int sussessor(node* tree, int data);

int predecessor(node* tree, int data);

int height (node* tree);

#endif