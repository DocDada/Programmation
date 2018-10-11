#include<stdio.h>
#include<stdlib.h>

/********************/
/*    PROTOTYPES    */
/*       DES        */
/*    FONCTIONS     */
/********************/

int input_array_size();
void input_array_size_v2(int * size);
int * alloc_1D_array(int size);
void alloc_1D_array_v2(int * array, int size);
void fill_array(int * array, int size);
void display_array(int * array, int size);
void free_array(int * array);




int main()
{
    int size = input_array_size();
    printf("TAILLE : %d\n", size);
    int * tab = alloc_1D_array(size);
    fill_array(tab, size);
    display_array(tab, size);
    free_array(tab);
    return 0;
}



/********************/
/*    DEFINITIONS   */
/*       DES        */
/*    FONCTIONS     */
/********************/


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
    } while (size <= 0);
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
void alloc_1D_array_v2(int * array, int size)
{
    array = (int *) malloc(size * sizeof(int));
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
    int i, input;
    for (i = 0; i < size; i++)
    {
        printf("Element %d : ", i);
        scanf(" %d", &input);
        *(array + i) = input;
    }
}


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

void free_array(int * array)
{
    free(array);
}



