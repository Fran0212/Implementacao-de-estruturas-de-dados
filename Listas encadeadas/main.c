#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "linkedList.h"

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    node* list;
    startList(&list);

    menu(list);
}