#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"
#include <time.h>
#include <windows.h>


void    new_game()
{
    int     sizeofmap = 9;
    int     ***map;

    t_Monstropedie *list;
    list = initiate_mob_Monst();

    create_b_mob(list,"janin_genieux" ,300       ,0.1   ,33     ,0.1    ,20  ,0.1     ,27     ,0.1        );
    create_b_mob(list,"la_belle_mere" ,50        ,0.108 ,37     ,0.087  ,12  ,0.04    ,23     ,0.1        );
    create_b_mob(list,"ali_ton_ami"   ,100       ,0.1   ,20     ,0.07   ,30  ,0.12    ,15     ,0.067      );
    create_b_mob(list,"gout_loom"     ,125       ,0.13  ,17     ,0.098  ,40  ,0.157   ,27     ,0.1        );
    create_b_mob(list,"farmer"        ,35        ,0.18  ,12     ,0.098  ,7   ,0.157   ,14     ,0.1        );
    create_b_mob(list,"glagladiateur" ,42        ,0.18  ,8      ,0.098  ,10  ,0.157   ,7      ,0.1        );
    create_b_mob(list,"joueur"        ,50        ,0.1   ,10     ,0.1    ,10  ,0.1     ,10     ,0.1        );

    perso joueur;
    create_mob(find_in_monstropedie(list,"joueur"),&joueur,5);

    map = map_create(map,sizeofmap);

    //show_map(map, 9);
    in_game(map,joueur,list);
}


