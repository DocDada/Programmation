#include "string_array.h"


/*******************************************/
/*        DEFINITIONS DES FONCTIONS        */
/*******************************************/


void init_string_array(StringArray *strar)
{
    strar->strings = NULL;
    strar->size = 0;

    return;
}


void alloc_string_array(StringArray *strar)
{
    int num;

    strar->strings = ((char **) malloc(sizeof(char *) * strar->size));

    for (num = 0; num != strar->size; num++)
    {
        strar->strings[num] = (char *) malloc(sizeof(char) * MAX_SIZE);
    }

    return;
}


void fill_string_array(StringArray *strar)
{
    int num;

    for(num = 0; num != strar->size; num++)
    {
        scanf(" %s", strar->strings[num]);
    }

    return;
}


void display_string_array(StringArray *strar)
{
    int num;

    for(num = 0; num != strar->size; num++)
    {
        printf("%s ", strar->strings[num]);
    }
    printf("\n");

    return;
}


void free_string_array(StringArray *strar)
{
    int num;

    for (num = 0; num != strar->size; num++)
    {
        free(strar->strings[num]);
    }

    free(strar->strings);

    return;
}

