/*****************************************/
/*               MORPION                 */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define symboleO 'O'
#define symboleX 'X'
#define VIDE ' '
#define N 3
#define LIMITE N*N


/*************************/
/*                       */
/*      STRCUTURES       */
/*                       */
/*************************/
typedef struct Joueur
    {
    char nom[12] ;
    char symbole ;
    } Joueur ;

typedef struct Partie
    {
    char plateau[N][N] ;
    int nbtours ;
    } Partie ;


/*************************/
/*                       */
/*   DECLARATION  DES    */
/*      FONCTIONS        */
/*                       */
/*************************/
void nomJoueur(Joueur J[2]) ;
void afficheMorpion(char (*plateau)[N]);
void initTableauMorpion(Partie *partie) ;
int verifieCoordonnees(int lig, char col);
int verifieCaseVide(char plateau[N][N], int lig, char col);
int verifieConditionVictoire(char plateau[N][N], char symbole);
int joueTour(Joueur J, Partie *partie, int* lig, char* col) ;


/*************************/
/*                       */
/*         MAIN          */
/*                       */
/*************************/
int main(int argc, char *argv[])
    {
    Partie partie ;
    char col ;
    int lig, joueur, statut ;
    Joueur J[2] ;
    nomJoueur(J) ;// les 2 joueurs donnent leurs noms

    initTableauMorpion(&partie) ;

    while(1)// tant qu'il n y a pas de gagnant ou
            // que toutes les cases ne sont remplies
        {
        for (joueur = 0 ; joueur != 2 ; joueur++)
            // les joueurs jouent chacun leur tour
            {
            afficheMorpion(partie.plateau) ;
            statut = joueTour(J[joueur], &partie, &lig, &col);
            // un joueur joue et on regarde s'il ...
            if (statut == 1)// ... a gagné
                {
                printf("%s A GAGNE\n", J[joueur].nom);
                return 0 ;
                }
            else if (statut == 3)// ... ou s'il y a égalité ...
                {
                puts("EGALITE ...") ;
                return 0 ;
                }// ... sinon le jeu continue
            }
        }// fin du jeu / fin de boucle

    return 0;
    }




/*************************/
/*                       */
/*   DEFINITIONS DES     */
/*       FONCTIONS       */
/*                       */
/*************************/

/******************************/
/*  FONCTION afficheMorpion   */
/* affiche un morpion         */
/* INPUT : plateau (pointeur) */
/* OUPUT : neant              */
/******************************/
void afficheMorpion(char (*plateau)[N])
    {
    int i, j ;
    char col ;
    printf(" ");
    for(col = 'a' ; col < 'a'+N ; col++)//affiche a b c ...
        printf("  %c ", col) ;
    printf("\n ") ;

    for(i = 0 ; i != N ; i++, plateau++)// délimite
        {
        for(j = 0 ; j != ( (N+1)+N*3 ) ; j++)
            printf("-") ;

        puts("") ;
        printf("%d", i+1) ;
        // affiche 1 2 3 ... N, l'un en dessous de l'autre
        for(j = 0 ; j != N ; j++)
            printf("| %c ", (*plateau)[j]) ;
        // affiche cases du morpion (O / X / espace)

        printf("| \n ") ;
        }

    for(j = 0 ; j != ( (N+1)+N*3 ) ; j++)//délimite (esthétique)
        // pas dans la boucle(longueur=3), car délimitations == 4
        printf("-") ;
    puts("") ;
    }



/***********************************************/
/* FONCTION initTableauMorpion(Partie *partie) */
/* initialise un morpion ainsi que le nombre   */
/* de tours                                    */
/* INPUT : Partie (pointeur)                   */
/* OUPUT : neant                               */
/***********************************************/
void initTableauMorpion(Partie *partie)
    {
    int lig, col ;
    for(lig = 0 ; lig != N+1 ; lig++)// != moins chere que <
        for (col = 0 ; col != N+1 ; col++)
            partie->plateau[lig][col] = VIDE ;
    // toutes les case du tableau sont des espaces au début
    partie->nbtours = 0 ;// le nombre de tours équivaut à 0 en début de partie
    }

/***********************************************/
/*         FONCTION verifieCoordonnees         */
/* vérifie si les coordonnées sont conformes   */
/* INPUT : ligne et colonne (entier et char)   */
/* OUPUT : booléen                             */
/***********************************************/
int verifieCoordonnees(int lig, char col)
    {
    if((lig>0 && lig<=N) && (col<(97+N) && col>=97))
        // vérifie si les coordonnées sont entre 1 et N et a et (a+N)
        return 1;// les critères sont respectés
    else
        return 0;
    // critères pas respectés, on redemande au joueur de rentrer les valeurs
    }
