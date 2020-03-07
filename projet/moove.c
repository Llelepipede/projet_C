#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"
#include <time.h>
#include <windows.h>
#include "map.h"

void    deplacement(t_map     ***map,char     moov)
{
    int *pos_joueur_map;
    int *pos_joueur;

    pos_joueur_map = (int*)malloc(sizeof(int)*2);
    pos_joueur = (int*)malloc(sizeof(int)*2);
    pos_joueur_map = to_find_in_map(map,9,1);
    pos_joueur = to_find_in_case(map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type,7,1);

    map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type->design[pos_joueur[0]][pos_joueur[1]].maj = 0;

    if((moov == 'z' || moov == 'Z')&& pos_joueur[0] != 0 )
        pos_joueur[0]--;
    if((moov == 'd' || moov == 'D')&& pos_joueur[1] != 6 )
        pos_joueur[1]++;
    if((moov == 's' || moov == 'S')&& pos_joueur[0] != 6 )
        pos_joueur[0]++;
    if((moov == 'q' || moov == 'Q')&& pos_joueur[1] != 0 )
        pos_joueur[1]--;
    //system("cls");
    //printf("before then news\n");
    //Sleep(1000);
    if (map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type->design[pos_joueur[0]][pos_joueur[1]].case_teleporteur)
    {
        int case_tp = map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type->design[pos_joueur[0]][pos_joueur[1]].case_teleporteur;

        map[pos_joueur_map[0]][pos_joueur_map[1]]->maj = 2;
        pos_joueur_map[0]+= case_tp == 1 ? -1 : case_tp == 4 ? 1 : 0;
        pos_joueur_map[1]+= case_tp == 2 ? -1 : case_tp == 3 ? 1 : 0;
        pos_joueur[1]= case_tp == 2 ? 6 : case_tp == 3 ? 0 : pos_joueur[1];
        pos_joueur[0]= case_tp == 1 ? 6 : case_tp == 4 ? 0 : pos_joueur[0];
        map[pos_joueur_map[0]][pos_joueur_map[1]]->maj = 1;
        map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type->design[pos_joueur[0]][pos_joueur[1]].maj = 1;
    }
    else
        map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type->design[pos_joueur[0]][pos_joueur[1]].maj = 1;
    free(pos_joueur);
    free(pos_joueur_map);
}

