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

node* root;

void startTree(node** tree);

int isEmpty(node* tree);

void insert(node** tree, int data);

node* search(node* tree, int data);

node* max(node* tree);

node* min(node* tree);

node* sucessor(node* tree, int data);

node* predecessor(node* tree, int data);

int height(node* tree);

int isRoot(node* tree);

int removeNode(node** tree, int data);

void inOrder(node* tree);
#endif