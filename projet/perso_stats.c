#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include <string.h>


typedef struct stats b_perso;
typedef struct character perso;
typedef struct list_mob t_Monstropedie;
typedef struct joueur player;

t_Monstropedie    create_Monstropedie()
{
    t_Monstropedie monstropedie;

    /*ALI TON AMI*/

    monstropedie.Ali_ton_ami.name = "Ali ton ami";

    monstropedie.Ali_ton_ami.b_hp = 300;
    monstropedie.Ali_ton_ami.b_mana = 0;
    monstropedie.Ali_ton_ami.b_attac = 20;
    monstropedie.Ali_ton_ami.b_deff = 30;
    monstropedie.Ali_ton_ami.b_speed = 15;

    monstropedie.Ali_ton_ami.lvl_up_impact[0] = 0.1;
    monstropedie.Ali_ton_ami.lvl_up_impact[1] = 0.0;
    monstropedie.Ali_ton_ami.lvl_up_impact[2] = 0.07;
    monstropedie.Ali_ton_ami.lvl_up_impact[3] = 0.12;
    monstropedie.Ali_ton_ami.lvl_up_impact[4] = 0.067;
    printf("%d",monstropedie.Ali_ton_ami.b_hp);
    /*LA BELLE MERE*/

    monstropedie.La_belle_mere.name = "La belle mere";

    monstropedie.La_belle_mere.b_hp = 150;
    monstropedie.La_belle_mere.b_mana = 0;
    monstropedie.La_belle_mere.b_attac = 37;
    monstropedie.La_belle_mere.b_deff = 7;
    monstropedie.La_belle_mere.b_speed = 23;

    monstropedie.La_belle_mere.lvl_up_impact[0] = 0.108;
    monstropedie.La_belle_mere.lvl_up_impact[1] = 0.03;
    monstropedie.La_belle_mere.lvl_up_impact[2] = 0.087;
    monstropedie.La_belle_mere.lvl_up_impact[3] = 0.04;
    monstropedie.La_belle_mere.lvl_up_impact[4] = 0.067;

    /*GOUT LOOM*/

    monstropedie.Gout_Loom.name = "Gout Loom";

    monstropedie.Gout_Loom.b_hp = 200;
    monstropedie.Gout_Loom.b_mana = 0;
    monstropedie.Gout_Loom.b_attac = 17;
    monstropedie.Gout_Loom.b_deff = 50;
    monstropedie.Gout_Loom.b_speed = 27;

    monstropedie.Gout_Loom.lvl_up_impact[0] = 0.13;
    monstropedie.Gout_Loom.lvl_up_impact[1] = 0.0;
    monstropedie.Gout_Loom.lvl_up_impact[2] = 0.09;
    monstropedie.Gout_Loom.lvl_up_impact[3] = 0.16;
    monstropedie.Gout_Loom.lvl_up_impact[4] = 0.06;


    return monstropedie;
}

void    create_mob(b_perso base, perso *mob,int lvl)
{
    mob->name = base.name;
    mob->lvl = lvl;
    set_lvl_up(base,mob);
}


void    personnage(t_Monstropedie list)
{
    perso m_Ali_ton_ami;
    set_to_zero(&m_Ali_ton_ami);
    create_mob(list.Ali_ton_ami,&m_Ali_ton_ami,54);
    show_stat_of(m_Ali_ton_ami);
}

void    set_to_zero(perso *mob)
{
    mob->name = "TEST";
    mob->hp = 0;
    mob->mana = 0;
    mob->attac = 0;
    mob->deff = 0;
    mob->speed = 0;
}

void    set_lvl_up(b_perso base, perso *mob)
{
    int     i = 0;

    mob->hp = base.b_hp;
    mob->mana = base.b_mana;
    mob->attac = base.b_attac;
    mob->deff = base.b_deff;
    mob->speed = base.b_speed;
    printf("%d\n%d\n",base.b_hp,mob->lvl);

    while(i<mob->lvl)
    {
        mob->hp += base.b_hp * base.lvl_up_impact[0];
        mob->mana += base.b_mana * base.lvl_up_impact[1];
        mob->attac += base.b_attac * base.lvl_up_impact[2];
        mob->deff += base.b_deff * base.lvl_up_impact[3];
        mob->speed += base.b_speed * base.lvl_up_impact[4];
        printf("%d\n",i);
        i++;
    }
}







void    show_stat_of(perso monster)
{
    int lvl = monster.lvl;
    int hp = monster.hp/1.0;
    int mana = monster.mana/1.0;
    int attaque = monster.attac/1.0;
    int deffense = monster.deff/1.0;
    int vitesse = monster.speed/1.0;
    printf("\t-%s- niveau:%d\n\nhp->%d\nmana->%d\nattaque->%d ( la valeur reel est: %f,arrondie pour plus de clarte)\ndeffense->%d\nvitesse->%d\n",monster.name,lvl,hp,mana,attaque,monster.attac,deffense,vitesse);
}


