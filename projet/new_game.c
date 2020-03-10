#include "header.h"


void    new_game()
{
    int     sizeofmap = 9;
    t_map     ***map;
    char    name[15];
    int     i=0;
    t_Monstropedie *list;
    list = initiate_mob_Monst();
    respond("Quelle est votre nom ? (- de 20 caracteres)\n");
    scanf("%s",&name);
                                     //Heal point|hp/lvl|mana|mana/lvl|attaque|att/lvl|deff|deff/lvl|vitesse|vitesse/lvl|competence  |name                  |target |effect |attk%|bonus|bonus%|cost
    create_b_mob(list,"Janin Genieux" ,300       ,0.1   ,50  ,0.1     ,20     ,0.1    ,10  ,0.1     ,27     ,0.1        ,create_comp("competence_janin"     ,2      ,1      ,200  ,-2   ,40    ,3   ));
    create_b_mob(list,"La Belle Mere" ,50        ,0.135 ,10  ,0.1     ,22     ,0.087  ,6   ,0.04    ,23     ,0.1        ,create_comp("ton_ex_etait_mieux"   ,2      ,1      ,70   ,0    ,0     ,12  ));
    create_b_mob(list,"Ali ton ami"   ,100       ,0.1   ,9   ,0.1     ,15     ,0.07   ,15  ,0.12    ,15     ,0.067      ,create_comp("annee vingt vingt"    ,2      ,1      ,60   ,0    ,0     ,4   ));
    create_b_mob(list,"Pakoafer"      ,150       ,0.1   ,50  ,0.1     ,13     ,0.05   ,10  ,0.12    ,7      ,0.067      ,create_comp("KaKette!"             ,2      ,1      ,30   ,0    ,0     ,6   ));
    create_b_mob(list,"Rasta-blanc"   ,80        ,0.1   ,50  ,0.1     ,11     ,0.07   ,2   ,0.12    ,23     ,0.067      ,create_comp("Matrix"               ,2      ,1      ,50   ,0    ,0     ,6   ));
    create_b_mob(list,"Gout Loom"     ,125       ,0.13  ,20  ,0.1     ,10     ,0.098  ,20  ,0.157   ,27     ,0.1        ,create_comp("LA_FERME"             ,2      ,1      ,50   ,0    ,0     ,10  ));
    create_b_mob(list,"Farmer"        ,35        ,0.18  ,10  ,0.1     ,6      ,0.1    ,7   ,0.157   ,14     ,0.1        ,create_comp("libertine"            ,1      ,2      ,50   ,1    ,20    ,6   ));
    create_b_mob(list,"Jony"          ,38        ,0.18  ,9   ,0.1     ,7      ,0.098  ,3   ,0.157   ,9      ,0.1        ,create_comp("Allumer_le_feu"       ,2      ,1      ,60   ,0    ,0     ,7   ));
    create_b_mob(list,"Roucky"        ,30        ,0.18  ,11  ,0.1     ,5      ,0.1    ,15  ,0.157   ,16     ,0.1        ,create_comp("Coup_D'tete"          ,2      ,1      ,30   ,0    ,0     ,2   ));
    create_b_mob(list,"Glagladiateur" ,42        ,0.18  ,5   ,0.1     ,3      ,0.098  ,12  ,0.157   ,7      ,0.1        ,create_comp("En_garde!"            ,1      ,2      ,80   ,2    ,40    ,5   ));

    create_b_mob(list,name            ,50        ,0.12  ,20  ,0.1     ,10     ,0.11   ,10  ,0.1     ,12     ,0.1        ,create_comp("soin_supperieur"      ,1      ,2      ,105  ,0    ,0     ,7   ));

    perso joueur;
    create_mob(find_in_monstropedie(list,name),&joueur,1);

    map = map_create(map,sizeofmap);
    //show_map(map, 9);
    in_game(map,&joueur,list);
}


