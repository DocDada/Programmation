#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 100


// DECLARATION DES FONCTIONS
int mylen(char *s) ;
void reverse(char *s) ;
char* dernier_char(char *s) ;
char* dernier_char_v2(char *s) ;
void remplace_char(char *s, char c1, char c2) ;
char* premiere_occurence(char *s, char c) ;
int palindrome(char *s) ;
void maj_min(char *s) ;
char decalchar(char cara, int ajout) ;
void chiffrement_de_cesar(char *s, int decal) ;
void chiffrement_de_vigenere(char *s, char *cle, int crypt_decrypt) ;
void defi(char *s, int longueur, char *mot) ;


// MAIN
int main(int argc, char *argv[])
    {
    system("clear");
    char s[MAXCHAR] = "ta marine va tenir" ;

    // question 3
    printf("Question 3 : %s\n", s) ;

    // question 4
    s[0] = 'l' ;
    s[13] = 'v' ;
    printf("Question 4 : %s\n", s) ;

    // question 5
    char s2[MAXCHAR] ;

    // question 6
    strcpy(s2, "a Malte");
    printf("Question 5 : %s\n", s2) ;

    // question 7
    strcat(s, s2) ;
    printf("Question 7 : %s\n", s) ;

    // question 8
    int i ;
    for(i=strlen(s) ; i!=17 ; i--)//boucle décalant les char,laissant un espace
            s[i] = s[i - 1] ;
    s[18] = ' ' ;// ... pour insérer un espace entre "venir" et "a Malte"
    printf("Question 8 : %s\n", s) ;

    // question 9
    char s3[] = "abricot sec?" ;

    // question 10
    printf("Question 10 : strlen : %lu\n", strlen(s3)) ;
    // appel de la fonction strlen

    // question 11
    //char vide [] = "" ;
    printf("Question 11 : mylen : %d\n", mylen(s3)) ;
    // appel de la fonction mylen

    // question 12
    reverse(s);
    printf("Question 12 : %s\n", s) ;
    strcpy(s,"ta marine va tenir") ;
    reverse(s);
    printf("Question 12 : %s\n", s) ;

    // question 13
    char *dernier = dernier_char_v2(s3) ;
    printf("Question 13 : Avant : %s\n", s3);
    *dernier = '!' ;
    printf("Question 13 : Après : %s\n", s3);

    // question 14
    remplace_char(s3, 'c', 'z') ;
    printf("Question 14 : %s\n", s3) ;

    // question 15
    char *occurence = NULL ;
    occurence = premiere_occurence(s3, 'b');
    printf("Question 13 : Avant : %s\n", s3);
    *occurence = 'h' ;
    printf("Question 13 : Après : %s\n", s3);

    // question 16
    char pal[] = "";
    printf("Question 16 : %d\n", palindrome(pal)) ;

    // question 17
    char chihiro[] = "CHihIrO!" ;
    printf("Qestion 17 : Avant : %s\n", chihiro) ;
    maj_min(chihiro) ;
    printf("Qestion 17 : Avant : %s\n", chihiro) ;

    // question 18
    printf("Question 18 : %c\n", decalchar('z', 1)) ;

    // question 19
    char youpi[] = "youpilesvacances" ;
    chiffrement_de_cesar(youpi, 7) ;
    printf("Question 19 : %s\n", youpi) ;
    chiffrement_de_cesar(youpi, -7) ;
    printf("Question 19 : %s\n", youpi) ;

    // question 20
    char cle[] = "babar" ;
    chiffrement_de_vigenere(youpi, cle, 1) ;
    printf("Question 20 : chiffrement : %s\n", youpi) ;
    chiffrement_de_vigenere(youpi, cle, 0) ;
    printf("Question 20 : dechiffrement : %s\n", youpi) ;

    // question 21
    char a_dechiff[] = "zfwruwuovgvauulrogfbuybpqsevdvuuwr" ;
    char mot[] = "sparla" ;
    defi(a_dechiff, 6, mot) ;
    printf("Fin questions\n") ;
    //zfwruwuovgvauulrogfbuybpsevdvuuwr

    //
    return 0 ;
    }




/****************************/
/*                          */
/*                          */
/* DEFINITION DES FONCTIONS */
/*                          */
/*                          */
/****************************/



// question 11
// renvoie la longueur de la chaine s
int mylen(char *s)
    {
    int compteur = 0 ;
    for ( ; *s != '\0'; s++, compteur++) ;
    return compteur ;
    }

