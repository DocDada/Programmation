#ifndef ARRAY_1D
#define ARRAY_1D


#include<stdio.h>
#include<stdlib.h>


/*****************************/
/*        PROTOTYPES         */
/*            DES            */
/*         FONCTIONS         */
/*****************************/

// TABLEAU 1D
void test_array_1D();
unsigned int input_array_size();
void input_array_size_v2(unsigned int * size);
int * alloc_1D_array(unsigned int size);
void alloc_1D_array_v2(int ** array, unsigned int size);
void fill_array(int * array, unsigned int size);
void display_array(int * array, unsigned int size);
void free_array(int * array);

#endif

