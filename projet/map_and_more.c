#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "map.h"
#include <windows.h>


t_map   ***map_create(t_map ***map,int sizeofmap)
{
    int     colonne;
    int     ligne;


    colonne = 0;
    ligne = 0;

    int in_map_colonne = 0;
    int in_map_ligne = 0;

    /*Partie malloc*/
    /*elle conciste a creer un espace mémoire dedie a la map dans le jeu.
    cette map aura la forme d'un carre de taille "sizeofmap", avec dans chaque case du quadrillage ,
    2 valeurs: qu'es qui s'y trouve, et si un evenement s'y est passee*/

    if (!(map = (t_map***)malloc(sizeof(t_map**) * sizeofmap)))
        return (0);
    while (colonne < sizeofmap)
    {

        if (!(map[colonne] = (t_map**)malloc(sizeof(t_map*) * sizeofmap )))
            return (0);
        ligne = 0;
        while (ligne < sizeofmap)
        {
            in_map_colonne = 0;

            //printf("%d , %d\n",colonne,ligne);
            if (!(map[colonne][ligne] = (t_map*)malloc(sizeof(t_map))))
            {
                printf("not malloc");
                return (0);
            }
            map[colonne][ligne]->map_type = (t_map_type*)malloc(sizeof(t_map_type));
            map[colonne][ligne]->map_type->design = (t_case_type**)malloc(sizeof(t_case_type*)*7);
            map[colonne][ligne]->maj = 0;
            map[colonne][ligne]->map_type->color = (colonne+ligne)%2==0 ? 2 : 3; //est foret pour l'instant
            map[colonne][ligne]->map_type->event = 0; //aucun evenement
            map[colonne][ligne]->map_type->district = 0; //aucun district

            while(in_map_colonne <7)
            {
                map[colonne][ligne]->map_type->design[in_map_colonne] = (t_case_type*)malloc(sizeof(t_case_type)*7);
                in_map_ligne = 0;
                while(in_map_ligne < 7)
                {
                    //printf(">%d | %d \n> %d | %d\n",in_map_colonne,in_map_ligne,ligne,colonne);
                    //Sleep(10);

                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].passable = 1;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].heal = 0;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].mob = 0;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].butin = 0;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].case_teleporteur = in_map_colonne == 0 && in_map_ligne == 3 ? 1 : in_map_colonne == 6 && in_map_ligne == 3 ? 4 : in_map_colonne == 3 && in_map_ligne == 0 ? 2 : in_map_colonne == 3 && in_map_ligne == 6 ? 3 : 0 ;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].maj = 0;

                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].color = (colonne+ligne)%2==0 ? 2 : 3 ;
                    in_map_ligne++;
                }
                in_map_colonne++;
            }
            //printf("malloc done\n");
            ligne ++;
        }
        colonne++;
    }
    map[4][4]->maj = 1;
    map[4][4]->map_type->design[0][3].case_teleporteur = 1;
    map[4][4]->map_type->design[3][3].maj =1;
    //printf("%d\n",map[4][4]->map_type->design[1][1].color);
    //Sleep(300);
    //printf("malloc complete\n");
    return map;
}


int     *to_find_in_map(t_map ***map, int sizeofmap ,int player_type)
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
            //printf("%d",map[j][i]->maj);
            if (map[j][i]->maj == player_type)
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

int     *to_find_in_case(t_map_type *map_type, int sizeofmap ,int player_type)
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
            if (map_type->design[j][i].maj == player_type)
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

void     map_foret1(t_case_type **map,int event)
{
    int     colonne;
    int     ligne;

    int sizeofmap = 7;
    colonne = 7;
    ligne = 7;

    //Partie malloc
    //elle conciste a creer un espace mémoire dedie a la map dans le jeu.
    //cette map aura la forme d'un carre de taille "sizeofmap", avec dans chaque case du quadrillage ,
    //2 valeurs: qu'es qui s'y trouve, et si un evenement s'y est passee

    while (colonne)
    {
        while (ligne)
        {
            //printf("%d , %d\n",sizeofmap - colonne,sizeofmap - ligne);
            map[sizeofmap - colonne][sizeofmap - ligne].passable = 1;
            map[sizeofmap - colonne][sizeofmap - ligne].heal = 0;
            map[sizeofmap - colonne][sizeofmap - ligne].mob = 0;
            map[sizeofmap - colonne][sizeofmap - ligne].butin = 0;
            map[sizeofmap - colonne][sizeofmap - ligne].case_teleporteur = 0;
            map[sizeofmap - colonne][sizeofmap - ligne].color = 2;
            //printf("->%d, %d\n",map[sizeofmap - colonne][sizeofmap - ligne][0],map[sizeofmap - colonne][sizeofmap - ligne][1]);
            //printf("malloc done\n");
            ligne --;
        }

        ligne = sizeofmap;
        colonne--;
    }
    map[3][0].case_teleporteur = 1;
    map[0][3].case_teleporteur = 3;
    map[3][7].case_teleporteur = 2;
    map[7][3].case_teleporteur = 4;
    //printf("%d",map[sizeofmap - colonne][sizeofmap - ligne].color = 2);
    Sleep(3000);


}



