#include "header.h"

void         create_b_mob(t_Monstropedie *list,char *name, int hp, float hp_lvl, int mana, float mana_lvl, int attaque, float attaque_lvl, int deffense, float deffense_lvl, int vitesse, float vitesse_lvl, t_competence *comp)
{
    b_perso *mob = malloc(sizeof(b_perso));
    mob->name = (char*)malloc(sizeof(char)*20);
    strcpy(mob->name,name);

    mob->b_hp = hp;
    mob->b_mana = mana;
    mob->b_attac = attaque;
    mob->b_deff = deffense;
    mob->b_speed = vitesse;

    mob->lvl_up_impact[0] = hp_lvl;
    mob->lvl_up_impact[1] = mana_lvl;
    mob->lvl_up_impact[2] = attaque_lvl;
    mob->lvl_up_impact[3] = deffense_lvl;
    mob->lvl_up_impact[4] = vitesse_lvl;
    mob->comp = comp;
    add_mob(list,mob);
}



void    add_mob(t_Monstropedie *list,b_perso *mob)
{
    mob->previous = &list->first;
    mob->next = list->first.next;
    list->first.next = mob;
}



