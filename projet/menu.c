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
    t_Monstropedie *monstropedie;
    monstropedie = initiate_mob_Monst();
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
        respond("scenario : fini (a 100%)\n");
        respond("deplacement : 0\n");
        respond("item : 0\n");
        respond("attaque critique : 0\n");
        respond("monstre : fini (à 90%)\n\n");

        }
        if (choice == '$') //   ZONE DE TEST, mettre ici les fonctions a essayer , et entrez $ pour la demmarer dans le menu
        {
            personnage(monstropedie);
        }
        respond("connais pas\n");
        ask_space(&choice);

    }
    if (choice == '1')
    {
        int ***map;
        system("cls");
        printf("\n");
        respond("not update ...\n\n");
        //personnage();
        map = map_create(map,6);
        show_map(map,6);
        //printf("ok");
        //back_to_menu(3);

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

