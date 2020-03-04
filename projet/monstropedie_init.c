#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "perso_stats_h.h"

typedef struct stats b_perso;
typedef struct list_mob t_Monstropedie;
typedef struct character perso;
typedef struct joueur player;

/*t_Monstropedie    create_Monstropedie()
{
    t_Monstropedie monstropedie;

    /*ALI TON AMI

    monstropedie.Ali_ton_ami.name = "Ali ton ami";

    monstropedie.Ali_ton_ami.b_hp = 100;
    monstropedie.Ali_ton_ami.b_mana = 0;
    monstropedie.Ali_ton_ami.b_attac = 20;
    monstropedie.Ali_ton_ami.b_deff = 30;
    monstropedie.Ali_ton_ami.b_speed = 15;

    monstropedie.Ali_ton_ami.lvl_up_impact[0] = 0.1;
    monstropedie.Ali_ton_ami.lvl_up_impact[1] = 0.0;
    monstropedie.Ali_ton_ami.lvl_up_impact[2] = 0.07;
    monstropedie.Ali_ton_ami.lvl_up_impact[3] = 0.12;
    monstropedie.Ali_ton_ami.lvl_up_impact[4] = 0.067;

    /*LA BELLE MERE

    monstropedie.La_belle_mere.name = "La belle mere";

    monstropedie.La_belle_mere.b_hp = 50;
    monstropedie.La_belle_mere.b_mana = 0;
    monstropedie.La_belle_mere.b_attac = 37;
    monstropedie.La_belle_mere.b_deff = 7;
    monstropedie.La_belle_mere.b_speed = 23;

    monstropedie.La_belle_mere.lvl_up_impact[0] = 0.108;
    monstropedie.La_belle_mere.lvl_up_impact[1] = 0.03;
    monstropedie.La_belle_mere.lvl_up_impact[2] = 0.087;
    monstropedie.La_belle_mere.lvl_up_impact[3] = 0.04;
    monstropedie.La_belle_mere.lvl_up_impact[4] = 0.067;

    /*GOUT LOOM

    monstropedie.Gout_Loom.name = "Gout Loom";

    monstropedie.Gout_Loom.b_hp = 125;
    monstropedie.Gout_Loom.b_mana = 0;
    monstropedie.Gout_Loom.b_attac = 17;
    monstropedie.Gout_Loom.b_deff = 40;
    monstropedie.Gout_Loom.b_speed = 27;

    monstropedie.Gout_Loom.lvl_up_impact[0] = 0.13;
    monstropedie.Gout_Loom.lvl_up_impact[1] = 0.0;
    monstropedie.Gout_Loom.lvl_up_impact[2] = 0.098;
    monstropedie.Gout_Loom.lvl_up_impact[3] = 0.157;
    monstropedie.Gout_Loom.lvl_up_impact[4] = 0.1;

    /*JANIN GENIEUX

    monstropedie.Janin_Genieux.name = "Janin Genieux";

    monstropedie.Janin_Genieux.b_hp = 250;
    monstropedie.Janin_Genieux.b_mana = 0;
    monstropedie.Janin_Genieux.b_attac = 17;
    monstropedie.Janin_Genieux.b_deff = 50;
    monstropedie.Janin_Genieux.b_speed = 27;

    monstropedie.Janin_Genieux.lvl_up_impact[0] = 0.13;
    monstropedie.Janin_Genieux.lvl_up_impact[1] = 0.0;
    monstropedie.Janin_Genieux.lvl_up_impact[2] = 0.09;
    monstropedie.Janin_Genieux.lvl_up_impact[3] = 0.17;
    monstropedie.Janin_Genieux.lvl_up_impact[4] = 0.1;

    return monstropedie;
}*/

t_Monstropedie     *initiate_mob_Monst()
{
    t_Monstropedie *list = (t_Monstropedie*)malloc(sizeof(b_perso)*2);
    list->first = initiate_mob(NULL,&list->last);
    list->last = initiate_mob(&list->first,NULL);
    return list;
}
b_perso     initiate_mob(b_perso *previous,b_perso *next)
{
    b_perso *mob = (b_perso*)malloc(sizeof(b_perso));
    int i;
    mob->name = "Beg-end";
    mob->next = next;
    mob->previous = previous;
    mob->b_hp = 0;
    mob->b_attac = 0;
    mob->b_deff = 0;
    mob->b_speed = 0;
    while (i<5)
    {
        mob->lvl_up_impact[i]=0;
        i++;
    }
    return *mob;
}


