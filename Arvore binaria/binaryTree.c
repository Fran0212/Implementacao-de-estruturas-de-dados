#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"


void startTree(node** tree)
{
    // inicializacao da arvore
    /*---------------------*/
    // Tree Initialization
    *tree = NULL;
}

int isEmpty(node* tree)
{
    // verifica se a arvore esta vazia
    /*------------------------------*/
    // verifies if the tree is empty
    return tree == NULL;
}

void insert(node** tree, int data)
{
    // atribuicao de valores
    /*--------------------*/
    // assignment of values
    node* new = (node*)malloc(sizeof(node));

    new->data = data;
    new->left = NULL;
    new->right = NULL;

    // se estiver vazia...
    /*-----------------*/
    // If it is empty ...
    if (isEmpty(*tree))
    {
        // arvore recebe o novo no
        /*---------------------*/
        // Arvore receives the new
        *tree = new;
    }

    // caso contrario...
    /*---------------*/
    // else...
    else
    {
        // auxiliar eh instanciado
        /*---------------------*/
        // assisted is instantiated
        node* aux = *tree;

        // mesmo raciocinio apresentado no arquivo de cabecalho
        /*--------------------------------------------------*/
        // same reasoning presented in the head file
        if (data < aux->data)
        {
            if (isEmpty(aux->left))
            {
                new->father = aux;
                aux->left = new;
            }

            else
            {
                free(new);
                return insert(&(aux->left), data);
            }
        }

        else
        {
            if (isEmpty(aux->right))
            {
                new->father = aux;
                aux->right = new;
            }

            else
            {
                free(new);
                return insert(&(aux->right), data);
            }
        }
    }
}

node* search(node* tree, int data)
{
    // se estiver vazio...
    /*------------------*/
    // If it is empty ...
    if (isEmpty(tree))
    {
        // retorna NULL
        /*----------*/
        // Return NULL
        return NULL;
    }

    // se for o mesmo numero...
    /*----------------------*/
    // If it is the same number ...
    else if (data == tree->data)
    {
        // retorna o no
        /*----------*/
        // Returns the node
        return tree;
    }

    // se for menor...
    /*-------------*/
    // If it is smaller ...
    else if (data < tree->data)
    {
        // se for vazio...
        /*-------------*/
        // If it is empty ...
        if (isEmpty(tree->left))
        {
            // retorna NULL
            /*----------*/
            // Return NULL
            return NULL;
        }

        // procura pela esquerda
        /*-------------------*/
        // search for left
        return search(tree->left, data);
    }

    // se for maior...
    /*-------------*/
    // If it is higher ...
    else if (data > tree->data)
    {
        // se for vazio...
        /*-------------*/
        // If it is empty ...
        if (isEmpty(tree->right))
        {
            // retorna NULL
            /*----------*/
            // Return NULL
            return NULL;
        }

        // procura pela direita
        /*------------------*/
        // Search for right
        return search(tree->right, data);
    }
}

int max(node* tree)
{
    // se os dois "lados" estiverem vazios...
    /*------------------------------------*/
    // If the two "sides" are empty ...
    if (isEmpty(tree->left) && isEmpty(tree->right))
    {
        // retorna o numero
        /*---------------*/
        // Returns the number
        return tree->data;
    }

    // retorna novamente a funcao passando sempre o lado direito
    /*------------------------------------------------------*/
    // Returns the function again passing the right side
    return max(tree->right);
}

int min(node* tree)
{
    // se os dois "lados" estiverem vazios...
    /*------------------------------------*/
    // If the two "sides" are empty ...
    if (isEmpty(tree->left) && isEmpty(tree->right))
    {
        // retorna o numero
        /*---------------*/
        // Returns the number
        return tree->data;
    }

    // retorna novamente a funcao passando sempre o lado esquerdo
    /*------------------------------------------------------*/
    // Returns the function again passing the left side
    return max(tree->left);
}

int sussessor(node* tree, int data)
{
    // se o no estiver vazio...
    /*----------------------*/
    // If it is not empty ...
    if (isEmpty(tree))
    {
        // retorna 0
        /*-------*/
        // Returns 0
        return 0;
    }

    // procura o no passado na funcao
    /*----------------------------*/
    // seeks it in the passed in the function
    node* find = search(tree, data);

    // se o no da direita nao estiver vazio...
    /*-------------------------------------*/
    // If the right node is not empty ...
    if (!isEmpty(find->right))
    {
        // retorna o minimo da direita
        /*--------------------------*/
        // Returns the least right
        return min(find->right);
    }


    else
    {
        // father eh o pai do no que procuramos
        /*-----------------------------------*/
        // father is the father of node we are looking for
        node* father = find->father;

        // enquanto o pai nao for nulo e dado do pai for menor que o no a ser analisado...
        /*------------------------------------------------------------------------------*/
        // While the Father is not null and his father is smaller than the node to be analyzed ...
        while (father != NULL && father->data < find->data)
        {
            // escalamos a arvore
            /*----------------*/
            // We climb the tree
            father = father->father;
        }

        // retorna o dado armazenado pelo pai
        /*--------------------------------*/
        // Returns the data stored by the father
        return father->data;
    }
}

int predecessor(node* tree, int data)
{
    // se o no estiver vazio...
    /*----------------------*/
    // If it is not empty ...
    if (isEmpty(tree))
    {
        // retorna 0
        /*-------*/
        // Returns 0
        return 0;
    }

    // procura o no passado na funcao
    /*----------------------------*/
    // seeks it in the passed in the function
    node* find = search(tree, data);

    // se o no da esquerda nao estiver vazio...
    /*-------------------------------------*/
    // If the left node is not empty ...
    if (!isEmpty(tree->left))
    {
        // retorna o maximo da esquerda
        /*--------------------------*/
        // Returns the maximum from left
        return max(tree->left);
    }

    else
    {
        // father eh o pai do no que procuramos
        /*-----------------------------------*/
        // father is the father of node we are looking for
        node* father = find->father;

        // enquanto o pai nao for nulo e dado do pai for maior que o no a ser analisado...
        /*------------------------------------------------------------------------------*/
        // While the Father is not null and his father is bigger than the node to be analyzed ...
        while (father != NULL && father->data < find->data)
        {
            // escalamos a arvore
            /*----------------*/
            // We climb the tree
            father = father->father;
        }

        // retorna o dado armazenado pelo pai
        /*--------------------------------*/
        // Returns the data stored by the father
        return father->data;
    }
}

int height (node* tree)
{
    // se a arvore for vazia...
    /*-----------------------*/
    // If the tree is empty ...
    if (isEmpty(tree)) 
        // retorna -1
        /*--------*/
        // Return -1
        return -1; 
    // caso contrario...
    /*----------------*/
    // else...
    else {
        // verifica a altura da esquerda e da direita
        /*-----------------------------------------*/
        // Checks the height of the left and right
        int leftHeight = height(tree->left);
        int rightHeight = height(tree->right);

        // se a altura da da direita for maior...
        /*------------------------------------*/
        // If the height of the right is larger ...
        if (rightHeight > leftHeight)
        {
            // retorna ela somado com 1
            /*-----------------------*/
            // Returns it added with 1
            return rightHeight + 1;
        }

        // caso contrario...
        /*---------------*/
        // else...
        else
        {
            // retorna a altura da esquerda mais 1
            /*---------------------------------*/
            // Returns the left height plus 1
            return leftHeight + 1;
        }
    }
}

