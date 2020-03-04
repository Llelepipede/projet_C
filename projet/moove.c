#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"
#include <time.h>
#include <windows.h>

void    deplacement(int     ***map,char     moov)
{
    int *pos_joueur;
    pos_joueur = (int*)malloc(sizeof(int)*2);

    pos_joueur = to_find_in_map(map,9,1);
    map[pos_joueur[0]][pos_joueur[1]][1] = 2;

    if((moov == 'z' || moov == 'Z')&& pos_joueur[0] != 0 )
        pos_joueur[0]--;
    if((moov == 'd' || moov == 'D')&& pos_joueur[1] != 8 )
        pos_joueur[1]++;
    if((moov == 's' || moov == 'S')&& pos_joueur[0] != 8 )
        pos_joueur[0]++;
    if((moov == 'q' || moov == 'Q')&& pos_joueur[1] != 0 )
        pos_joueur[1]--;

    map[pos_joueur[0]][pos_joueur[1]][1] = 1;
    free(pos_joueur);
}
