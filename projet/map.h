#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

typedef struct s_case_type  t_case_type;
typedef struct s_map_type   t_map_type;
typedef struct s_map        t_map;

struct s_map {

    t_map_type *map_type; //type de la map , avec son design
    int maj; //si il y a le joueur, ou si il y est passer (0 = pas passe, 1 = le joueur, 2 = le joueur y est passe)

};

struct s_map_type {

    t_case_type **design;  //design de la carte
    int event;  //si il y a des monstre ou autre
    int color;  //couleur de la case affiché
    int district;
};

struct s_case_type {

    int passable;          //si 1, la case peut etre accecible
    int heal;              //si 1, la case soigne le joueur
    int mob;               //si 1, la case est occupé par un personnage adverse
    int butin;             //si 1, la case a un coffre.
    int case_teleporteur;  //si 1 ou plus, la case est un teleporteur ( 1 sud | 2 est | 3 ouest | 4 nord )
    int maj;               //si 1, la case accueil le joueur

    int  color;  //couleur de la case


};

#endif // MAP_H_INCLUDED
