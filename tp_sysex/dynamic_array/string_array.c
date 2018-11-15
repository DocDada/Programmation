#include<stdio.h>
#include "array1D.c"
#define T 20
#include<string.h>

typedef struct StringArray
{
    unsigned int size;
    char ** strings;
} StringArray;


void init_string_array(StringArray * strar);
void alloc_string_array(StringArray * strar);
void input_string(char * string);
void fill_string_array(StringArray * strar);
void display_string_array(StringArray * strar);
//void free_string_array(char ** strings);
void free_string_array(StringArray * strar);

int main(int argc, char * argv[])
{
    StringArray strar;

    init_string_array(&strar);
    input_array_size_v2(&(strar.size));
    alloc_string_array(&strar);

    //printf("%d\n", strar.size);
    //(strar.strings)[0] = "Paul";
    //printf("%s\n", strar.strings[0]);
    //printf("%d\n", strar.size);

    fill_string_array(&strar);
    display_string_array(&strar);

    free_string_array(&strar);

    return 0;
}

void init_string_array(StringArray * strar)
{
    strar->strings = NULL;
    strar->size = 0;
}


void alloc_string_array(StringArray * strar)
{
    int num;

    strar->strings = ((char **) malloc(sizeof(char *) * strar->size));

    /*for (num = 0; num != strar->size; num++)
    {
        strar->strings[num] = (char *) calloc(100, 1);
    }*/

    return;
}

/*
void alloc_string_array(StringArray *** str)
{
    int num;
    *str = (char **) malloc(sizeof(char *));// tableau de pointeurs
    for (num = 0; num < str.size; num++)
    {
        (*array+ligne) = (int *) malloc(dimension[1] * sizeof(int));
        (*array)[ligne] = (char *) malloc(str.size * sizeof(char));// [] prioritaire sur *
    }
}

*/

void input_string(char * string)
{
    printf("Enter a string : ");
    /*fgets(*string, sizeof(*string), stdin);// ERREUR
    printf("Je passe par la ");
    char * anti = strchr(*string, '\n');
    *anti = '\0';
*/
    char name[10];
    scanf(" %s", name);
    string = name;
    return;
}

void fill_string_array(StringArray * strar)
{
    int num;
    char name[10];

    for(num = 0; num != strar->size; num++)
    {
        puts("Enter ");
        //strar->strings[num] = "Poulpy";
        //input_string(strar->strings[num]);
        scanf(" %s", name);
        strcpy(strar->strings[num], name);
        //strar->strings[num] = name;
    }

    return;
}


void display_string_array(StringArray * strar)
{
    int num;

    puts("NOMS");
    for(num = 0; num != strar->size; num++)
    {
        printf("%s\n", strar->strings[num]);
    }

    return;
}






void free_string_array(StringArray * strar)
{
    /*int num;
    for (num = 0; num != strar->size; num++)
    {
        free(strar->strings[num]);
    }*/
    free(strar->strings);
}


