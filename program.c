#include <stdio.h>

#define NB_VALEURS 3
#define MAX_LONGUEUR 50
#define MAX_LIGNES 15

// Affiche une ligne de l'histogramme vertical
void afficher_ligne_histov(int valeurs[], int taille, int y)
{
    printf("| ");

    for (int i = 0; i < taille; i++) {
        if (valeurs[i] >= y) {
            printf("xxx");
        } else {
            printf("   ");
        }

        printf(" ");
    }

    printf("\n");
}

int main(void)
{
    int valeurs[NB_VALEURS] = { 8, 4, 12 };

    //Recherche du maximum
    int maximum = valeurs[0];

    for (int i = 1; i < NB_VALEURS; i++) {
        if (valeurs[i] > maximum) {
            maximum = valeurs[i];
        }
    }

    
    // ÉTAPE 1 ET 2 : HORIZONTAL
    

    float echelle = (float)MAX_LONGUEUR / maximum;

    for (int i = 0; i < NB_VALEURS; i++) {

        int nb_croix = (int)(valeurs[i] * echelle);

        printf("| ");

        for (int j = 0; j < nb_croix; j++) {
            printf("x");
        }

        printf(" %d\n", valeurs[i]);
    }

    printf("+-");

    for (int j = 0; j < MAX_LONGUEUR; j++) {
        printf("-");
    }

    printf("\n\n");

    // ÉTAPE 3 : VERTICAL

    /*
       Calcul de y :
       y = maximum - (maximum / MAX_LIGNES) * i

       On utilise un float pour obtenir les valeurs
       intermédiaires comme dans l'énoncé. */


    for (int i = 0; i < MAX_LIGNES; i++) {

        float y = maximum - ((float)maximum / MAX_LIGNES) * i;

        afficher_ligne_histov(valeurs, NB_VALEURS, y);
    }

    // Axe horizontal de l'histogramme vertical
    printf("+");

    for (int i = 0; i < NB_VALEURS * 4; i++) {
        printf("-");
    }

    printf("\n");

    return 0;
}
