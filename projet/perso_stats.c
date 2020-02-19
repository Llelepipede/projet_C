#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include <string.h>

void    personnage()
{
    perso monst_ali;

    monst_ali.name = "Ali ton ami";

    monst_ali.lvl = 4;
    monst_ali.b_hp = 300;
    monst_ali.b_mana = 0;
    monst_ali.b_attac = 20;
    monst_ali.b_deff = 30;
    monst_ali.b_speed = 15;


    monst_ali.lvl_up_impact[0] = 0.1;
    monst_ali.lvl_up_impact[1] = 0.057;
    monst_ali.lvl_up_impact[2] = 0.07;
    monst_ali.lvl_up_impact[3] = 0.12;
    monst_ali.lvl_up_impact[4] = 0.067;


    set_lvl_up(&monst_ali);
    show_stat_of(&monst_ali);
}

void    set_lvl_up(perso *monster)
{
    int     i = 0;

    monster->hp = monster->b_hp;
    monster->mana = monster->b_mana;
    monster->attac = monster->b_attac;
    monster->deff = monster->b_deff;
    monster->speed = monster->b_speed;

    while(i<monster->lvl)
    {
        monster->hp += monster->b_hp * monster->lvl_up_impact[0];
        monster->mana += monster->b_mana * monster->lvl_up_impact[1];
        monster->attac += monster->b_attac * monster->lvl_up_impact[2];
        monster->deff += monster->b_deff * monster->lvl_up_impact[3];
        monster->speed += monster->b_speed * monster->lvl_up_impact[4];
        i++;
    }
}

void    show_stat_of(perso *monster)
{
    int lvl = monster->lvl;
    int hp = monster->hp/1.0;
    int mana = monster->mana/1.0;
    int attaque = monster->attac/1.0;
    int deffense = monster->deff/1.0;
    int vitesse = monster->speed/1.0;

    printf("\t-%s- niveau:%d\n\nhp->%d\nmana->%d\nattaque->%d ( la valeur reel est: %f,arrondie pour plus de clarte)\ndeffense->%d\nvitesse->%d\n",monster->name,lvl,hp,mana,attaque,monster->attac,deffense,vitesse);
}


