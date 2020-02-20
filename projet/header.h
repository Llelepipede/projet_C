#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct stats b_perso;
typedef struct list_mob t_Monstropedie;
typedef struct character perso;
typedef struct joueur player;

void    set_to_zero(perso *mob);
int     start();
void    menu();
void    ask_space();
void    respond(char *sentence);
void    about();
void    new_game();
int     ***map_create();
void    personnage(list_mob);
void    set_lvl_up(b_perso base,perso *mob,int lvl);
void    show_stat_of(perso mob);
t_Monstropedie    create_Monstropedie();

#endif // HEADER_H_INCLUDED
