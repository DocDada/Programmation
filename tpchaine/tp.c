#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char decalchar(char c, int decal) ;
void chiffrement_de_cesar(char *s, int decal) ;
void decalchar_pointeur(char *c, int decal) ;
void chiffrement_de_vigenere(char *textToCrypt, char *key) ;
//void dechiffrement_de_vigenere(char *textToCrypt, char *key) ;
// void super_dechiffrement(char *crypte, char *s, int len_cle) ;

int main(int argc, char* argv[])
{
	char c , s2[30], s[] = "youpilesvacances" ;
	int decal ;
	printf("\nEntrer un caractere entre a et z : ");
	scanf("%c", &c) ;
	printf("\nEntrer un nombre : ") ;
	scanf("%d", &decal) ;
	printf("\ncaractere : %c ; ascii : %d\n", c, c) ;
	c = decalchar(c, decal) ;
	printf("\ncaractere : %c ; ascii : %d\n", c, c) ;
	
	puts("Question 19 : chiffrement de Cesar : ") ;
	chiffrement_de_cesar(s, decal) ;
	printf("%s\n", s) ;
	puts("\ndechiffrement : ") ;
	chiffrement_de_cesar(s, -decal) ;
	printf("%s\n", s) ;
	
	puts("Question 20 : chiffrement de Vigenere :") ;
	printf("\nEntrer une chaine de caracteres : ") ;
	scanf("%s", s2) ;
	chiffrement_de_vigenere(s, s2) ;
	printf("%s\n", s) ;
	//dechiffrement_de_vigenere(s, s2) ;
	printf("%s\n", s) ;
	
	// puts("Question 21 : dechiffrement :") ;
	// char crypte[] = "zfwruwuovgvauulrogfbuybpqsevdvuuw" ;
	// int len_cle = 6 ;
	// char mot[] = "sparla" ;
	// super_dechiffrement(crypte, mot, len_cle) ;
	// printf("%s\n", crypte) ;
	return 0 ;
}


char decalchar(char c, int decal)
{
	decal = decal%26 ;
	char z = 123, a = 97 ;
	if (c+decal<a)
		c = z - (a - (c+decal)) ;
	else if (c+decal>z)
		c = a + ((c+decal) - z) ;
	else
		c += decal ; 
	return c ;
}

void chiffrement_de_cesar(char *s, int decal)
{
	for ( ; *s != '\0' ; s++)
		decalchar_pointeur(s, decal) ;
}

void decalchar_pointeur(char *c, int decal)
{
	decal = decal%26 ;
	char z = 123, a = 97 ;
	if (*c+decal<a)
		*c = z - (a - (*c+decal)) ;
	else if (*c+decal>=z)
		*c = a + ((*c+decal) - z) ;
	else
		*c += decal ; 
}

// void chiffrement_de_vigenere(char *s, char *s2)
// {
	// char a = 96 ;
	// int *p = malloc(strlen(s2)) ;
	// if (p == NULL)
		// exit(0) ;
	// int *debut = p ;
	// int *fin = p+(strlen(s2)-1) ;
	// for ( p = debut ; *s2 != '\0' ; s2++, p++)
		// *p = ( *s2 - a ) ;
	// for ( p = debut ; *s != '\0' ; s++, p++)
	// {
		// if (p == fin)
			// p = debut ;
		// decalchar_pointeur(s, *p) ;
	// }
	// free(p) ;
// }
void chiffrement_de_vigenere(char *textToCrypt, char *key)
{
    char a = 'a' ;
    // On récupère la longueur de la clé
    int lenKey = strlen(key);
    int *decalages = (int*) malloc(lenKey) ;
    if (decalages == NULL)
        return;
    
    // # Partie de récupération des décalages
    int *debut = decalages;
    while(*key != '\0')
    {
        *decalages = ( *key - a );
        decalages++;
        key++;
    }
    
    // # Partie de chiffrement du texte clair
    int iKey;
    decalages = debut;
    while(*textToCrypt != '\0')
    {
        // Si on arrive à la fin de la clé, on revient au début (on boucle dessus)
        if (iKey >= lenKey) {
            decalages = debut ;
            iKey = 0;
        }
        decalchar_pointeur(textToCrypt, *decalages) ;
        textToCrypt++;
        decalages++;
        iKey++;
    }
    free(debut) ;
    free(decalages) ;
}
// void dechiffrement_de_vigenere(char *s, char *s2)
// {
	// char a = 96 ;
	// int decal[malloc(strlen(s2))] ;
	// int *p = malloc(strlen(s2)) ;
	// if (p == NULL)
		// exit(0) ;
	// int *debut = p ;
	// int *fin = p+(strlen(s2)-1) ;
	// for ( p = debut ; *s2 != '\0' ; s2++, p++)
		// *p = -( *s2 - a ) ;
	// for ( p = debut ; *s != '\0' ; s++, p++)
	// {
		// if (p == fin)
			// p = debut ;
		// decalchar_pointeur(s, *p) ;
	// }
	// free(p) ;
// }

// void super_dechiffrement(char *crypte, char *s, int len_cle)
// {
	// char a = 96 ;
	// int decal[malloc(strlen(s2))] ;
	// int *cle = &decal[0] ;
	// int *debut = &decal[0] ;
	// for (; *s2 != '\0' ; s2++, p++)
	// {
		
	// }
	// for ( ; *s != '\0' ; s++, cle++)
	// {
		// if (*cle == '\0')
			// cle = debut ;
		// decalchar_pointeur(crypte, *cle) ;
	// }
	// free(decal) ;
// }

/*void dechiffrement_de_vigenere(char *textToCrypt, char *key)
{
    char a = 'a' ;
    // On récupère la longueur de la clé
    int lenKey = strlen(key);
    int *decalages = malloc(lenKey) ;
    if (decalages == NULL)
        return;
    
    // # Partie de récupération des décalages
    int *debut = decalages;
    while(*key != '\0')
    {
        *decalages = -( *key - a );
        decalages++;
        key++;
    }
    
    // # Partie de chiffrement du texte clair
    int iKey;
    decalages = debut;
    while(*textToCrypt != '\0')
    {
        // Si on arrive à la fin de la clé, on revient au début (on boucle dessus)
        if (iKey >= lenKey) {
            decalages = debut ;
            iKey = 0;
        }
        decalchar_pointeur(textToCrypt, *decalages) ;
        textToCrypt++;
        decalages++;
        iKey++;
    }
    free(decalages) ;
}*/
