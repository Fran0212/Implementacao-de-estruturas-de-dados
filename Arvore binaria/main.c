// gcc main.c binaryTree.c -o teste

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

/*========== PROTOTIPOS ==========*/
void menu(node* tree);
void userOpt(node* tree, int opt);
/*================================*/

int main(void)
{
    node* tree;

    startTree(&tree);

    menu(tree);
}

void menu(node* tree)
{
    int opt;
    printf(
    "\n"
    "[0] --> Para a execucao\n"
    "[1] --> Insere\n"
    "[2] --> Remove\n"
    "[3] --> printa a arvore\n"
    "[4] --> No com o valor maximo\n"
    "[5] --> No com o valor minimo\n"
    "[6] --> Procura um valor\n"
    "[7] --> altura da arvore\n"
    );

    printf("Insira sua opcao: ");
    scanf("%d\n", &opt);

    return userOpt(tree, opt);
}

void userOpt(node* tree, int opt)
{
    int data;

    switch (opt)
    {
    case 0:
        printf("Obrigado pelo uso!!\n");
        exit(0);
    case 1:
        printf("Diga qual dado a ser inserido: \n");
        scanf("%d", &data);

        insert(&tree, data);
        break;

    case 2:
        printf("Diga qual dado a ser removido: \n");
        scanf("%d", &data);

        removeNode(&tree, data);
        break;
    case 3:
        if (isEmpty(tree)) printf("Arvore vazia!\n");
        else printTree(tree);
        break;
    case 4:
        if (isEmpty(tree)) printf("Arvore vazia!\n");
        else printf("Pai do no: %d\nvalor do no: ¨%d", max(tree)->father->data, max(tree)->data);
        break;
    case 5:
        if (isEmpty(tree)) printf("Arvore vazia!\n");
        else printf("Pai do no: %d\nvalor do no: ¨%d", min(tree)->father->data, min(tree)->data);
        break;
    case 6:
        if (isEmpty(tree)) printf("Arvore vazia!\n");
        else
        {
            printf("Diga o dado a ser buscado: ");
            scanf("%d", &data);
            node* s = search(tree, data);
            printf("Pai do no: %d\nValor do no: %d\nEsquerda: %d\nDireita: %d", s->father->data, s->data, s->left->data, s->right->data);
        }
        break;
    case 7:
        if (isEmpty(tree)) printf("Arvore vazia!\n");
        else printf("Altura da arvore: %d\n", height(tree));
        break;
    default:
        printf("Opcao invalida!!");
        break;
    }

    menu(tree);
}