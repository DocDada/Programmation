#include<stdio.h>
#include<string.h>



#define TAILLE_M 20


void truncate_by_adr(char *s, int p);
char* truncate_by_copy(char *s, int p);
void truncate_after_p(char *s, int p, char* s2);
void replace_char(char *s, char c1, char c2);



int main()
{
	int p;
	char ch[TAILLE_M], s2[TAILLE_M];
	puts("Votre chaine :");

    	fgets(ch, sizeof(ch), stdin);
    	char *anti = strchr(ch, '\n');
    	*anti = '\0' ;
	
	puts("Position de troncature :");
	do
	{
		scanf(" %d", &p);
	} while (p < 0 && p >= TAILLE_M);

	/*
	strncpy(s2, ch, p);// tronque par copie
	printf("s2 : %s\n", s2);
	printf("ch : %s\n", ch);
	truncate_by_adr(ch, p);
	printf("ch : %s\n", ch);
	*/
	truncate_after_p(ch, p, s2);
	printf("ch : %s\n", ch);
	printf("s2 : %s\n", s2);
	
	return 0;
}

void truncate_by_adr(char *s, int p)
{
	*(s + p) = '\0';
}

void truncate_after_p(char *s, int p, char* s2)
{
	for (; p < TAILLE_M; p++, s2++)
	{
		*(s2) = *(s + p);
	}
}

void replace_char(char *s, char c1, char c2)
{
    	for (; *s != '\0' ; s++)
        	if (*s == c1)
            		*s = c2 ;
}

