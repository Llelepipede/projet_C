#include "header.h"


void    menu()
{

    int choice = 0;
    color(3,0);
    printf("\t\t\t-MAIN MENU-\n\n\t\t1. Create New Game\n\t\t2. Load Saved Game\n\t\t3. About\n\t\t4. Exit\n");
    choice = _getch();
    Sleep(300);
    t_Monstropedie *monstropedie;
    monstropedie = initiate_mob_Monst();
    if (!(choice == 38 || choice == 130 || choice == 34 || choice == 39 || choice == 49 || choice == 50 || choice == 51 || choice == 52))
    {
        system("cls");
        if (choice == 42 || choice == 230) //etat du projet , tapez * pour faire apparaitre dans le menu
        {
            respond("\tetat du projet\n");
            respond("menu jeu : fait\n");
            respond("stat personnage: fini (a 100%)\n");
            respond("sauvegarde : 0\n");
            respond("map : fini (a 95%) atributions des cases pas deffinies\n");
            respond("combat : fini (a 100%)\n");
            respond("scenario : fini (a 100%)\n");
            respond("deplacement : fini (a 100%)\n");
            respond("item : 0\n");
            respond("attaque critique : 0\n");
            respond("monstre : fini (a 100%)\n\n");
            test_color();
        }
        if (choice == 36) //   ZONE DE TEST, mettre ici les fonctions a essayer , et entrez $ pour la demmarer dans le menu
        {
            personnage(monstropedie);
        }

        if (choice == 39 || choice == 52)
        {
            respond("A la prochaine :)\n");
            return;
        }

        respond("connais pas\n");
        back_to_menu(3);


    }
    if (choice == 38 || choice == 49)
    {
        system("cls");
        printf("\n");
        //personnage();
        new_game();
        //printf("ok");
        back_to_menu(3);

    }
    else if (choice == 130 || choice == 50)
    {
        //load_game();
        system("cls");
        printf("\n");
        respond("not update ...\n\n");
        back_to_menu(3);
    }
    else if (choice == 34 || choice == 51)
    {
        system("cls");
        about();
        back_to_menu(3);
    }
    else if (choice == 39 || choice == 52)
     {
            respond("A la prochaine :)\n");
            return;

     }

}

