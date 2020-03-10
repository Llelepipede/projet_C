
#include "header.h"


t_competence *create_comp(char *name,int target, int effect, int attk_boost, int bonus_effect, int bonus_effect_rate, int cost)
{
    t_competence *comp = (t_competence*)malloc(sizeof(t_competence));

    comp->name = (char*)malloc(sizeof(char)*20);
    comp->name = name;
    comp->target = target;
    comp->effect = effect;
    comp->attk_boost = attk_boost;
    comp->bonus_effect = bonus_effect;
    comp->bonus_effect_rate = bonus_effect_rate;
    comp->cost = cost;

    return comp;
}
