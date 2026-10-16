#include <stdio.h>

#define NB_VALEURS 3

int main(void)
{
    int valeurs[NB_VALEURS] = {8, 4, 12};

    for (int i = 0; i < NB_VALEURS; i++)
    {
        printf("| ");

        for (int j = 0; j < valeurs[i]; j++)
        {
            printf("x");
        }

        printf(" %d\n", valeurs[i]);
    }

    printf("+-----------------------------------------------\n");

    return 0;
}
