#include "header.h"


void    in_game(t_map ***map,perso *joueur,t_Monstropedie *list)
{
    int touche;
    int on_mob = 0;
    perso mob;
    int random_lvl;

    int compteur_dep = 0;
    int random1;
    int random2;
    int random3;
    int random4;

    int x_map;
    int y_map;
    int x_case;
    int y_case;

    int *pos_joueur_map = (int*)malloc(sizeof(int)*2);
    int *pos_joueur = (int*)malloc(sizeof(int)*2);
    int *pos_joueur_memory;



    pos_joueur_map = to_find_in_map(map,9,1);
    pos_joueur = to_find_in_case(map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type,7,1);

    int result_combat=0;
    char *mob_name;

    srand(time(NULL));
    show_map(map,9);
    while (1)
    {
        if (compteur_dep%25 == 0)
        {
            do{
                random1 = rand()%9;
                random2 = rand()%9;
            }while (map[random1][random2]->map_type->event == 1);
            map[random1][random2]->map_type->event=1;
            do{
                random3 = rand()%7;
                random4 = rand()%7;
            } while ((map[random1][random2]->map_type->design[random3][random4].maj) && (map[random1][random2]->map_type->design[random3][random4].case_teleporteur) && (map[random1][random2]->map_type->design[random3][random4].mob) && !(map[random1][random2]->map_type->design[random3][random4].passable));


            map[random1][random2]->map_type->design[random3][random4].mob=1;
            map[random1][random2]->map_type->design[random3][random4].passable=1;
        }
        if (result_combat!=2)
            pos_joueur_memory = pos_joueur;
        mob_name = "NULL";
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {

            touche = _getch();
            if (touche==80)  // fleche bas
            {
                compteur_dep++;
                on_mob = deplacement(map,'s');
            }
            if (touche==72)  // fleche haut
            {
                compteur_dep++;
                on_mob = deplacement(map,'z');
            }
            if (touche==75)  // fleche gauche
            {
                compteur_dep++;
                on_mob = deplacement(map,'q');
            }
            if (touche==77)  // fleche droite
            {
                compteur_dep++;
                on_mob = deplacement(map,'d');
            }

        }
        pos_joueur_map = to_find_in_map(map,9,1);
        pos_joueur = to_find_in_case(map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type,7,1);

        x_map = pos_joueur_map[0];
        y_map = pos_joueur_map[1];
        x_case= pos_joueur[0];
        y_case= pos_joueur[1];
        if (on_mob)
        {
            random_lvl = rand()%6;
            if (on_mob == 3)
                mob_name = "glagladiateur";
            if (on_mob == 2)
                mob_name = "farmer";
            if (on_mob == 1)
                mob_name = "farmer";
            if (on_mob == 4)
                mob_name = "farmer";
            create_mob(find_in_monstropedie(list,mob_name),&mob,joueur->lvl+(random_lvl-3));
            result_combat = combat(joueur,&mob);
            if (result_combat == 1)
            {
                map[x_map][y_map]->map_type->event=0;
                map[x_map][y_map]->map_type->design[x_case][y_case].mob=0;
            }
            if (result_combat == 0)
            {
                system("cls");
                printf("\n\n\n");
                respond("G A M E   O V E R\n\n");
                free(list);
                free(map);
                free(joueur);
                free(pos_joueur_map);
                free(pos_joueur);
                return 0;
            }
            if (result_combat == 2)
            {
                map[x_map][y_map]->map_type->design[x_case][y_case].maj=0;
                map[x_map][y_map]->map_type->design[pos_joueur_memory[0]][pos_joueur_memory[1]].maj=1;
            }


        }
        show_map(map,9);
    }
}
