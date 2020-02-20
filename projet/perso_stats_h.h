#ifndef __h_perso__
#define __h_perso__

typedef struct stats b_perso;
typedef struct character perso;
typedef struct list_mob t_Monstropedie;
typedef struct joueur player;


struct stats{
    char    *name;
    float   lvl_up_impact[5];
    /*plus bas seront les BASES STATS*/
    int     b_attac;
    int     b_deff;
    int     b_speed;
    int     b_hp;
    int     b_mana;
};

struct character{
    char    *name;
    int     lvl;
    /*ceux la seront les vrais stat*/
    float   attac;
    float   deff;
    float   speed;
    float   hp;
    float   mana;
};


struct list_mob{

    b_perso  La_belle_mere;
    b_perso  Ali_ton_ami;
    b_perso  Gout_Loom;
    b_perso  Farmer;
    b_perso  En_garde;
};


#endif // __h_perso__
