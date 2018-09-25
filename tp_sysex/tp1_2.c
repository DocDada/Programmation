#include <stdio.h>
#include <math.h>
int main(void)
{
	float a, b, c, delta, x1, x2;
	char choix = 'y';
	while(choix == 'y' || choix == 'Y')
	{
		puts("\n**Resolution d'un equation d'ordre 2 : ax^2 + bx + c = 0");
		printf("Valeur du coefficient a : ");
		scanf(" %f", &a);
		printf("Valeur du coefficient b : ");
		scanf(" %f", &b);
		printf("Valeur du coefficient c : ");
		scanf(" %f", &c);
		
		delta = (b * b) - 4 * a * c;
		printf("\ndelta vaut %.6f\n", delta);
		if(delta > 0)
		{
			puts("Le discriminant est positif, il existe deux solutions:");
			x2 = (-b - sqrt(delta)) / (2 * a);
			x1 = (-b + sqrt(delta)) / (2 * a);
			printf(" x1= %.6f\n", x1);
			printf(" x2= %.6f\n\n", x2);
		}
		else
		{
			puts("Le discriminant est negatif, il n'existe pas de solution.");
		}
		printf("Voulez-vous resoudre une autre equation ? y/n : ");
		scanf(" %c", &choix);
	}	
	return 0;
}
