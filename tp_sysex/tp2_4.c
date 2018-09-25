#include <stdio.h>

int main(void) {
    int n, l, c, m;
    int tab[10][10] = {{0}};
    puts("Entrez N : ");
    do
    {
        scanf(" %d", &n);
    } while (n > 10 && n < 1);

    for (l=1; l != n+1; l++)
    {
        for (c=1; c != 11; c++)
        {
            tab[c - 1][l - 1] = l * c;
        }
    }
    for (l=0; l != n; l++)
    {
        printf("\n");
        for (c=0; c != 10; c++)
        {
            printf("| %3d ", tab[c][l]);
        }
        printf(" |\n");
        for (m = 0;m!=31;m++)
            printf("..");
    }

    return 0;
}
