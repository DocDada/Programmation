#include<stdio.h>
#include<stdlib.h>



/*****************************/
/*        PROTOTYPES         */
/*            DES            */
/*         FONCTIONS         */
/*****************************/

// TABLEAU 1D
void test_array_1D();
int input_array_size();
void input_array_size_v2(int * size);
int * alloc_1D_array(int size);
void alloc_1D_array_v2(int ** array, int size);
void fill_array(int * array, int size);
void display_array(int * array, int size);
void free_array(int * array);

// TABLEAU 2D
void test_array_2D();
void input_array_dimension(int dimension[2]);
int ** alloc_2D_array(int dimension[2]);
void alloc_2D_array_v2(int *** array, int dimension[2]);
void fill_2D_array(int ** array, int dimension[2]);
void display_2D_array(int ** array, int dimension[2]);
void free_2D_array(int ** array, int dimension[2]);



/*****************************/
/*                           */
/*            MAIN           */
/*                           */
/*****************************/
int main(int argc, char* argv[])
{
    // test_array_1D();
    test_array_2D();
    return 0;
}



/*****************************/
/*        DEFINITIONS        */
/*            DES            */
/*         FONCTIONS         */
/*****************************/

void test_array_1D()
{
    /*
    int size = input_array_size();
    printf("TAILLE : %d\n", size);
    int * tab = alloc_1D_array(size);
    */
    int size;
    int * tab = NULL;
    input_array_size_v2(&size);
    printf("TAILLE : %d\n", size);
    alloc_1D_array_v2(&tab, size);
    fill_array(tab, size);
    display_array(tab, size);
    free_array(tab);
}

void test_array_2D()
{
    int dimension[2];
    int ** array = NULL;
    input_array_dimension(dimension);
    printf("ROW : %d\tCOLUMN : %d\n", dimension[0], dimension[1]);
    //array = alloc_2D_array(dimension);
    alloc_2D_array_v2(&array, dimension);
    fill_2D_array(array, dimension);
    display_2D_array(array, dimension);
    free_2D_array(array, dimension);
}


/*****************************/
/*         FONCTIONS         */
/*          TABLEAU          */
/*             1D            */
/*****************************/

/*****************************/
/* input_array_size          */
/*                           */
/* the user enter the size   */
/* of the array              */
/* return : int              */
/*****************************/
int input_array_size()
{
    int size;
    do
    {
        puts("Enter size of array : ");
        scanf(" %d", &size);
    } while (size <= 0);
    return size;
}

/*****************************/
/* input_array_size_v2       */
/*                           */
/* the user enter the size   */
/* of the array              */
/* return : void             */
/*****************************/
void input_array_size_v2(int * size)
{
    do
    {
        puts("Enter size of array : ");
        scanf(" %d", size);
    } while (*size <= 0);
}

/*****************************/
/* alloc_1D_array            */
/*                           */
/* allocation of an array    */
/*                           */
/* return : int *            */
/*****************************/
int * alloc_1D_array(int size)
{
    return (int *) malloc(size * sizeof(int));
}

/*****************************/
/* alloc_1D_array_v2         */
/*                           */
/* allocation of an array    */
/*                           */
/* return : void             */
/*****************************/
void alloc_1D_array_v2(int ** array, int size)
{
    *array = (int *) malloc(size * sizeof(int));
}

/*****************************/
/* fill_array                */
/*                           */
/* the user enter the        */
/* elements of the array     */
/* return : void             */
/*****************************/
void fill_array(int * array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Element %d : ", i);
        scanf(" %d", &array[i]);
    }
}


/*****************************/
/* display_array             */
/*                           */
/* display the elements of   */
/* the array                 */
/* return : void             */
/*****************************/
void display_array(int * array, int size)
{
    int i;
    puts("Elements of array :");
    for (i = 0; i < size; i++)
    {
        printf("%d, ", *(array + i));
    }
    printf(";\n");
}

/*****************************/
/* free_array                */
/*                           */
/* free the array            */
/*                           */
/* return : void             */
/*****************************/
void free_array(int * array)
{
    free(array);
}





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
void input_array_dimension(int dimension[2])
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
int ** alloc_2D_array(int dimension[2])
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
void alloc_2D_array_v2(int *** array, int dimension[2])
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
void fill_2D_array(int ** array, int dimension[2])
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
void display_2D_array(int ** array, int dimension[2])
{
    int ligne;
    for (ligne = 0; ligne < dimension[0]; ligne++)
    {
        printf("ROW %d : ", ligne);
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
void free_2D_array(int ** array, int dimension[2])
{
    int ligne;
    for (ligne = 0; ligne < dimension[0]; ligne++)
    {
        free_array(array[ligne]);// on desalloue chaque ligne
    }
    free(array);
}

