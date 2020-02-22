#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"
#include <time.h>
#include <windows.h>


void    menu()
{

    char     choice = '0';
    color(3,0);
    printf("\t\t\t-MAIN MENU-\n\n\t\t1. Create New Game\n\t\t2. Load Saved Game\n\t\t3. About\n\t\t4. Exit\n");
    ask_space(&choice);
    while (!(choice>='1' && choice <='4'))
    {
        system("cls");
        if (choice == '*') //etat du projet , tapez * pour faire apparaitre dans le menu
        {
        respond("\tetat du projet\n");
        respond("menu jeu : fait\n");
        respond("stat personnage: en cours(70%)\n");
        respond("sauvegarde : 0\n");
        respond("map : 0\n");
        respond("combat : 0\n");
        respond("scenario : 0\n");
        respond("deplacement : 0\n");
        respond("item : 0\n");
        respond("attaque critique : 0\n");
        respond("monstre : en cours(60%)\n\n");

        }
        if (choice == '$') //   ZONE DE TEST, mettre ici les fonctions a essayer , et entrez $ pour la demmarer dans le menu
        {
            t_Monstropedie *monstropedie;
            monstropedie = initiate_mob_Monst();
            personnage(monstropedie);
        }
        respond("connais pas\n");
        ask_space(&choice);

    }
    if (choice == '1')
    {
        system("cls");
        printf("\n");
        respond("not update ...\n\n");
        //personnage();
        //new_game();
        //printf("ok");
        back_to_menu(3);

    }
    else if (choice == '2')
    {
        //load_game();
        system("cls");
        printf("\n");
        respond("not update ...\n\n");
        back_to_menu(3);
    }
    else if (choice == '3')
    {
        system("cls");
        about();
        back_to_menu(3);
    }
    else
        respond("A la prochaine :)\n");

}

