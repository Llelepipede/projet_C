#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"
#include <time.h>
#include <windows.h>


void    in_game(int ***map,perso joueur,t_Monstropedie list)
{
    int curs;
    int touche;
    show_map(map,9);
    while (1)
    {
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {

        touche = _getch();
            if (touche==80)  // fleche bas
            {
                deplacement(map,'s');
            }
            if (touche==72)  // fleche haut
            {
                deplacement(map,'z');
            }
            if (touche==75)  // fleche gauche
            {
                deplacement(map,'q');
            }
            if (touche==77)  // fleche droite
            {
                deplacement(map,'d');
            }


        }
        //printf("%d",touche);
        //Sleep(1000);
        show_map(map,9);
    }
}