/***********************************************/
/*         FONCTION verifieCaseVide            */
/* vérifie si la case est vide                 */
/* INPUT : ligne et colonne (entier et char)   */
/* plateau (morpion)                           */
/* OUPUT : booléen                             */
/***********************************************/
int verifieCaseVide(char plateau[N][N], int lig, char col)
    {
    if(plateau[lig - 1][col - 'a'] == VIDE)// la case est vide
        return 1;
    else
        return 0;
    }

/***********************************************/
/*    FONCTION verifieConditionVictoire        */
/* vérifie si le joueur a gagné                */
/* INPUT : symbole du joueur (char)            */
/* plateau (morpion)                           */
/* OUPUT : booléen                             */
/***********************************************/
int verifieConditionVictoire(char plateau[N][N], char symbole)
    {
    int verti_ou_horiz, lig, col ;
    for (lig = 0, col = 0 ; (plateau[col][lig] != '\0') && plateau[col][lig] == symbole ; col++, lig++);
    // diagonale haut-gauche -> bas-droite
    if (col == N && lig == N)
        return 1 ;
    for (lig = N-1, col = 0 ; (plateau[col][lig] != '\0') && plateau[col][lig] == symbole ; lig++, col--);
    // l'autre diagonale
    if (col == N && lig == N)
        return 1 ;
    for(verti_ou_horiz=0 ; verti_ou_horiz<=N-1 ; verti_ou_horiz++)
        // on regarde si le joueur a mis ses symboles sur toute ...
        {
        for (lig = 0 ; (plateau[lig][verti_ou_horiz] != '\0') && plateau[lig][verti_ou_horiz] == symbole ; lig++);
        // ... une ligne ou ...
        for (col = 0 ; (plateau[verti_ou_horiz][col] != '\0') && plateau[verti_ou_horiz][col] == symbole ; col++);
        // ... sur toute une colonne
        if (lig == N || col == N)
        // si a chaque test on trouvé le symbole du joueur
            return 1 ;// alors le joueur a gagné
        }
    return 0;// le joueur n'a pas gagné
    }

/***********************************************/
/*    FONCTION nomJoueur                       */
/* demande le nom des joueurs                  */
/* INPUT : tableau de joueurs (2)              */
/* OUPUT : néant                               */
/***********************************************/
void nomJoueur(Joueur J[2])
    {
    system("clear");// on efface le terminal
    printf("Nom du joueur 1 :\t");
    fgets(J[0].nom, sizeof(J[0].nom), stdin);// on récupère l'entrée standard
    char *anti = strchr(J[0].nom, '\n');
    *anti = '\0' ;
    J[0].symbole = symboleO ;// on assigne le symbole O
    printf("Nom du joueur 2 :\t");
    fgets(J[1].nom, sizeof(J[1].nom), stdin);
    anti = strchr(J[1].nom, '\n');
    *anti = '\0' ;
    J[1].symbole = symboleX ;// on assigne le symbole X
    }


/***********************************************/
/*             FONCTION joueTour               */
/* le joueur entre des coordonnées             */
/* vérifie si les coord. sont conformes        */
/* vérifie si case vide                        */
/* vérifie si le joueur gagne                  */
/* vérifie si le plateau est complété          */
/* INPUT : Joueur J, Partie (pointeur)         */
/* ligne et colonne (entier et char)           */
/* (tous deux pointeurs)                       */
/* OUPUT : entier (0, 1, 3)                    */
/***********************************************/
int joueTour(Joueur J, Partie *partie, int *lig, char* col)
    {
    char str[100];
    int nbArgument ;
    do
        {
        printf("Joueur %s (ligne colonne): ", J.nom) ;
        fgets(str, 100, stdin) ;// le joueur entre les coordonnées
        nbArgument = sscanf(str, "%d%c", lig, col) ;
        }
    while(nbArgument!=2 && (!verifieCoordonnees(*lig, *col) || !verifieCaseVide(partie->plateau, *lig, *col)) );
    // tant que la case est vide ou que les coordonnées entrées ...
    // ne sont conformes, redemander à l'utilsateur les coordonnées
    partie->plateau[(*lig)-1][(*col)-'a'] = J.symbole;
    // une fois la boucle passée, on affiche ...
    // le symbole du joueur dans la case selectionnée
    (partie->nbtours)++;// le joueur a joué son tour

    if (verifieConditionVictoire(partie->plateau, J.symbole))
        return 1 ;
    if (partie->nbtours >= LIMITE)// si toutes les cases sont remplies ...
        return 3;
    return 0;
    }




// FIN MORPION
