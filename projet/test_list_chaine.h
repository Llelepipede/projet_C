#ifndef __h_item__
#define __h_item__

typedef struct s_item t_item;

struct s_item{
    char    name;
    int     power;
    int     effect;
    t_item  *next;
};

#endif
