
#include "header.h"



int    combat(perso    *player,perso    *mob)
{
    int touche;
    int en_combat = 1;
    int action;
    int action_mob;

    srand(time(NULL));
    color(12,0);
    printf("\nEN COMBAT !!!\n");
    color(3,0);
    Sleep(1000);
    system("cls");
    color(3,0);
    show_combat(player,mob);
    while (en_combat)
    {
        action = 0;
        action_mob = rand()%2+1;
        touche = _getch();
        color(3,0);



        if (touche==97 || touche == 65)  // fleche bas
        {
            action = 1;
        }
        if (touche==122 || touche == 90)  // fleche haut
        {
            action = 2;
        }
        if (touche==113 || touche == 75)  // fleche gauche
        {
            action = 3;
        }
        if (action == 1)
        {
            if (player->speed >= mob->speed)
            {
                attaque(player,mob,player,mob);
                if (player->hp <= 0)
                    return 0;
                if (mob->hp <= 0)
                    return 1;
                if (action_mob==1)
                    attaque(mob,player,player,mob);
                if (action_mob==2)
                {
                    do_comp(mob,player,player,mob);
                }

            }
            else
            {
                if (action_mob==1)
                    attaque(mob,player,player,mob);
                if (action_mob==2)
                    do_comp(mob,player,player,mob);
                if (player->hp <= 0)
                    return 0;
                if (mob->hp <= 0)
                    return 1;
                attaque(player,mob,player,mob);
            }

        }
        if (action == 2)
        {
            if (player->speed >= mob->speed)
            {
                do_comp(player,mob,player,mob);
                if (player->hp <= 0)
                    return 0;
                if (mob->hp <= 0)
                    return 1;
                if (action_mob==1)
                    attaque(mob,player,player,mob);
                if (action_mob==2)
                {
                    do_comp(mob,player,player,mob);
                }

            }
            else
            {
                if (action_mob==1)
                    attaque(mob,player,player,mob);
                if (action_mob==2)
                    do_comp(mob,player,player,mob);
                if (player->hp <= 0)
                    return 0;
                if (mob->hp <= 0)
                    return 1;
                do_comp(player,mob,player,mob);
            }

        }
        if (action == 3)
        {
            if (player->speed >= mob->speed)
            {
                if (flee())
                {
                    return 2;
                }
                if (action_mob==1)
                    attaque(mob,player,player,mob);
                if (action_mob==2)
                {
                    do_comp(mob,player,player,mob);
                }

            }
            else
            {
                if (action_mob==1)
                    attaque(mob,player,player,mob);
                if (action_mob==2)
                    do_comp(mob,player,player,mob);
                if (player->hp <= 0)
                    return 0;
                if (mob->hp <= 0)
                    return 1;
                if (flee())
                {
                    return 2;
                }
            }
        }

        if (player->hp <= 0)
            return 0;
        if (mob->hp <= 0)
            return 1;
        system("cls");
        show_combat(player,mob);
    }
}

int     flee()
{
    srand(time(NULL));
    int random = rand();

    if(random%3==1)
    {
        printf("vous avez fuis !\n");
        _getch();
        return 1;
    }
    else
    {
        printf("vous avez pas reussi a fuir ...\n");
        _getch();
        return 0;
    }

}


void    attaque(perso *attaquant,perso *defenseur, perso *player, perso *mob)
{
    float     dammage_to_do_f;
    float     dammage_to_endure_f;
    int       dammage_to_endure_i;

    float     attk = attaquant->attac;
    float     deff = defenseur->deff;

    dammage_to_do_f = (attk+(attk*10/100));
    dammage_to_endure_f = dammage_to_do_f-(dammage_to_do_f/(100/(deff+1)));
    dammage_to_endure_i = dammage_to_endure_f/1;

    defenseur->hp -= dammage_to_endure_i;

    printf("%s frappe %s de toute ces forces,\n%s inflige %d point%c de degat%c",attaquant->name,defenseur->name,attaquant->name,dammage_to_endure_i,dammage_to_endure_i>1?'s':' ',dammage_to_endure_i>1?'s':' ');
    _getch();
    system("cls");
    show_combat(player,mob);
    printf("%s frappe %s de toute ces forces,\n%s inflige %d point%c de degat%c\n",attaquant->name,defenseur->name,attaquant->name,dammage_to_endure_i,dammage_to_endure_i>1?'s':' ',dammage_to_endure_i>1?'s':' ');
}

