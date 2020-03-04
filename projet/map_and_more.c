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
    map[2][2][0]=1;
    //printf("malloc complete\n");
    return map;
}


int     *to_find_in_map(int ***map, int sizeofmap ,int player_type)
{
    int j,i;
    int *result;
    result = (int*)malloc(sizeof(int)*2);
    j = 0;

    while(j<sizeofmap)
    {
        i = 0;
        while(i<sizeofmap)
        {
            if (map[j][i][1] == player_type)
            {
                result[0]=j;
                result[1]=i;
                return result;
            }
            i++;
        }
        j++;
    }
    return 0,0;
}


void    show_map(int ***map,int sizeofmap)
{
    int     i = 0;
    int     j = 0;

    system("cls");
    printf("\n");
    color(0,7);
    printf(" ");
    //map[2][3][1]=1;
    while (j < sizeofmap)
    {
        printf("    ");
        j++;
    }
    printf("\n");
    while (i < sizeofmap)
    {
        color(0,7);
        printf(" ");
        j = 0;
        while (j < sizeofmap)
        {
            if (map[i][j][1])
            {
                if (map[i][j][0]==0)
                    color(0,2);
                if (map[i][j][0]==1)
                    color(0,3);
            }
            else
                color(0,0);
            printf(" ");

            if (map[i][j][1] == 1)
                color(0,4);
            printf(" ");

            if (map[i][j][1])
            {
                if (map[i][j][0]==0)
                    color(0,2);
                if (map[i][j][0]==1)
                    color(0,3);
            }
            else
                color(0,0);
            printf(" ");

            color(0,0);
            if ( j == sizeofmap-1)
                color(0,7);
            printf(" ");
            j++;
        }
        printf("\n");
        color(0,7);
        printf(" ");
        color(0,0);
        if (i == sizeofmap - 1)
            color(0,7);
        while (j > 0)
        {

            printf("   ");
            if (j == 1)
                color(0,7);
            printf(" ");
            if (i != sizeofmap-1)
                color(0,0);
            j--;

        }
        printf("\n");

        i++;
    }
    color(7,0);
    printf("\n");
}



