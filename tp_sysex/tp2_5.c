#include <stdio.h>

#define T_MAX 10

int test_dim(int c, int l, int c2, int l2);
void input_dim(int* c, int* l);
void input_contents(int tab[T_MAX][T_MAX], int c, int l);
void pre_print_matrix(int tab[T_MAX][T_MAX], int c, int l);
int sum_matrix(int t[T_MAX][T_MAX], int t2[T_MAX][T_MAX], int t3[T_MAX][T_MAX], int c, int l, int c2, int l2);
int mult_matrix(int t[T_MAX][T_MAX], int t2[T_MAX][T_MAX], int t3[T_MAX][T_MAX], int c, int l, int c2, int l2);
void pre_print(int t[T_MAX][T_MAX], int t2[T_MAX][T_MAX], int t3[T_MAX][T_MAX], int c, int l, int c2, int l2, int c3, int l3);

int main(void)
{
    char s;
    int mat1[T_MAX][T_MAX] = {{0}}, mat2[T_MAX][T_MAX] = {{0}}, mat3[T_MAX][T_MAX] = {{0}};
    int c1, c2, l1, l2, erreur = 1;

    // On entre les dimensions des matrices
    input_dim(&c1, &l1);
    input_dim(&c2, &l2);

    // on entre le contenu des matrices
    input_contents(mat1, c1, l1);
    input_contents(mat2, c2, l2);



    // on demande a l'utilisateur s'il veut faire la somme ou le produit
    // de 2 matrices
    do
    {
        puts("Somme ou produit ? S/s/P/p : ");
        scanf(" %c", &s);
    } while (s != 's' && s != 'S' && s != 'P' && s != 'p');

    switch (s)
    {
        case 'S': case 's':
            erreur = sum_matrix(mat1, mat2, mat3, c1, l1, c2, l2);
            puts("\nSomme matricielle :");
            break;
        case 'P': case 'p':
            erreur = mult_matrix(mat1, mat2, mat3, c1, l1, c1, l1);
            puts("\nProduit matriciel :");
        default:
            break;
    }

    if (erreur != 0)// si le produit ou la somme est possible, on affiche
    {
        pre_print(mat1, mat2, mat3, c1, l1, c2, l2, c2, l1);// avec beaute
    }
    return 0;
}

int test_dim(int c, int l, int c2, int l2)
{
    if (c == c2 && l == l2)
        return 1;
    return 0;
}

void input_dim(int* c, int* l)
{
    puts("Entrez les dimensions de la matrice : ");
    do
    {
        printf("Colonnes : ");
        scanf(" %d", c);
    } while (*c <= 0 && *c >= T_MAX);
    do
    {
        printf("Lignes : ");
        scanf(" %d", l);
    } while (*l <= 0 && *l >= T_MAX);
}

void input_contents(int tab[T_MAX][T_MAX], int c, int l)
{
    int i, j;
    puts("Entrez le contenu de la matrice case par case");
    for (i = 0; i != l; i++)
    {
        for (j = 0; j != c; j++)
        {
            printf("Ligne %d Colonne %d : ", i, j);
            scanf(" %d", &tab[i][j]);
        }
    }
}

void pre_print_matrix(int tab[T_MAX][T_MAX], int c, int l)
{
    int i, j;
    printf("--");
    for (i = 0; i < (c*2 + c%1); i++)
        printf(" ");
    puts("--");
    for (i = 0; i != l; i++)
    {
        printf("|");
        for (j = 0; j != c; j++)
        {
            if (j != c - 1)
                printf("%2d ", tab[i][j]);
            else
                printf("%2d", tab[i][j]);
        }
        printf("|\n");
    }

    printf("--");
    for (i = 0; i < (c*2 + c%1); i++)
        printf(" ");
    puts("--");
}

int sum_matrix(int t[T_MAX][T_MAX], int t2[T_MAX][T_MAX], int t3[T_MAX][T_MAX], int c, int l, int c2, int l2)
{
    if (test_dim(c, l, c2, l2) == 0)
        return 0;
    int i, j;
    for (i = 0; i != l; i++)
    {
        for (j = 0; j != c; j++)
        {
            t3[i][j] = t[i][j] + t2[i][j];
        }
    }
    return 1;
}

int mult_matrix(int t[T_MAX][T_MAX], int t2[T_MAX][T_MAX], int t3[T_MAX][T_MAX], int c, int l, int c2, int l2)
{
    if (c != l2)
    {
        puts("Le produit matriciel n'est pas possible.");
        return 0;// error
    }
    int i, j, aij = 0, z;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (z = 0; z < c; z++)
            {
                aij += t[i][z] * t2[z][j];
            }
        t3[i][j] = aij;
        aij = 0;
        }
    }
    return 1;
}

void pre_print(int t[T_MAX][T_MAX], int t2[T_MAX][T_MAX], int t3[T_MAX][T_MAX], int c, int l, int c2, int l2, int c3, int l3)
{
    int i, j, e;
    for (e = 0; e != (c*2 + c%1 + 6); e++)
        printf(" ");
    printf("--");
    for (i = 0; i < (c2*2 + c2%1); i++)
        printf(" ");
    puts("--");
    for (i = 0; i != l2; i++)
    {
        for (e = 0; e != (c*2 + c%1 + 6); e++)
            printf(" ");
        printf("|");
        for (j = 0; j != c2; j++)
        {
            if (j != c - 1)
                printf("%2d ", t2[i][j]);
            else
                printf("%2d", t2[i][j]);
        }
        printf("|\n");
    }
    for (e = 0; e != c*2 + c%1 + 6; e++)
        printf(" ");
    printf("--");
    for (i = 0; i < (c2*2 + c2%1); i++)
        printf(" ");
    puts("--");




    printf("--");
    for (i = 0; i < (c*2 + c%1); i++)
        printf(" ");
    printf("--  ");

    printf("--");
    for (i = 0; i < (c3*2 + c3%1); i++)
        printf(" ");
    puts("--");

    for (i = 0; i != l; i++)
    {
        printf("|");
        for (j = 0; j != c; j++)
        {
            if (j != c - 1)
                printf("%2d ", t[i][j]);
            else
                printf("%2d", t[i][j]);
        }
        printf("|  ");

        printf("|");
        for (j = 0; j != c3; j++)
        {
            if (j != c3 - 1)
                printf("%2d ", t3[i][j]);
            else
                printf("%2d", t3[i][j]);
        }
        printf("|\n");
    }

    printf("--");
    for (i = 0; i < (c*2 + c%1); i++)
        printf(" ");
    printf("--  ");

    printf("--");
    for (i = 0; i < (c3*2 + c3%1); i++)
        printf(" ");
    puts("--");
}


