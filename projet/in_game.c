#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <windows.h>


void    in_game(t_map ***map,perso joueur,t_Monstropedie *list)
{
    int touche;
    int on_mob = 0;
    perso mob;
    char *mob_name;

    show_map(map,9);
    while (1)
    {
        mob_name = "NULL";
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {

            touche = _getch();
            if (touche==80)  // fleche bas
            {
                on_mob = deplacement(map,'s');
            }
            if (touche==72)  // fleche haut
            {
                on_mob = deplacement(map,'z');
            }
            if (touche==75)  // fleche gauche
            {
                on_mob = deplacement(map,'q');
            }
            if (touche==77)  // fleche droite
            {
                on_mob = deplacement(map,'d');
            }

        }

        if (on_mob)
        {
            if (on_mob == 3)
                mob_name = "glagladiateur";

            create_mob(find_in_monstropedie(list,mob_name),&mob,3);
            combat(&joueur,&mob);
        }
        show_map(map,9);
    }
}
