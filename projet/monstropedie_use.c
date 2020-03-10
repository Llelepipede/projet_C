#include "header.h"


b_perso     *find_in_monstropedie(t_Monstropedie *m_list,char *name)
{
    b_perso *mob_lookup;
    mob_lookup = m_list->first.next;
    while ((strcmp(mob_lookup->name,m_list->first.name)))
    {
        if (!(strcmp(mob_lookup->name,name)))
        {
            return mob_lookup;
        }
        mob_lookup = mob_lookup->next;
        //printf("%s\n",mob_lookup->next->name);
    }
    return mob_lookup;
}
