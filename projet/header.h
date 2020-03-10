#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "map.h"
#include "perso_stats_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>




/*perso_stats_h.h*/
typedef struct  stats       b_perso;
typedef struct  list_mob    t_Monstropedie;
typedef struct  character   perso;
typedef struct  joueur      player;

/*map.h*/
typedef struct s_case_type  t_case_type;
typedef struct s_map_type   t_map_type;
typedef struct s_map        t_map;

/*start.c*/
int             start();

/*menu.c*/
void            menu();

/*about.c*/
void            about();

/*visual_change.c*/
void            ask_space(char *choice);
void            back_to_menu(int time);
void            respond(char *sentence);
void            color(int text,int font);

/*perso_stats.c*/
void            personnage(t_Monstropedie *list);
void            create_mob(b_perso *base, perso *mob,int lvl);
void            set_to_zero(perso *mob);
void            set_lvl_up(b_perso base,perso *mob,int lvl);
void            show_stat_after_fight(perso monster,int     xp_earn);
void            show_stat_of(perso monster);
void            lvl_up(perso    *mob,b_perso    *base);
void            heal(perso  *mob);

/*monstropedie_init.c*/
t_Monstropedie  *initiate_mob_Monst();
b_perso         initiate_mob(b_perso *previous,b_perso *next);

/*monstropedie_update.c*/
void            create_b_mob(t_Monstropedie *list,char *name, int hp, float hp_lvl, int mana, float , int attaque, float attaque_lvl, int deffense, float deffense_lvl, int vitesse, float vitesse_lvl, t_competence *comp);
void            add_mob(t_Monstropedie *list,b_perso *mob);

/*monstropedie_use.c*/
b_perso         *find_in_monstropedie(t_Monstropedie *m_list,char *name);

/*new_game.c*/
void            new_game();

/*map_and_more.c*/
t_map           ***map_create(t_map ***map,int sizeofmap);
int             *to_find_in_map(t_map ***map, int sizeofmap ,int player_type);
int             *to_find_in_case(t_map_type *map_type, int sizeofmap ,int player_type);
void            show_map(t_map ***map,int sizeofmap);

/*moove.c*/
int             deplacement(t_map ***map,char     moov);

/*test_color.c*/
void  test_color();

/*in_game*/
void    in_game(t_map ***map,perso *joueur,t_Monstropedie *list);

/*combat.c*/
int    combat(perso    *player,perso    *mob);
int     flee();
void    do_comp(perso *attaquant, perso *defenseur, perso *player, perso *mob);
void    attaque(perso *attaquant, perso *defenseur, perso *player, perso *mob);
void    show_combat(perso    *player,perso    *mob);

#endif // HEADER_H_INCLUDED
