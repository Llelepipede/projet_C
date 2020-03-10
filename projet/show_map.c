#include "header.h"




void    show_map(t_map ***map,int sizeofmap)
{
    int     i = 0;
    int     j = 0;
    int     k = 0;
    int     l = 0;
    int     k_memory = 0;
    int     l_memory = 0;
    int     *pos_joueur;
    int     couleur_joueur = 10;

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
                color(0,couleur_joueur);
            printf("%c",map[i][j]->map_type->event == 1 ? '!' : ' ');

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
                    if (map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].case_teleporteur)
                        color(0,6);
                    if (map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].heal)
                        color(0,14);
                    if (map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].mob)
                        color(0,5);
                    if (map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].maj)
                        color(0,couleur_joueur);
                    printf("%s",map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].mob && !(map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k_memory-1][l_memory].maj)? "00": "  ");
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
                    color(couleur_joueur,map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k][l].color);
                    if (map[pos_joueur[0]][pos_joueur[1]]->map_type->design[k][l].maj)
                        printf("(00)");
                    else
                        printf("    ");
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
}

void    show_ath()
{
    color(3,0);
    printf("deplacement: fleches |  stats: S  |  retourner au menu: echap\n");
    color(2,0);
    printf("\n(00)\n ");
    color(0,2);
    printf("  ");
    color(3,0);
    printf(" -> vous     ");
    color(0,5);
    printf("00");
    color(3,0);
    printf(" -> ennemi     ");
    color(0,14);
    printf("  ");
    color(3,0);
    printf(" -> soin");



}