void    do_comp(perso *attaquant, perso *defenseur, perso *player, perso *mob)
{
    float     dammage_to_do_f;
    float     dammage_to_endure_f;
    int       dammage_to_endure_i;

    float     attk = attaquant->attac;
    int       ratio_attk = attaquant->comp->attk_boost;
    float     deff = defenseur->deff;

    if (attaquant->comp->cost <= attaquant->mana/1)
    {
        if (attaquant->comp->target==2)
        {

            dammage_to_do_f = (attk+(attk*ratio_attk/100));
            dammage_to_endure_f = dammage_to_do_f-(dammage_to_do_f/(100/(deff+1)));
            dammage_to_endure_i = dammage_to_endure_f/1;

            defenseur->hp -= dammage_to_endure_i;

            if (attaquant->comp->bonus_effect == 1 || attaquant->comp->bonus_effect==-1)
            {
                defenseur->attac = (defenseur->attac)+((attaquant->comp->bonus_effect > 0 ? 1 : -1)*attaquant->comp->bonus_effect_rate/100.0 * defenseur->attac);
            }
            if (attaquant->comp->bonus_effect==2 || attaquant->comp->bonus_effect==-2)
            {
                defenseur->deff = (defenseur->deff)+((attaquant->comp->bonus_effect > 0 ? 1 : -1)*attaquant->comp->bonus_effect_rate/100.0 * defenseur->deff);
            }
            if (attaquant->comp->bonus_effect==3 || attaquant->comp->bonus_effect==-3)
            {
                defenseur->speed = (defenseur->speed)+((attaquant->comp->bonus_effect > 0 ? 1 : -1)*attaquant->comp->bonus_effect_rate/100.0 * defenseur->speed);
            }

        }
        else
        {
            dammage_to_endure_i = (attk+(attk*ratio_attk/100))/1;
            attaquant->hp += dammage_to_endure_i;

        }
        if (attaquant->hp >attaquant->hp_max)
            attaquant->hp = attaquant->hp_max;
        if (defenseur->hp >defenseur->hp_max)
            defenseur->hp = defenseur->hp_max;
        attaquant->mana -= attaquant->comp->cost;

        printf("%s utilise:\"%s\" sur %s,\n%s %s %d point%c de degat%c\n",attaquant->name,attaquant->comp->name,(attaquant->comp->target == 1 ? attaquant->name : defenseur->name),(attaquant->comp->target == 1 ? attaquant->name : defenseur->name),(attaquant->comp->target == 1 ? "se soigne de" : "subit"),dammage_to_endure_i,dammage_to_endure_i>1?'s':' ',dammage_to_endure_i>1?'s':' ');
         if (attaquant->comp->bonus_effect==1 || attaquant->comp->bonus_effect==-1)
        {
            attaquant->attac = (attaquant->attac)+(((attaquant->comp->bonus_effect > 0 ? 1 : -1)*attaquant->comp->bonus_effect_rate/100.0 )* attaquant->attac);
            printf("%s a augmente son attaque de %d %% \n",attaquant->name,attaquant->comp->bonus_effect_rate);
        }
        if (attaquant->comp->bonus_effect==2 || attaquant->comp->bonus_effect==-2)
        {
            attaquant->deff = (attaquant->deff)+(((attaquant->comp->bonus_effect > 0 ? 1 : -1)*attaquant->comp->bonus_effect_rate/100.0 )* attaquant->deff);
            printf("%s a augmente sa deffense de %d %% \n",attaquant->name,attaquant->comp->bonus_effect_rate);
        }
        if (attaquant->comp->bonus_effect==3 || attaquant->comp->bonus_effect==-3)
        {
            attaquant->speed = (attaquant->speed)+(((attaquant->comp->bonus_effect > 0 ? 1 : -1)*attaquant->comp->bonus_effect_rate/100.0 )* attaquant->speed);
            printf("%s a augmente sa vitesse de %d %% \n",attaquant->name,attaquant->comp->bonus_effect_rate);
        }
        _getch();
        system("cls");
        show_combat(player,mob);
        printf("%s frappe %s de toute ces forces,\n%s inflige %d point%c de degat%c\n",attaquant->name,defenseur->name,attaquant->name,dammage_to_endure_i,dammage_to_endure_i>1?'s':' ',dammage_to_endure_i>1?'s':' ');

    }
    else
    {
        printf("%s utilise:\"%s\" sur %s,\nmais son mana est insuffisant",attaquant->name,attaquant->comp->name,(attaquant->comp->target == 1 ? attaquant->name : defenseur->name));
        _getch();
        system("cls");
        show_combat(player,mob);
        printf("%s utilise:\"%s\" sur %s,\nmais son mana est insuffisant\n",attaquant->name,attaquant->comp->name,(attaquant->comp->target == 1 ? attaquant->name : defenseur->name));
    }
}

