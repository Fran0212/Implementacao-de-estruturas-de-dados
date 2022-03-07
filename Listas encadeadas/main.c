#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int leng;


    do
    {
        printf("Escolha a lingua /// Choose language\n");

        printf("1 para portugues /// 2 for english: _\b");

        scanf("%d", &leng);
        switch (leng)
        {
        case 1:
            printf("Nada por aqui, ainda, mas pode conferir meu linkedin -> https://www.linkedin.com/in/francisco-neto-a7618020a/");
            exit(0);

        case 2:
            printf("Nothing here, yet, but you may check my linkedin -> https://www.linkedin.com/in/francisco-neto-a7618020a/");
            exit(0);

        default:
            printf("Tente novamente // Try again");
            break;
        }
    } while (1);
}