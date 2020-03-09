
#include "header.h"



void    combat(perso    *player,perso    *mob)
{
    int touche;
    int en_combat = 1;


    color(12,0);
    printf("\nEN COMBAT !!!\n");
    color(3,0);
    Sleep(1000);
    system("cls");

    test_color();
    color(3,0);
    show_combat(player,mob);
    while (en_combat)
    {

        touche = _getch();
        system("cls");
        test_color();
        color(3,0);
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {

            touche = _getch();
            /*if (touche==80)  // fleche bas
            {
                on_mob = deplacement(map,'s');
            }
            if (touche==72)  // fleche haut
            {
                on_mob = deplacement(map,'z');
            }
            if (touche==75)  // fleche gauche
            {
                on_mob = deplacement(map,'q');
            }
            if (touche==77)  // fleche droite
            {
                on_mob = deplacement(map,'d');
            }*/

        }
        show_combat(player,mob);
    }
}

void    show_combat(perso    *player,perso    *mob)
{
    int     marge;
    int     ligne = 0;
    int     colonne;
    int     num_char_in_name;
    char    to_input;
    mob->hp -= 5;
    player->hp -= 10;
    int differenciel_mob = ((mob->hp/mob->hp_max)/0.01)/1;
    int differenciel_play =((player->hp/player->hp_max)/0.01)/1;


    while (ligne < 10)
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

                if (colonne >= (80-marge)-20 )
                {

                    if (mob->name[num_char_in_name])
                    {
                        to_input = mob->name[num_char_in_name];
                        num_char_in_name++;
                    }
                    color(2,0);

                }

            }
            if (ligne == 2)  //barre de vie mob
            {
                if (colonne >= (80-marge)-20 && colonne <= 80-marge )
                {
                    if (differenciel_mob/*84*/ > 5*(colonne - (80-20-marge-1) ))
                    {
                        color(1,4);
                    }

                    else
                        color(0,7);
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

                }

            }

            if (ligne == 7)  //barre de vie player
            {
                if (colonne >= marge && colonne <= marge + 20)
                {
                    if (differenciel_play > 5*(colonne - marge - 1))
                        color(0,4);
                    else
                        color(0,7);
                }
            }
            printf("%c",to_input);
            colonne++;

        }

        color(1,3);
        //printf("L%dM%dC%d",ligne,marge,colonne);
        color(0,0);
        printf("\n");
        ligne++;
    }
    color(3,0);


    //printf("%f\n%d",mob->hp,differenciel);
}

