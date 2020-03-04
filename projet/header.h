#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct  stats       b_perso;
typedef struct  list_mob    t_Monstropedie;
typedef struct  character   perso;
typedef struct  joueur      player;

void            set_to_zero(perso *mob);
int             start();
void            menu();
void            ask_space(char *choice);
void            respond(char *sentence);
void            about();
void            new_game();
int             ***map_create();
void            personnage(t_Monstropedie *list);
void            set_lvl_up(b_perso base,perso *mob,int lvl);
void            show_stat_of(perso mob);
t_Monstropedie  create_Monstropedie();
void            make_and_show(b_perso base,perso *mob,int lvl);
b_perso         initiate_mob(b_perso *previous,b_perso *next);
t_Monstropedie  *initiate_mob_Monst();
void            add_mob(t_Monstropedie *list,b_perso *mob);
void            back_to_menu(int time);
void            create_b_mob(t_Monstropedie *list,char *name, int hp, float hp_lvl, int attaque, float attaque_lvl, int deffense, float deffense_lvl, int vitesse, float vitesse_lvl);
b_perso         *find_in_monstropedie(t_Monstropedie *m_list,char *name);
void            deplacement(int ***map,char     moov);
int             *to_find_in_map(int ***map, int sizeofmap ,int player_type);
void            show_map(int ***map,int sizeofmap);
#endif // HEADER_H_INCLUDED
