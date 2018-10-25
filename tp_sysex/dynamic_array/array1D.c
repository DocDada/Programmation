#include "array1D.h"


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
/* return : unsigned int     */
/*****************************/
unsigned int input_array_size()
{
    unsigned int size;
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
void input_array_size_v2(unsigned int * size)
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
/* return : unsigned int *   */
/*****************************/
int * alloc_1D_array(unsigned int size)
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
void alloc_1D_array_v2(int ** array, unsigned int size)
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
void fill_array(int * array, unsigned int size)
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
void display_array(int * array, unsigned int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("[%d] %d ", i, *(array + i));
    }
    printf("\n");
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




