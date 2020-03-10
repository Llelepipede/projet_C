#include "header.h"

void    personnage(t_Monstropedie *list)
{
                                     //Heal point|hp/lvl|mana|mana/lvl|attaque|att/lvl|deff|deff/lvl|vitesse|vitesse/lvl|competence
    create_b_mob(list,"janin_genieux" ,300       ,0.1   ,50  ,0.1     ,33     ,0.1    ,20  ,0.1     ,27     ,0.1        ,create_comp("Okan_au_tableau!",2,1,200,-2,40,3));
    create_b_mob(list,"la_belle_mere" ,50        ,0.108 ,10  ,0.1     ,37     ,0.087  ,12  ,0.04    ,23     ,0.1        ,create_comp("ton_ex_etait_mieux",2,1,110,0,0,12));
    create_b_mob(list,"ali_ton_ami"   ,100       ,0.1   ,9   ,0.1     ,20     ,0.07   ,30  ,0.12    ,15     ,0.067      ,create_comp("annee_vingt_vingt",2,1,105,-1,10,4));
    create_b_mob(list,"gout_loom"     ,125       ,0.13  ,20  ,0.1     ,17     ,0.098  ,40  ,0.157   ,27     ,0.1        ,create_comp("LA_FERME!",2,1,160,0,0,10));
    create_b_mob(list,"farmer"        ,35        ,0.18  ,11  ,0.1     ,12     ,0.098  ,7   ,0.157   ,14     ,0.1        ,create_comp("libertine",1,2,140,1,30,6));
    create_b_mob(list,"glagladiateur" ,42        ,0.18  ,5   ,0.1     ,8      ,0.098  ,10  ,0.157   ,7      ,0.1        ,create_comp("En_garde!",1,2,0,2,40,5));
    create_b_mob(list,"joueur"        ,50        ,0.12  ,20  ,0.1     ,10     ,0.11   ,10  ,0.1     ,12     ,0.1        ,create_comp("soin_complet",1,2,200,0,0,7));
    perso mob;
    char    choice;
    int     lvl;
    printf("\n\n");
    respond("choisissez le nom du mob a rechercher\n");
    ask_space(&choice);
    respond("a quelle lvl ?");
    printf("\t>");
    scanf("%d",&lvl);
    create_mob(find_in_monstropedie(list,&choice),&mob,lvl);
    show_stat_of(mob);
}

void    create_mob(b_perso *base, perso *mob,int lvl)
{
    if (strcmp(base->name,"Beg-end"))
    {
        mob->name = base->name;
        mob->lvl = lvl;
        mob->comp = base->comp;
        set_lvl_up(*base,mob,10);
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

void    heal(perso  *mob)
{
    mob->hp = mob->hp_max;
    mob->mana = mob->mana_max;
}

void    set_lvl_up(b_perso base, perso *mob,int lvl)
{
    int     i = 0;

    mob->hp = base.b_hp;
    mob->mana = base.b_mana;
    mob->attac = base.b_attac;
    mob->deff = base.b_deff;
    mob->speed = base.b_speed;
    mob->xp = 0;
    mob->xp_not_lvl_up = 0;


    while(i<mob->lvl)
    {
        mob->hp += base.b_hp * base.lvl_up_impact[0];
        mob->mana += base.b_mana * base.lvl_up_impact[1];
        mob->attac += base.b_attac * base.lvl_up_impact[2];
        mob->deff += base.b_deff * base.lvl_up_impact[3];
        mob->speed += base.b_speed * base.lvl_up_impact[4];
        mob->xp += (((i*i)+20)/2);
        mob->xp_to_lvlup = (((i*i)+20)/2);
        i++;
    }
    mob->hp_max = mob->hp;
    mob->mana_max = mob->mana;
}
void    lvl_up(perso    *mob,b_perso    *base)
{
    mob->lvl += 1;
    mob->xp_not_lvl_up = mob->xp_not_lvl_up%mob->xp_to_lvlup;
    mob->xp += mob->xp_to_lvlup;
    mob->xp_to_lvlup = (((mob->lvl*mob->lvl)+20)/2);
    mob->hp_max += base->b_hp * base->lvl_up_impact[0];
    mob->mana_max += base->b_mana * base->lvl_up_impact[1];
    mob->attac += base->b_attac * base->lvl_up_impact[2];
    mob->deff += base->b_deff * base->lvl_up_impact[3];
    mob->speed += base->b_speed * base->lvl_up_impact[4];

}


void    show_stat_after_fight(perso monster,int     xp_earn)
{

    system("cls");
    printf("\n\tVICTOIRE!\n\n");
    int lvl = monster.lvl;
    int hp = monster.hp/1;
    int hp_max = monster.hp_max/1;
    int mana = monster.mana/1;
    int mana_max = monster.mana_max/1;
    int attaque = monster.attac/1;
    int deffense = monster.deff/1;
    int vitesse = monster.speed/1;
    printf("\n\t-%s-\tniveau:%d\n\texp\t->\t%d/%d + %d\n\thp\t->\t%d/%d\n\tmana\t->\t%d/%d\n\tattaque\t->\t%d\n\tdeffense->\t%d\n\tvitesse\t->\t%d\n",monster.name,lvl,monster.xp_not_lvl_up,monster.xp_to_lvlup,xp_earn,hp,hp_max,mana,mana_max,attaque,deffense,vitesse);
    _getch();
}


void    show_stat_of(perso monster)
{

    int lvl = monster.lvl;
    int hp = monster.hp/1;
    int hp_max = monster.hp_max/1;
    int mana = monster.mana/1;
    int mana_max = monster.mana_max/1;
    int attaque = monster.attac/1;
    int deffense = monster.deff/1;
    int vitesse = monster.speed/1;
    printf("\n\t-%s-\tniveau:%d\n\texp\t->\t%d/%d\n\thp\t->\t%d/%d\n\tmana\t->\t%d/%d\n\tattaque\t->\t%d\n\tdeffense->\t%d\n\tvitesse\t->\t%d\n",monster.name,lvl,monster.xp_not_lvl_up,monster.xp_to_lvlup,hp,hp_max,mana,mana_max,attaque,deffense,vitesse);
    _getch();
}


