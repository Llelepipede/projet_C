#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include <string.h>
#include "header.h"


typedef struct stats b_perso;
typedef struct character perso;
typedef struct list_mob t_Monstropedie;
typedef struct joueur player;

void    personnage(t_Monstropedie *list)
{
                                     //Heal point|hp/lvl|attaque|att/lvl|deff|deff/lvl|vitesse|vitesse/lvl
    create_b_mob(list,"Janin_Genieux", 300       ,0.1   ,33     ,0.1    ,20  ,0.1     ,27     ,0.1        );
    create_b_mob(list,"La_Belle_Mere", 50        ,0.108 ,33     ,0.1    ,20  ,0.1     ,27     ,0.1        );
    create_b_mob(list,"Ali_ton_ami",100,0.1,20,0.07,30,0.12,15,0.067);
    b_perso mob;
    char    choice;
    int     lvl;
    printf("\n\n");
    respond("choisissez le nom du mob a rechercher\n");
    ask_space(&choice);
    respond("a quelle lvl ?");
    printf("\t>");
    scanf("%d",&lvl);
    create_mob(find_in_monstropedie(list,&choice),&mob,lvl);
}

void    create_mob(b_perso *base, perso *mob,int lvl)
{
    if (strcmp(base->name,"Beg-end"))
    {
        mob->name = base->name;
        mob->lvl = lvl;
        set_lvl_up(*base,mob,10);
        show_stat_of(*mob);
    }
    else
    {
        respond("monstre inconnu");
    }
}


/*void    personnage(t_Monstropedie list)
{
    perso mob;
    make_and_show(list.Ali_ton_ami,&mob,10);
    make_and_show(list.La_belle_mere,&mob,10);
    make_and_show(list.Gout_Loom,&mob,10);
    make_and_show(list.Janin_Genieux,&mob,10);
}

void    make_and_show(b_perso base,perso *mob,int lvl)
{
    int i = 0;
    printf("\nStats de %s du niveau 1-%d\n\n",base.name,lvl);
    while(i<lvl)
    {
        i++;
        set_to_zero(mob);
        create_mob(base,mob,i);
        show_stat_of(*mob);
    }
}
*/
void    set_to_zero(perso *mob)
{
    mob->name = "TEST";
    mob->hp = 0;
    mob->attac = 0;
    mob->deff = 0;
    mob->speed = 0;
}



void    set_lvl_up(b_perso base, perso *mob,int lvl)
{
    int     i = 0;

    mob->hp = base.b_hp;
    mob->attac = base.b_attac;
    mob->deff = base.b_deff;
    mob->speed = base.b_speed;

    while(i<mob->lvl)
    {
        mob->hp += base.b_hp * base.lvl_up_impact[0];
        mob->attac += base.b_attac * base.lvl_up_impact[2];
        mob->deff += base.b_deff * base.lvl_up_impact[3];
        mob->speed += base.b_speed * base.lvl_up_impact[4];
        i++;
    }
}


void    show_stat_of(perso monster)
{
    int lvl = monster.lvl;
    int hp = monster.hp/1.0;
    int attaque = monster.attac/1.0;
    int deffense = monster.deff/1.0;
    int vitesse = monster.speed/1.0;
    printf("\n\t-%s- niveau:%d\n\nhp->%d\nattaque->%d ( la valeur reel est: %f,arrondie pour plus de clarte)\ndeffense->%d\nvitesse->%d\n",monster.name,lvl,hp,attaque,monster.attac,deffense,vitesse);
}


