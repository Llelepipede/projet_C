#include "header.h"


void    in_game(t_map ***map,perso *joueur,t_Monstropedie *list)
{
    int touche;
    int on_mob = 0;
    perso mob;
    int random_lvl;
    int nb_of_mob = 0;
    int xp_earn;

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
    color(3,0);
    while (1)
    {
        show_ath();
        int on_mob = 0;

        if (compteur_dep%25 == 0 && nb_of_mob<8)
        {
            do{
                random1 = rand()%9;
                random2 = rand()%9;
            }while (map[random1][random2]->map_type->event == 1);
            map[random1][random2]->map_type->event=1;
            do{
                random3 = rand()%7;
                random4 = rand()%7;
            } while ((map[random1][random2]->map_type->design[random3][random4].maj) || (map[random1][random2]->map_type->design[random3][random4].heal) ||(map[random1][random2]->map_type->design[random3][random4].case_teleporteur) || (map[random1][random2]->map_type->design[random3][random4].mob) || !(map[random1][random2]->map_type->design[random3][random4].passable));


            map[random1][random2]->map_type->design[random3][random4].mob=1;
            map[random1][random2]->map_type->design[random3][random4].passable=1;
            nb_of_mob++;
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
        if (touche==115 || touche == 83)
        {
            system("cls");
            show_stat_of(*joueur);
        }
        if (touche == 27)
        {
            system("cls");
            respond("etes-vous sur de vouloir quiter ? \n\t\t(appuyez sur entr pour valider)\n\n");
            touche = _getch();
            if (touche == 13)
            {
                free(list);
                free(map);
                free(joueur);
                free(pos_joueur_map);
                free(pos_joueur);
                return;
            }

        }

        pos_joueur_map = to_find_in_map(map,9,1);
        pos_joueur = to_find_in_case(map[pos_joueur_map[0]][pos_joueur_map[1]]->map_type,7,1);

        x_map = pos_joueur_map[0];
        y_map = pos_joueur_map[1];
        x_case= pos_joueur[0];
        y_case= pos_joueur[1];
        if (map[x_map][y_map]->map_type->design[x_case][y_case].heal)
        {
            heal(joueur);
        }

        if (on_mob)
        {
            if ((x_map == 1 && y_map == 2) || (x_map == 2 && y_map == 7) || (x_map == 7 && y_map == 6) || (x_map == 6 && y_map == 1))
            {
                random_lvl = joueur->lvl + 8;
                random_lvl = random_lvl>10 ? 10 : random_lvl;
                if (on_mob == 3)
                    mob_name = "Rasta-blanc";
                if (on_mob == 2)
                    mob_name = "Ali ton ami";
                if (on_mob == 1)
                    mob_name = "La Belle Mere";
                if (on_mob == 4)
                    mob_name = "Pakoafer";
            }
            else
            {
                random_lvl = rand()%6;
                random_lvl = joueur->lvl+(random_lvl-3);
                if (random_lvl<1)
                    random_lvl = 1;
                if (on_mob == 3)
                    mob_name = "Glagladiateur";
                if (on_mob == 2)
                    mob_name = "Jony";
                if (on_mob == 1)
                    mob_name = "Farmer";
                if (on_mob == 4)
                    mob_name = "Roucky";
            }
            create_mob(find_in_monstropedie(list,mob_name),&mob,random_lvl);
            result_combat = combat(joueur,&mob);
            if (result_combat == 1)
            {
                xp_earn = sqrt(mob.xp)*(((mob.lvl-1)/mob.lvl)+1);
                show_stat_after_fight(*joueur,xp_earn);
                joueur->xp_not_lvl_up += xp_earn;
                while (joueur->xp_not_lvl_up >= joueur->xp_to_lvlup)
                {
                    lvl_up(joueur,find_in_monstropedie(list,joueur->name));
                }
                map[x_map][y_map]->map_type->event=0;
                map[x_map][y_map]->map_type->design[x_case][y_case].mob=0;
                if (!((x_map == 1 && y_map == 2) || (x_map == 2 && y_map == 7) || (x_map == 7 && y_map == 6) || (x_map == 6 && y_map == 1)))
                    nb_of_mob--;
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
                return ;
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
