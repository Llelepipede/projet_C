#include <stdio.h>
#include <stdlib.h>
#include "perso_stats_h.h"
#include "header.h"


void    menu()
{
    char     choice = '0';
    color(3,0);
    printf("\t\t\t-MAIN MENU-\n\n\t\t1. Create New Game\n\t\t2. Load Saved Game\n\t\t3. About\n\t\t4. Exit\n");
    ask_space(&choice);

    while (!(choice>='1' && choice <='4'))
    {
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
            t_Monstropedie monstropedie;
            monstropedie = create_Monstropedie();
            personnage(monstropedie);
        }
        respond("connais pas\n");
        ask_space(&choice);

    }
    if (choice == '1')
    {
        printf("not update ...\n");
        //personnage();
        //new_game();
        //printf("ok");
        menu();

    }
    else if (choice == '2')
    {
        //load_game();
        printf("not update ...\n");
        menu();
    }
    else if (choice == '3')
    {
        about();
        menu();
    }
    else
        respond("A la prochaine :)\n");
}

