#include<stdio.h>

int main(void)
{
	int nbrArt;
	float prixHT, tva = 0.196;
	float ttc;
	char nbAr[] = "nombre d'articles";
	char prixht[] = "prix HT";
	char prixttc[] = "prix TTC";

	do
	{
		printf("nombre d'articles : ");
		scanf(" %d", &nbrArt);
	} while(nbrArt < 0);
	do
	{
		printf("prix HT : ");
		scanf(" %f", &prixHT);
	} while(prixHT < 0);

	ttc = nbrArt * prixHT;
	ttc += ttc * tva;
	
	printf("%-19s : %5d\n", nbAr, nbrArt);
	printf("%-19s : %8.2f\n", prixht, prixHT);
	printf("%-19s : %8.2f\n", prixttc, ttc);

	return 0;
}