void    show_map(t_map ***map,int sizeofmap)
{
    int     i = 0;
    int     j = 0;
    int     k = 0;
    int     l = 0;
    int     k_memory = 0;
    int     l_memory = 0;
    int     *pos_joueur;

    system("cls");
    //printf("debut show map\n\n");
    //Sleep(1000);
    pos_joueur = to_find_in_map(map,9,1);
    //printf("%d | %d    |    \n\n",pos_joueur[0],pos_joueur[1],map[pos_joueur[0]][pos_joueur[1]]->map_type->design[1][1].color);
    printf("\n");


    //ligne blanche en haut
    color(0,7);
    printf(" ");


    while (j < sizeofmap)
    {
        printf("    ");
        j++;
    }
    //fin ligne blanche en haut
    printf("\n");
    k = 0;
    while (i < sizeofmap)
    {
        l = 0;
        //bande blanche a gauche pour ligne
        color(0,7);
        printf(" ");
        //fin bande blanche a gauche pour ligne
        j = 0;

        while (j < sizeofmap)
        {

            //set up la couleur si le joueur est deja passer sur la case (partie gauche de la case)
            if (map[i][j]->maj)
            {
                //set up la couleur grace a la color de map_type
                color(0,map[i][j]->map_type->color);
            }
            //sinon, met du noir
            else
                color(0,0);
            printf(" ");

            //place le curseur rouge si la maj == 1
            if (map[i][j]->maj == 1)
                color(0,4);
            printf(" ");

            //set up la couleur si le joueur est deja passer sur la case (partie droite de la case)
            if (map[i][j]->maj)
            {
                color(0,map[i][j]->map_type->color);
            }
            else
                color(0,0);
            printf(" ");

            //bande blanche a droite pour ligne
            color(0,0);
            if ( j == sizeofmap-1)
                color(0,7);
            printf(" ");
            //fin bande blanche a droite pour ligne

            //AFFICHAGE CARRE GAUCHE//


            if (i != 0 && i < sizeofmap-1 && j == sizeofmap-1)
            {
                //place l'ecart de 4 espaces entre les 2 carre
                color(0,0);
                printf("    ");

                //bande blanche a gauche pour ligne
                color(0,7);
                printf(" ");
                //fin bande blanche a gauche pour ligne
                /*printf("%d",j);
                while (j < sizeofmap-2)
                {
                    color(0,2);
                    printf("????");
                    j++;
                }*/
                color(1,3);
                k_memory = k;
                k = 0;
                l_memory = l;
                while (k < sizeofmap-2)
                {
                    color(4,map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].color);
                    printf(" ");
                    if (map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].maj)
                        color(0,4);
                    printf("  ");
                    color(4,map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].color);
                    printf(" ");
                    l_memory++;
                    k++;
                }
                color(0,7);
                printf(" ");

                k = k_memory;

            }
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


        if (i <sizeofmap-1)
        {
            color(0,0);
            printf("    ");
            color(0,7);
            printf(" ");
            color(9,0);
            l = 0;
            while (j != sizeofmap-2)
            {
                if (i != 0 && i != 7)
                {
                    color(4,map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k][l].color);
                    printf(" %c%c ",map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k][l].maj? '(' : ' ',map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k][l].maj ? ')' : ' ');
                }
                else
                {
                    color(0,7);
                    printf("    ");
                }

                l++;
                j++;
            }
            color(0,7);
            printf(" ");
            k++;

        }
        printf("\n");
        i++;
    }

    color(7,0);
    printf("\n");
}



