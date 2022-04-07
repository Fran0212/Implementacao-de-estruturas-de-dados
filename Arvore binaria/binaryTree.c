#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"


void startTree(node** tree)
{
    *tree = NULL;
}

int emptyNode(node* tree)
{
    return tree == NULL;
}

void nodeValueAttribution(node** tree, int data)
{
    // auxiliar eh instanciado
    /*----------------------*/
    // auxiliary is instantiated
    node* aux = *tree;

    // atribuicao do dado
    /*----------------*/
    // data assignment
    aux->data = data;

    // esquerda e direita recebem NULL
    /*-----------------------------*/
    // left and right receive NULL
    aux->right = NULL;
    aux->left = NULL;
}

int insertNode(node** tree, int data)
{
    // declaracao do novo no
    /*--------------------*/
    // statement of the new node
    node* new = (node*)malloc(sizeof(node));

    // atribuicao de valor do novo no
    /*-----------------------------*/
    // assignment of value of the new node
    nodeValueAttribution(&new, data);

    // se a arvore/no estiver vazia...
    /*-----------------------------*/
    // If the tree/node is empty ...
    if (emptyNode(*tree))
    {
        // a raiz recebe o novo no
        /*---------------------*/
        // The root receives the new node
        *tree = new;
    } 

    // caso contrario...
    /*----------------*/
    // else...
    else
    {
        // retorna a atribuicao pela busca de valores na arvore
        /*---------------------------------------------------*/
        // Returns the assignment for the search for values in the tree
        return attributionSearch(tree, &new);
    }

    // retorna 1 se tudo ocorrer bem
    /*-----------------------------*/
    // Returns 1 if everything occurs well
    return 1;
}

int attributionSearch(node** tree, node** newNode)
{
    // declaracao dos auxiliares
    /*------------------------*/
    // declaration of auxiliaries
    node* aux = *tree;
    node* newNodeAux = *newNode;

    // se o dado for menor ou igual ao dado atual do no...
    /*-------------------------------------------------*/
    // If the data is less than or equal to the current data of the node...
    if (newNodeAux->data < aux->data )
    {
        // se o no da esquerda estiver vazio...
        /*----------------------------------*/
        // If the on the left is empty ...
        if (aux->left == NULL)
        {
            // o novo no eh atribuido ao esquerdo
            /*--------------------------------*/
            // The new node is assigned to the left
            aux->left = newNodeAux;
        }

        // caso contrario...
        /*---------------*/
        // else...
        else
        {
            // o no eh passado novamente na funcao
            /*----------------------------------*/
            // The node is passed again in the funcao
            return attributionSearch(&(aux->left), &newNodeAux);
        }
    }

    // caso contrario...
    /*---------------*/
    // else...
    else
    {
        // se o lado direito estiver vazio...
        /*---------------------------------*/
        // If the right side is empty ...
        if (aux->right == NULL)
        {
            // o direito recebe o novo no
            /*-------------------------*/
            // The right receives the new node
            aux->right = newNodeAux;
        }

        // caso contrario...
        /*---------------*/
        // else...
        else
        {
            // o lado direito eh passado novamente na funcao
            /*-------------------------------------------*/
            // the right side is passed again in the funcao
            return attributionSearch(&(aux->right), &newNodeAux);
        }
    }
}

int search(node* tree, int data)
{
    if (tree->data == data)
    {
        return tree->data;
    }
    
    if (tree->data < data)
    {
        return search(tree->left, data);
    }

    if (tree->data > data)
    {
        return search(tree->right, data);
    }
}

int max(node* tree)
{
    if (tree->right == NULL)
    {
        return tree->data;
    }

    return max(tree->right);
}

int min(node* tree)
{
    if(tree->left == NULL)
    {
        return tree->data;
    }

    return min(tree->left);
}