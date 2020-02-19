#ifndef __h_perso__
#define __h_perso__

typedef struct stats perso;

struct stats{
    char    *name;
    int     lvl;
    int     exp;
    float   lvl_up_impact[5];
    /*plus bas seront les BASES STATS*/
    int     b_attac;
    int     b_deff;
    int     b_speed;
    int     b_hp;
    int     b_mana;
    /*ceux la seront les vrais stat*/
    float   attac;
    float   deff;
    float   speed;
    float   hp;
    float   mana;
};

#endif // __h_perso__
