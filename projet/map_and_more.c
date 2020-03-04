#include <stdio.h>
#include <stdlib.h>


int     ***map_create(int ***map,int sizeofmap)
{
    int     colonne;
    int     ligne;


    colonne = sizeofmap;
    ligne = sizeofmap;

    /*Partie malloc*/
    /*elle conciste a creer un espace mémoire dedie a la map dans le jeu.
    cette map aura la forme d'un carre de taille "sizeofmap", avec dans chaque case du quadrillage ,
    2 valeurs: qu'es qui s'y trouve, et si un evenement s'y est passee*/

    if (!(map = (int***)malloc(sizeof(int**) * sizeofmap)))
        return (0);
    while (colonne)
    {
        if (!(map[sizeofmap - colonne] = (int**)malloc(sizeof(int*) * sizeofmap )))
            return (0);
        while (ligne)
        {
            //printf("%d , %d\n",sizeofmap - colonne,sizeofmap - ligne);
            if (!(map[sizeofmap - colonne][sizeofmap - ligne] = (int*)malloc(sizeof(int) * 2)))
            {
                //printf("not malloc");
                return (0);
            }
            map[sizeofmap - colonne][sizeofmap - ligne][0] = 0;
            map[sizeofmap - colonne][sizeofmap - ligne][1] = 0;
            //printf("->%d, %d\n",map[sizeofmap - colonne][sizeofmap - ligne][0],map[sizeofmap - colonne][sizeofmap - ligne][1]);
            //printf("malloc done\n");
            ligne --;
        }

        ligne = sizeofmap;
        colonne--;
    }
    map[4][4][1]=1;
    //printf("malloc complete\n");
    return map;
}

void    show_map(int ***map,int sizeofmap)
{
    int     i = 0;
    int     j = 0;

    system("cls");
    printf("\nvous etes dans la foret\n\n");
    color(0,0);
    printf(" ");
    while (j < sizeofmap)
    {
        printf("    ");
        j++;
    }
    printf("\n");
    while (i < sizeofmap)
    {


        printf(" ");
        j = 0;
        while (j < sizeofmap)
        {

            if (map[i][j][0])
                color(0,7);
            else
                color(0,2);
            printf(" ");

            if (map[i][j][1])
                color(0,4);
            printf(" ");

            if (map[i][j][0])
                color(0,7);
            else
                color(0,2);
            printf(" ");

            color(0,0);

            printf(" ");
            j++;
        }
        printf("\n");
        color(0,0);
        printf(" ");
        while (j > 0)
        {
            printf("    ");
            j--;
        }
        printf("\n");

        i++;
    }
    color(7,0);

}
