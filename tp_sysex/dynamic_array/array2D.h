#ifndef ARRAY_2D
#define ARRAY_2D

#include<stdio.h>
#include<stdlib.h>
#include "array1D.h"


/*****************************/
/*        PROTOTYPES         */
/*            DES            */
/*         FONCTIONS         */
/*****************************/

// TABLEAU 2D
void test_array_2D();
void input_array_dimension(unsigned int dimension[2]);
int ** alloc_2D_array(unsigned int dimension[2]);
void alloc_2D_array_v2(int *** array, unsigned int dimension[2]);
void fill_2D_array(int ** array, unsigned int dimension[2]);
void display_2D_array(int ** array, unsigned int dimension[2]);
void free_2D_array(int ** array, unsigned int row);

#endif

