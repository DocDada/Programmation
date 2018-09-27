#include<stdio.h>

#define T_MAX 10


void pre_print(int tab[T_MAX]);




int main()
{
    int poly[T_MAX] = {0}, i;
    puts("Entrez les coefficients du polynome : ");
    for (i = 0; i < T_MAX; i++)
    {
        scanf(" %d", poly+i);
    }
    pre_print(poly);
    return 0;
}

void pre_print(int tab[T_MAX])
{
    int i;
    for (i = 0; i < T_MAX; i++)
    {
        if (*(tab+i) == 0)
            continue;
        printf("%+dX^%d", *(tab+i), i);
    }
}

