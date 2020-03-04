#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"

typedef struct  stats       b_perso;
typedef struct  list_mob    t_Monstropedie;
typedef struct  character   perso;
typedef struct  joueur      player;

void         create_b_mob(t_Monstropedie *list,char *name, int hp, float hp_lvl, int attaque, float attaque_lvl, int deffense, float deffense_lvl, int vitesse, float vitesse_lvl)
{
    b_perso *mob = malloc(sizeof(b_perso));
    mob->name = name;

    mob->b_hp = hp;
    mob->b_attac = attaque;
    mob->b_deff = deffense;
    mob->b_speed = vitesse;

    mob->lvl_up_impact[0] = hp_lvl;
    mob->lvl_up_impact[2] = attaque_lvl;
    mob->lvl_up_impact[3] = deffense_lvl;
    mob->lvl_up_impact[4] = vitesse_lvl;
    add_mob(list,mob);
}



void    add_mob(t_Monstropedie *list,b_perso *mob)
{
    mob->previous = &list->first;
    mob->next = list->first.next;
    list->first.next = mob;
}



