#include "header.h"


void    new_game()
{
    int     sizeofmap = 9;
    t_map     ***map;
    char    name[20];
    int     i=0;
    t_Monstropedie *list;
    list = initiate_mob_Monst();
    respond("Quelle est votre nom ? (- de 20 caracteres)\n");
    scanf("%s",&name);
    printf("\n ??? : Bienvenue %s \n\n",name);
    _getch();
    printf(" %s : Qui etes vous ? \n\n",name);
    _getch();
    printf(" Janin Genieux : Je suis Janin Genieux, je suis la pour te guider dans cette aventure. Ta quete est de detruire le \ndemoniaque Gout loom, cependant il est protege par les quatres gardiens, chef des districts \n(PS : Couleur differentes sur la carte). \n\n");
    _getch();
    printf("%s : Pourquoi moi ? \n\n",name);
    _getch();
    printf(" Janin Genieux : Tu es l'elu, le divin heritier du SAINT COUTEAU CASQUE, tiens va et finis ta quete \n(PS : Pssst je reviens apres le gouter). \n\n");
    _getch();
    printf(" *pouf Janin Genieux disparait dans un ecran de fumee* \n\n");
    _getch();
    printf(" %s : Attends part pas, il me reste tant de questions a te poser. \nPfff je retourne a la fika \n\n",name);
    _getch();
                                     //Heal point|hp/lvl|mana|mana/lvl|attaque|att/lvl|deff|deff/lvl|vitesse|vitesse/lvl|competence  |name                  |target |effect |attk%|bonus|bonus%|cost
    create_b_mob(list,"Janin Genieux" ,300       ,0.1   ,50  ,0.1     ,20     ,0.1    ,10  ,0.1     ,27     ,0.1        ,create_comp("Okan au tableau!"     ,2      ,1      ,200  ,-2   ,40    ,3   ));
    create_b_mob(list,"La Belle Mere" ,50        ,0.135 ,10  ,0.1     ,22     ,0.087  ,6   ,0.04    ,23     ,0.1        ,create_comp("ton_ex_etait_mieux"   ,2      ,1      ,70   ,0    ,0     ,12  ));
    create_b_mob(list,"Ali ton ami"   ,100       ,0.1   ,9   ,0.1     ,15     ,0.07   ,15  ,0.12    ,15     ,0.067      ,create_comp("annee vingt vingt"    ,2      ,1      ,60   ,0    ,0     ,4   ));
    create_b_mob(list,"Pakoafer"      ,150       ,0.1   ,50  ,0.1     ,13     ,0.06   ,10  ,0.12    ,7      ,0.067      ,create_comp("KaKette!"             ,1      ,2      ,30   ,0    ,0     ,2   ));
    create_b_mob(list,"Rasta-blanc"   ,80        ,0.1   ,50  ,0.1     ,17     ,0.1    ,2   ,0.12    ,23     ,0.067      ,create_comp("Matrix"               ,2      ,1      ,100  ,0    ,0     ,6   ));
    create_b_mob(list,"Gout Loom"     ,150       ,0.13  ,30  ,0.1     ,12     ,0.098  ,20  ,0.157   ,27     ,0.1        ,create_comp("LA_FERME"             ,2      ,1      ,70   ,0    ,0     ,10  ));
    create_b_mob(list,"Farmer"        ,35        ,0.18  ,10  ,0.1     ,6      ,0.1    ,7   ,0.157   ,14     ,0.1        ,create_comp("libertine"            ,1      ,2      ,50   ,1    ,20    ,6   ));
    create_b_mob(list,"Jony"          ,38        ,0.18  ,9   ,0.1     ,7      ,0.098  ,3   ,0.157   ,9      ,0.1        ,create_comp("Allumer_le_feu"       ,2      ,1      ,60   ,0    ,0     ,7   ));
    create_b_mob(list,"Roucky"        ,30        ,0.18  ,11  ,0.1     ,5      ,0.1    ,15  ,0.157   ,16     ,0.1        ,create_comp("Coup_D'tete"          ,2      ,1      ,30   ,0    ,0     ,2   ));
    create_b_mob(list,"Glagladiateur" ,42        ,0.18  ,5   ,0.1     ,3      ,0.098  ,12  ,0.157   ,7      ,0.1        ,create_comp("En_garde!"            ,1      ,2      ,80   ,2    ,40    ,5   ));

    create_b_mob(list,name            ,50        ,0.12  ,10  ,0.1     ,10     ,0.11   ,10  ,0.1     ,12     ,0.1        ,create_comp("soin_supperieur"      ,1      ,2      ,80   ,0    ,0     ,7   ));

    perso joueur;
    create_mob(find_in_monstropedie(list,name),&joueur,1);

    map = map_create(map,sizeofmap);
    //show_map(map, 9);
    in_game(map,&joueur,list);
}