// question 12
// retourne/inverse une chaine de caractères
void reverse(char *s)
    {
    int i, longueur = strlen(s)/2 ;
    char stock ;
    for (i=0 ; i!= longueur ; i++)
        {
        stock = *(s+(strlen(s)-i-1)) ;
        // parenthèses obligatoires *( CHAINE + PAS )
        *(s+(strlen(s)-i-1)) = *(s+i) ;
        *(s+i) = stock ;
        }
    }

// question 13 version 1 (WHILE)
// renvoie un pointeur sur le dernier caractère
char* dernier_char(char *s)
    {
    while (*s != '\0')// *s == s[0] == *s+0
        s++ ;
    return --s ;//d'abord décrémente puis renvoie l'adresse sur le dernier char
    }

// question 13 : version 2 (FOR)
char* dernier_char_v2(char *s)
    {
    for ( ; *s != '\0' ; ++s);
    return --s;
    }

// question 14
// remplace tous les caractères c1 par les caractères c2
void remplace_char(char *s, char c1, char c2)
    {
    for ( ; *s != '\0' ; s++)
        if (*s == c1)
            *s = c2 ;
    }

// question 15
// renvoie un pointeur sur la premiere occurence du char c dans s
char* premiere_occurence(char *s, char c)
    {
    for ( ; *s != '\0' ; s++)
        if (*s == c)
            return s ;
    return NULL ;
    }

// question 16
// renvoie un booléen, indiquant si s est un palindrome
int palindrome(char *s)
    {
    int longueur = strlen(s)/2 - 1, compteur, vraie_longueur = strlen(s) - 1 ;
    for (compteur = 0 ; compteur != longueur ; compteur++)
        if (*(s+compteur) != *(s+vraie_longueur-compteur))
            return 0 ;// la chaine s n'est pas un palindrome
    return 1 ;// la chaine s est un palindrome
    }

// question 17
// change majuscule en minuscule
void maj_min(char *s)
    {
    for ( ; *s != '\0' ; s++)
        {
        if (*s>96 && *s<123)
            *s -= 32 ;
        else if (*s>64 && *s<91)
            *s += 32 ;
        }
    }

// question 18
// incrémente un caractère de ajout, selon la table ascii
char decalchar(char cara, int ajout)
    {
    if (cara + ajout < 97)
        cara = 122 - (96 - (cara + ajout)) ;
    else if (cara + ajout > 122)
        cara = 97 + ((cara + ajout) - 123);
    else if (cara + ajout>=97 && cara + ajout <= 122)
        cara = cara + ajout ;
    return cara ;
    }

// question 19
// chiffrement de césar
void chiffrement_de_cesar(char *s, int decal)
    {
    for ( ; *s != '\0' ; s++)
        *s = decalchar(*s, decal) ;
    }

// question 20
// chiffrement de vigenere
void chiffrement_de_vigenere(char *s, char *cle, int crypt_decrypt)
    {
    int i, longueur = strlen(cle) ;// dernière variable => obligatoire
    char *debut = cle ;
    for (i = 0 ; *s != '\0' ; i++, cle++, s++)
        {
        if (i == longueur)
            {
            cle = debut ;
            i = 0 ;
            }
        if (crypt_decrypt)
            *s = decalchar(*s, (*cle - 96)) ;// 96 pour la question 20
        else
            *s = decalchar(*s, -(*cle - 96)) ;// 96 pour la question 20
        }
    }

// question 21
// dechiffrement de zfwruwuovgvauulrogfbuybpqsevdvuuwr
void defi(char *s, int longueur, char *mot)
    {
    int i, j, compteur = 0 ;
    char *sh = s, stock, *debut = s+0, clee[longueur], *debutmot = mot+0 ;
    for ( ; *s != '\0' ; s = debut, mot = debutmot, compteur++)
        {
        if (compteur == 6)
            compteur = 0;
        for (i = 0 ; *s != '\0' && i != longueur ; i++, s++, mot++)
            {
            if (*s > *mot)
                clee[i] = (*s-(*mot)) + 96 ;
            else if (*s == *mot)
                clee[i] = 'z' ;
            else
                clee[i] = (122 - (*mot)) + (*s-97) + 97 ;
            }
        for (i = 0 ; i != compteur ; i++)
            {
            stock = clee[strlen(clee) - 1] ;
            for (j = strlen(clee) - 1 ; j != 0 ; j--)
                clee[j] = clee[j-1] ;
            clee[0] = stock ;
            }
        chiffrement_de_vigenere(sh, clee, 0) ;
        printf("phrase : %s\tclee : %s\n", sh, clee);
        chiffrement_de_vigenere(sh, clee, 1) ;
        debut++ ;
        }
    }






// FIN DU TP CHAINE