void    show_combat(perso    *player,perso    *mob)
{
    int     marge;
    int     ligne = 0;
    int     colonne;
    int     num_char_in_name;
    char    to_input;

    int hp_play = player->hp/1;
    int mana_play = player->mana/1;
    int differenciel_mob_hp = ((mob->hp/mob->hp_max)/0.01)/1;
    int differenciel_mob_mana = ((mob->mana/mob->mana_max)/0.01)/1;
    int differenciel_play_hp =((player->hp/player->hp_max)/0.01)/1;
    int differenciel_play_mana =((player->mana/player->mana_max)/0.01)/1;


    while (ligne <= 10)
    {
        color(0,0);


        marge = 7;
        num_char_in_name = 0;
        colonne = marge;
        color(1,3);
        //printf("L%dM%dC%d",ligne,marge,colonne);
        while (marge)
        {
            color(0,0);
            printf(" ");
            marge--;
        }
        marge = colonne;
        while(colonne < 80-marge)
        {
            to_input = ' ';
            color(0,0);

            if (ligne == 1)
            {

                if (colonne >= (80-marge)-27 )
                {

                    if (mob->name[num_char_in_name])
                    {
                        to_input = mob->name[num_char_in_name];
                        num_char_in_name++;

                    }
                    color(2,0);

                    if (!(mob->name[num_char_in_name]) && colonne == (80-marge)-7)
                            printf("lvl:%d",mob->lvl);

                }


            }
            if (ligne == 2)  //barre de vie mob
            {
                if (colonne >= (80-marge)-27 && colonne <= 80-marge-7 )
                {
                    if (differenciel_mob_hp/*84*/ > 5*(colonne - (80-26-marge) ))
                    {
                        color(7,4);
                    }

                    else
                        color(4,7);
                }


            }
            if (ligne == 3)  //barre de mana mob
            {
                if (colonne >= (80-marge)-27 && colonne <= 80-marge-7 )
                {
                    if (differenciel_mob_mana/*84*/ > 5*(colonne - (80-26-marge) ))
                    {
                        color(1,11);
                    }

                    else
                        color(11,7);
                }


            }


            if (ligne == 6)
            {

                if (colonne >= marge && colonne < marge + 20)
                {

                    if (player->name[num_char_in_name])
                    {
                        to_input = player->name[num_char_in_name];
                        num_char_in_name++;
                    }
                    color(2,0);
                    if (!(player->name[num_char_in_name]) && colonne == marge + 20-2)
                            printf("lvl:%d",player->lvl);

                }

            }

            if (ligne == 7)  //barre de vie player
            {
                if (colonne >= marge && colonne <= marge + 20)
                {
                    if (differenciel_play_hp > 5*(colonne - marge - 1))
                        color(0,4);
                    else
                        color(0,7);
                }
            }
            if (ligne == 8)  //barre de mana player
            {
                if (colonne >= marge && colonne <= marge + 20)
                {
                    if (differenciel_play_mana > 5*(colonne - marge - 1))
                        color(7,11);
                    else
                        color(11,7);
                }
            }
            if (ligne == 9)  //liste des choix
            {
                if (colonne>=marge && colonne <= 80-marge)
                {
                    to_input = 'x';
                }

            }

            if ((ligne != 7 || colonne != marge) &&( ligne != 8 || colonne != marge) && (ligne != 2 || colonne != (80-27-marge)) &&( ligne != 3 || colonne != (80-27-marge)))
                printf("%c",to_input);
            else
            {
                if (ligne ==7)
                {
                    color(4,7);
                    printf("pv:%d",hp_play);
                }
                if (ligne == 8)
                {
                    color(11,7);
                    printf("mana:%d",mana_play);
                }
                if (ligne ==2)
                {
                    color(4,7);
                    printf("pv:");
                }
                if (ligne == 3)
                {
                    color(11,7);
                    printf("mana:");
                }

            }
            colonne++;

        }

        color(1,3);
        //printf("L%dM%dC%d",ligne,marge,colonne);
        color(0,0);
        printf("\n");
        ligne++;
    }
    color(3,0);


    printf("\n        a:attaque cout:0           z:%s cout:%d",player->comp->name,player->comp->cost);
    printf("\n\n        q:fuir    cout:0\n");
}

