#include "array1D.h"
#include "array2D.h"

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
    unsigned int size = input_array_size();
    printf("TAILLE : %d\n", size);
    int * tab = alloc_1D_array(size);
    */
    unsigned int size;
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
    unsigned int dimension[2];
    int ** array = NULL;
    input_array_dimension(dimension);
    printf("ROW : %d\tCOLUMN : %d\n", dimension[0], dimension[1]);
    //array = alloc_2D_array(dimension);
    alloc_2D_array_v2(&array, dimension);
    fill_2D_array(array, dimension);
    display_2D_array(array, dimension);
    free_2D_array(array, dimension[0]);
}


