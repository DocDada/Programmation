#ifndef STRING_ARRAY
#define STRING_ARRAY


#include <stdio.h>
#include <string.h>
#include "array1D.c"


#define MAX_SIZE 20// maximum size of a string


typedef struct StringArray
{
    unsigned int size;
    char **strings;
} StringArray;


/******************************************/
/*        PROTOTYPES DES FONCTIONS        */
/******************************************/


void init_string_array(StringArray *strar);
void alloc_string_array(StringArray *strar);
void fill_string_array(StringArray *strar);
void display_string_array(StringArray *strar);
void free_string_array(StringArray *strar);


#endif

