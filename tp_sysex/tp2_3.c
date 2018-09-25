#include<stdio.h>
#include<string.h>

#define TAILLE 50


int count_max_id_chars(char *s);



int main()
{
	int c;
	char nom[TAILLE];
    	fgets(nom, sizeof(nom), stdin);
    	char *anti = strchr(nom, '\n');
    	*anti = '\0';

	c = count_max_id_chars(nom);
	printf("Nombre d'iterations max : %d\n", c);
	return 0;
}

int count_max_id_chars(char *s)
{
	int c = 0, c_max = 0;
	char s2 = *s;
	for(; *s != '\0'; s++)
	{
		if (*s == s2)
		{
			c++;
		}
		else if (c > c_max)
		{
			c_max = c;
			c = 0;
		}
	}
	return c_max;
}

