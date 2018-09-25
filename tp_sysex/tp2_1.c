#include<stdio.h>


char decalchar(char cara, int ajout);
int testChar(char c);

int main(void)
{
	int n, type;
	char saisie;
	puts("Entrez un caractere");

	scanf(" %c", &saisie);
	
	puts("Entrez N");

	scanf(" %d", &n);
	printf("%c : %d\n", saisie, saisie);
	type = testChar(saisie);
	if (type == 1)
	{
		puts("Numerique");
	}
	else if (type == 2)
	{
		puts("Alphabetique");
	}
	else
	{
		puts("Autre");
	}
	saisie = decalchar(saisie, n);
	printf("%c\n", saisie);
	return 0;
}


int testChar(char c)
{
	if (c >= 48 && c <= 57)
	{
		return 1;
	}
	else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return 2;
	}
	return 3;
}


char decalchar(char cara, int ajout)
{
	int d, f, t = testChar(cara);
	if (t == 3 || t == 1)
	{
		return cara;
	}
	if (cara >= 97 && cara <= 122)
	{
		d = 97;
		f = 122;
	}
	else
	{
		d = 65;
		f = 90;
	}
    	if (cara + ajout < d)
        	cara = f - (d - 1 - (cara + ajout));
    	else if (cara + ajout > f)
        	cara = d + ((cara + ajout) - f - 1);
    	else if (cara + ajout >= d && cara + ajout <= f)
        	cara = cara + ajout;
    	return cara ;
}

