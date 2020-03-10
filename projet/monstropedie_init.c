#include "header.h"

t_Monstropedie     *initiate_mob_Monst()
{
    t_Monstropedie *list = (t_Monstropedie*)malloc(sizeof(b_perso)*2);
    list->first = initiate_mob(NULL,&list->last);
    list->last = initiate_mob(&list->first,NULL);
    return list;
}
b_perso     initiate_mob(b_perso *previous,b_perso *next)
{
    b_perso *mob = (b_perso*)malloc(sizeof(b_perso));
    int i;
    mob->name = "Beg-end";
    mob->next = next;
    mob->previous = previous;
    mob->b_hp = 0;
    mob->b_attac = 0;
    mob->b_deff = 0;
    mob->b_mana = 0;
    mob->b_speed = 0;
    while (i<5)
    {
        mob->lvl_up_impact[i]=0;
        i++;
    }
    return *mob;
}


