#include "header.h"


void    new_game()
{
    int     sizeofmap = 9;
    t_map     ***map;

    t_Monstropedie *list;
    list = initiate_mob_Monst();
                                     //Heal point|hp/lvl|mana|mana/lvl|attaque|att/lvl|deff|deff/lvl|vitesse|vitesse/lvl|competence  |name                  |target |effect |attk%|bonus|bonus%|cost
    create_b_mob(list,"janin_genieux" ,300       ,0.1   ,50  ,0.1     ,20     ,0.1    ,10  ,0.1     ,27     ,0.1        ,create_comp("competence_janin"     ,2      ,1      ,200  ,-2   ,40    ,3));
    create_b_mob(list,"la_belle_mere" ,50        ,0.135 ,10  ,0.1     ,22     ,0.087  ,6   ,0.04    ,23     ,0.1        ,create_comp("ton_ex_etait_mieux"   ,2      ,1      ,70   ,0    ,0     ,12));
    create_b_mob(list,"ali_ton_ami"   ,100       ,0.1   ,9   ,0.1     ,15     ,0.07   ,15  ,0.12    ,15     ,0.067      ,create_comp("annee vingt vingt"    ,2      ,1      ,60   ,-1   ,10    ,4));
    create_b_mob(list,"gout_loom"     ,125       ,0.13  ,20  ,0.1     ,10     ,0.098  ,20  ,0.157   ,27     ,0.1        ,create_comp("La_ferme"             ,2      ,1      ,50   ,0    ,0     ,10));
    create_b_mob(list,"farmer"        ,35        ,0.18  ,11  ,0.1     ,6      ,0.1    ,7   ,0.157   ,14     ,0.1        ,create_comp("libertine"            ,1      ,2      ,50   ,1    ,20    ,6));
    create_b_mob(list,"glagladiateur" ,42        ,0.18  ,5   ,0.1     ,3      ,0.098  ,12  ,0.157   ,7      ,0.1        ,create_comp("En_garde!"            ,1      ,2      ,80   ,2    ,40    ,5));
    create_b_mob(list,"joueur"        ,50        ,0.12  ,20  ,0.1     ,10     ,0.11   ,10  ,0.1     ,12     ,0.1        ,create_comp("soin_supperieur"         ,1      ,2      ,140  ,0    ,0     ,7));

    perso joueur;
    create_mob(find_in_monstropedie(list,"joueur"),&joueur,15);

    printf("%s%d",joueur.comp->name,joueur.comp->cost);
    map = map_create(map,sizeofmap);
    //show_map(map, 9);
    in_game(map,&joueur,list);
}


