#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"
#include <time.h>
#include <windows.h>


void    new_game()
{
    int     sizeofmap = 9;
    int     ***map = map_create(map,sizeofmap);

    t_Monstropedie *monstropedie;
    monstropedie = initiate_mob_Monst();

    map = map_create(map,sizeofmap);

    show_map(map,sizeofmap);
}


