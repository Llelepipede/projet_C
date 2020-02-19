#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct stats perso;
int     start();
int     menu();
void    ask_space();
void    respond(char *sentence);
void    about();
void    new_game();
int     ***map_create();
void    personnage();
void    set_lvl_up(perso *monster);
void    show_stat_of();
#endif // HEADER_H_INCLUDED
