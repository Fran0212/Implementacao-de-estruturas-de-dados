# Arvore binaria de busca

> Definição
> 
> - Arvore binaria de busca é uma estrutura de dados feita, especificamente, para buscar dados

## Raciocínio de manipulação

```c
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
```

## Estrutura

```c
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
```

## Inserção

```c
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
```

## Remoção

```c
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
    /*-----------------*/
    // If it's a leaf ...
    if (isLeaf(found))
    {
        // se a folha for raiz...
        /*---------------------*/
        // If the leaf is root ...
        if (isRoot(found))
        {
            // no recebe NULL
            /*-------------*/
            // node receives NULL
            *tree = NULL;
            // raiz recebe NULL
            /*---------------*/
            // root receives NULL
            root = *tree;
        }

        // se o dado for menor que o valor do pai...
        /*----------------------------------------*/
        // If the data is smaller than the value of the father ...
        if (found->data < found->father->data)
        {
            // a esquerda do pai recebe NULL
            /*----------------------------*/
            // The left of the father receives null
            found->father->left = NULL;
        }

        // caso contrario...
        /*------------*/
        // else...
        else
        {
            // o pai recebe null
            /*----------------*/
            // The father receives null
            found->father->right = NULL;
        }
    }

    // Node representa o grau do no
    /*--------------------------*/
    // Node represents the degree of the node
    int Node = isNode(found);

    // se Node for igual a um...
    /*---------------------*/
    // If Node is equal to one...
    if (Node == 1)
    {
        // se for raiz...
        /*------------*/
        // is is root...
        if (isRoot(found))
        {
            // a raiz recebe o lado esquerdo do no
            /*----------------------------------*/
            // the root receives the left side of the node 
            root = found->left;
            return 1;
        }

        // referencia para o pai do lado esquerdo vai mudar
        /*----------------------------------------------*/
        // reference for the father on the left will change
        found->left->father = found->father;

        // se o dado do no for menor que o do pai...
        /*----------------------------------------*/
        // If the data is smaller than the father's ...
        if (found->data < found->father->data)
        {
            // o valor entra no lado esquerdo do pai
            /*-----------------------------------*/
            // The value enters in the left side of the parent
            found->father->left = found->left;
        }
        
        // caso contrario entra no lado direito
        /*------------*/
        // else enter in the right side
        else found->father->right = found->left;
        return 1;
    }

    // mesma logica do anterior
    /*-----------------------*/
    // same logic of the previous
    if (Node == 2)
    {
        if (isRoot(found))
        {
            root = found->right;
            return 1;
        }

        found->right->father = found->father;

        if (found->data < found->father->data)
        {
            found->father->left = found->right;
        }
        
        else found->father->right = found->right;
        return 1;
    }

    // se o grau for 3...
    /*-----------------*/
    // If grade is 3 ...
    if (Node == 3)
    {
        // declaro um auxiliar
        /*-------------------*/
        // declare an auxiliar
        node* aux = *tree;
        // declaro uma variavel que recebe o sucessor
        /*----------------------------------------*/
        // declara a variable the receives the sucessor
        node* Sucessor = sucessor(aux, found->data);

        // o valor do no eh trocado
        /*-----------------------*/
        // the value in the node is changed
        found->data = Sucessor->data;

        // o valor do sucessor eh passado novamente pare ser removido
        /*---------------------------------------------*/
        // The value of the sucessor is passed again to be removed
        removeNode(&aux, Sucessor->data);
    }

    return 1;
}
```

- “Node” é o resultado de uma função que verifica qual o tipo de nó:
    - 1 → Apenas nó esquerdo está presente.
    - 2 → Apenas nó direito está presente.
    - 3 → Os dois nós estão presentes.

## Conclusão

- Nesse readme você viu o básico sobre arvores binarias.
- Para que você entenda melhor sobre essa estrutura você pode ler a implementação do código e, além disso, eu recomendo o [material](https://joaoarthurbm.github.io/eda/) do professor João Arthur sobre essa e outras EDs.
