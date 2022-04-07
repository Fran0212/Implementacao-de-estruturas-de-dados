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
}node;

void startTree(node** tree);

int emptyNode(node* tree);

void nodeValueAttribution(node** tree, int data);

int insertNode(node** tree, int data);

int attributionSearch(node** tree, node** newNode);

int search(node* tree, int data);

int max(node* tree);

int min(node* tree);
#endif