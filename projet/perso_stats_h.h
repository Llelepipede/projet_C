#ifndef __h_perso__
#define __h_perso__

typedef struct stats b_perso;
typedef struct character perso;
typedef struct list_mob t_Monstropedie;
typedef struct joueur player;
typedef struct  s_competence t_competence;

struct stats{
    char    *name;
    float   lvl_up_impact[5];
    /*plus bas seront les BASES STATS*/
    int         b_attac;
    int         b_deff;
    int         b_speed;
    int         b_hp;
    int         b_mana;


    t_competence *comp;


    b_perso     *previous;
    b_perso *next;
};

struct character{
    char    *name;
    int     lvl;
    /*ceux la seront les vrais stat*/
    float   attac;
    float   deff;
    float   speed;
    float   mana;
    float   mana_max;
    float   hp;
    float   hp_max;

    int     xp;
    int     xp_not_lvl_up;
    int     xp_to_lvlup;
    t_competence *comp;

};

struct s_competence{
    char    *name;
    int     target; //1=lanceur du sort, 2=ennemie

    int     effect; //1=damage, 2=soin
    int     attk_boost; //%de l'attaque convertis en effect
    int     bonus_effect; //1=boost l'atk, 2=boost def, 3=boost vitesse un nombre negatif fais la meme chose dans le debuff
    int     bonus_effect_rate; //%de boost/reduction
    int     cost; //cout de la competence
};

struct list_mob{
    b_perso first;
    b_perso last;
};



#endif // __h_perso__
