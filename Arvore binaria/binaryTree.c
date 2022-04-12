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
        root = *tree;
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

node* max(node* tree)
{
    // se os dois "lados" estiverem vazios...
    /*------------------------------------*/
    // If the two "sides" are empty ...
    if (isEmpty(tree->left) && isEmpty(tree->right))
    {
        // retorna o numero
        /*---------------*/
        // Returns the number
        return tree;
    }

    // retorna novamente a funcao passando sempre o lado direito
    /*------------------------------------------------------*/
    // Returns the function again passing the right side
    return max(tree->right);
}

node* min (node* tree)
{
    // se os dois "lados" estiverem vazios...
    /*------------------------------------*/
    // If the two "sides" are empty ...
    if (isEmpty(tree->left) && isEmpty(tree->right))
    {
        // retorna o numero
        /*---------------*/
        // Returns the number
        return tree;
    }

    // retorna novamente a funcao passando sempre o lado esquerdo
    /*------------------------------------------------------*/
    // Returns the function again passing the left side
    return min(tree->left);
}

node* sucessor(node* tree, int data)
{
    // se o no estiver vazio...
    /*----------------------*/
    // If it is not empty ...
    if (isEmpty(tree))
    {
        // retorna 0
        /*-------*/
        // Returns 0
        return NULL;
    }

    // procura o no passado na funcao
    /*----------------------------*/
    // seeks it in the passed in the function
    node* found = search(tree, data);

    // se o no da direita nao estiver vazio...
    /*-------------------------------------*/
    // If the right node is not empty ...
    if (!isEmpty(found->right))
    {
        // retorna o minimo da direita
        /*--------------------------*/
        // Returns the least right
        return min(found->right);
    }


    else
    {
        // father eh o pai do no que procuramos
        /*-----------------------------------*/
        // father is the father of node we are looking for
        node* father = found->father;

        // enquanto o pai nao for nulo e dado do pai for menor que o no a ser analisado...
        /*------------------------------------------------------------------------------*/
        // While the Father is not null and his father is smaller than the node to be analyzed ...
        while (father != NULL && father->data < found->data)
        {
            // escalamos a arvore
            /*----------------*/
            // We climb the tree
            father = father->father;
        }

        // retorna o dado armazenado pelo pai
        /*--------------------------------*/
        // Returns the data stored by the father
        return father;
    }
}

node* predecessor(node* tree, int data)
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
    node* found = search(tree, data);

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
        node* father = found->father;

        // enquanto o pai nao for nulo e dado do pai for maior que o no a ser analisado...
        /*------------------------------------------------------------------------------*/
        // While the Father is not null and his father is bigger than the node to be analyzed ...
        while (father != NULL && father->data < found->data)
        {
            // escalamos a arvore
            /*----------------*/
            // We climb the tree
            father = father->father;
        }

        // retorna o dado armazenado pelo pai
        /*--------------------------------*/
        // Returns the data stored by the father
        return father;
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

int isLeaf(node* tree)
{
    // verifica se os dois lados sao vazios
    /*----------------------------------*/
    // verify that the two sides are empty
    return (isEmpty(tree->left) && isEmpty(tree->right));
}

int isRoot(node* tree)
{
    // verifica se o no eh raiz
    /*----------------------*/
    // Checks if the node is Root
    return tree == root;
}

int isNode(node* tree)
{
    // se apenas o lado esquerdo estiver preenchido...
    /*---------------------------------------------*/
    // If only the left side is filled ...
    if (!isEmpty(tree->left))
    {
        // retorna 1
        /*--------*/
        // returns 1
        return 1;
    }

    // se apenas o lado direito estiver preenchido...
    /*---------------------------------------------*/
    // If only the right side is filled ...
    if (!isEmpty(tree->right))
    {
        // retorna 2
        /*--------*/
        // returns 2
        return 2;
    }

    // se os dois lados estiverem preenchidos...
    /*---------------------------------------*/
    // if the both side are filled...
    if (!isEmpty(tree->left) && !isEmpty(tree->right))
    {
        // retorna 3
        /*--------*/
        // returns 3
        return 3;
    }
}

int removeNode(node** tree, int data)
{
    // se estiver vazio retorna 0
    /*------------------------*/
    // if it is empty returns 0
    if (isEmpty(*tree)) return 0;

    // acha o no a ser removido
    /*----------------------*/
    // finds the node to be removed
    node* found = search(*tree, data);

    // se for uma folha...
    if (isLeaf(found))
    {
        // se a folha for raiz...
        if (isRoot(found))
        {
            // no recebe NULL
            *tree = NULL;
            // raiz recebe NULL
            root = *tree;
        }

        if (found->data < found->father->data)
        {
            found->father->left = NULL;
        }

        else
        {
            found->father->right = NULL;
        }
    }

    int Node = isNode(found);

    if (Node == 1)
    {
        if (isRoot(found))
            root = found->left;

        found->father->left = found->left;
    }


    if (Node == 2)
    {
        if (isRoot(found))
            root = found->right;

        found->father->right = found->right;
    }

    if (Node == 3)
    {
        return 0;
    }

    return 1;
}

void inOrder(node* tree)
{
    inOrder(tree->left);
    printf("%d-> ", tree->data);
    inOrder(tree->right);
}