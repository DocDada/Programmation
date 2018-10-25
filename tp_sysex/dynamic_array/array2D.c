#include "array2D.h"


/*****************************/
/*         FONCTIONS         */
/*          TABLEAU          */
/*             2D            */
/*****************************/

/*****************************/
/* input_array_dimension     */
/*                           */
/* the user enter the size   */
/* of the 2D array           */
/* (row and column)          */
/* return : void             */
/*****************************/
void input_array_dimension(unsigned int dimension[2])
{
    puts("Entrez le nombre de lignes de votre tableau 2D");
    input_array_size_v2(&dimension[0]);
    puts("Entrez le nombre de colonnes de votre tableau 2D");
    input_array_size_v2(&dimension[1]);
}

/*****************************/
/* alloc_2D_array            */
/*                           */
/* allocation of a 2D array  */
/*                           */
/* return : int **           */
/*****************************/
int ** alloc_2D_array(unsigned int dimension[2])
{
    int ligne;
    int ** array = (int **) malloc(dimension[0] * sizeof(int *));
    for (ligne = 0; ligne < dimension[0]; ligne++)
    {
        array[ligne] = (int *) malloc(dimension[1] * sizeof(int));
    }
    return array;
}

/*****************************/
/* alloc_2D_array_v2         */
/*                           */
/* allocation of a 2D array  */
/*                           */
/* return : void             */
/*****************************/
void alloc_2D_array_v2(int *** array, unsigned int dimension[2])
{
    int ligne;
    *array = (int **) malloc(dimension[0] * sizeof(int *));// tableau de pointeurs
    for (ligne = 0; ligne < dimension[0]; ligne++)
    {
        //*(*array+ligne) = (int *) malloc(dimension[1] * sizeof(int));
        (*array)[ligne] = (int *) malloc(dimension[1] * sizeof(int));// [] prioritaire sur *
    }
}

/*****************************/
/* fill_2D_array             */
/*                           */
/* the user enter the        */
/* elements of the array     */
/*                           */
/* return : void             */
/*****************************/
void fill_2D_array(int ** array, unsigned int dimension[2])
{
    int ligne;
    for (ligne = 0; ligne < dimension[0]; ligne++)
    {
        fill_array(array[ligne], dimension[1]);// remplit chaque ligne du tableau
    }
}


/*****************************/
/* display_2D_array          */
/*                           */
/* display the elements of   */
/* the array                 */
/*                           */
/* return : void             */
/*****************************/
void display_2D_array(int ** array, unsigned int dimension[2])
{
    int ligne;
    for (ligne = 0; ligne < dimension[0]; ligne++)
    {
        printf("Array[%d] : ", ligne);
        display_array(array[ligne], dimension[1]);// on affiche chaque ligne
    }
}


/*****************************/
/* free_2D_array             */
/*                           */
/* free a 2D array           */
/*                           */
/* return : void             */
/*****************************/
void free_2D_array(int ** array, unsigned int row)
{
    int ligne;
    for (ligne = 0; ligne < row; ligne++)
    {
        free_array(array[ligne]);// on desalloue chaque ligne
    }
    free(array);
}

