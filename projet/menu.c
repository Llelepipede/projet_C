#include <stdio.h>
#include <stdlib.h>


void    menu()
{
    int     choice = 0;
    color(3,0);
    printf("\t\t\t-MAIN MENU-\n\n\t\t1. Create New Game\n\t\t2. Load Saved Game\n\t\t3. About\n\t\t4. Exit\n");
    choice = ask_space();

    while (!(choice>=1 && choice <=4))
    {
        respond("connais pas\n");
        choice = ask_space();

    }
    if (choice == 1)
    {
        new_game();
        //printf("ok");
    }
    else if (choice == 2)
    {
        //load_game();
        printf("not update ...\n");
        menu();
    }
    else if (choice == 3)
    {
        about();
        menu();
    }
    else
        respond("A la prochaine :)\n");
}

