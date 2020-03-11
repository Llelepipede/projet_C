#include "header.h"


t_map   ***map_create(t_map ***map,int sizeofmap)
{
    int     colonne;
    int     ligne;


    colonne = 0;
    ligne = 0;

    int in_map_colonne = 0;
    int in_map_ligne = 0;

    srand(time(NULL));
    int random;
    /*Partie malloc*/
    /*elle conciste a creer un espace mémoire dedie a la map dans le jeu.
    cette map aura la forme d'un carre de taille "sizeofmap", avec dans chaque case du quadrillage ,
    2 valeurs: qu'es qui s'y trouve, et si un evenement s'y est passee*/

    if (!(map = (t_map***)malloc(sizeof(t_map**) * sizeofmap)))
        return (0);
    while (colonne < sizeofmap)
    {

        if (!(map[colonne] = (t_map**)malloc(sizeof(t_map*) * sizeofmap )))
            return (0);
        ligne = 0;
        while (ligne < sizeofmap)
        {
            in_map_colonne = 0;

            //printf("%d , %d\n",colonne,ligne);
            if (!(map[colonne][ligne] = (t_map*)malloc(sizeof(t_map))))
            {
                printf("not malloc");
                return (0);
            }
            map[colonne][ligne]->map_type = (t_map_type*)malloc(sizeof(t_map_type));
            map[colonne][ligne]->map_type->design = (t_case_type**)malloc(sizeof(t_case_type*)*7);
            map[colonne][ligne]->maj = 0;  //POUR TOUT AFFICHERRRR : 2, sinon 0
            map[colonne][ligne]->map_type->color = colonne < 4 && ligne <= 4 ? 2 : colonne <= 4 && ligne > 4 ? 4 : colonne >= 4 && ligne < 4 ? 3 : colonne == 4 && ligne == 4 ? 8 : 14 ; //est foret pour l'instant
            map[colonne][ligne]->map_type->event = 0; //aucun evenement
            if  (map[colonne][ligne]->map_type->color == 2)
                map[colonne][ligne]->map_type->district = 1; //aucun district
            else if  (map[colonne][ligne]->map_type->color == 4)
                map[colonne][ligne]->map_type->district = 2;
            else if  (map[colonne][ligne]->map_type->color == 3)
                map[colonne][ligne]->map_type->district = 3;
            else if  (map[colonne][ligne]->map_type->color == 14)
                map[colonne][ligne]->map_type->district = 4;
            else
                map[colonne][ligne]->map_type->district = 0;
            while(in_map_colonne <7)
            {
                map[colonne][ligne]->map_type->design[in_map_colonne] = (t_case_type*)malloc(sizeof(t_case_type)*7);
                in_map_ligne = 0;
                while(in_map_ligne < 7)
                {
                    //printf(">%d | %d \n> %d | %d\n",in_map_colonne,in_map_ligne,ligne,colonne);
                    //Sleep(10);
                    random = rand()%20;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].case_teleporteur = in_map_colonne == 0 && in_map_ligne == 3 ? 1 : in_map_colonne == 6 && in_map_ligne == 3 ? 4 : in_map_colonne == 3 && in_map_ligne == 0 ? 2 : in_map_colonne == 3 && in_map_ligne == 6 ? 3 : 0 ;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].passable = random == 1 && !(map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].case_teleporteur)? 0 : 1;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].heal = 0;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].mob = 0;
                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].butin = 0;

                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].maj = 0;

                    map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].color = random == 1 && !(map[colonne][ligne]->map_type->design[in_map_colonne][in_map_ligne].case_teleporteur)? 0 : colonne < 4 && ligne <= 4 ? 2 : colonne <= 4 && ligne > 4 ? 4 : colonne >= 4 && ligne < 4 ? 3 : colonne == 4 && ligne == 4 ? 8 : 14 ;
                    in_map_ligne++;
                }
                in_map_colonne++;
            }
            //printf("malloc done\n");
            ligne ++;
        }
        colonne++;
    }
    map[4][4]->maj = 1;
    map[4][4]->map_type->design[0][3].case_teleporteur = 1;
    map[4][4]->map_type->design[3][3].maj =1;
    map[6][2]->map_type->design[3][3].heal = 1;
    map[6][2]->map_type->design[3][3].passable = 1;
    map[6][6]->map_type->design[3][3].heal = 1;
    map[6][6]->map_type->design[3][3].passable = 1;
    map[2][6]->map_type->design[3][3].heal = 1;
    map[2][6]->map_type->design[3][3].passable = 1;
    map[2][2]->map_type->design[3][3].heal = 1;
    map[2][2]->map_type->design[3][3].passable = 1;

    map[1][2]->map_type->event = 1;
    map[1][2]->map_type->design[3][3].color = 13;
    map[1][2]->map_type->design[3][3].mob = 2;
    map[1][2]->map_type->design[3][3].passable = 1;

    map[2][7]->map_type->event = 1;
    map[2][7]->map_type->design[3][3].color = 13;
    map[2][7]->map_type->design[3][3].mob = 2;
    map[2][7]->map_type->design[3][3].passable = 1;

    map[7][6]->map_type->event = 1;
    map[7][6]->map_type->design[3][3].color = 13;
    map[7][6]->map_type->design[3][3].mob = 2;
    map[7][6]->map_type->design[3][3].passable = 1;

    map[6][1]->map_type->event = 1;
    map[6][1]->map_type->design[3][3].color = 13;
    map[6][1]->map_type->design[3][3].mob = 2;
    map[6][1]->map_type->design[3][3].passable = 1;

    //printf("%d\n",map[4][4]->map_type->design[1][1].color);
    //Sleep(300);
    //printf("malloc complete\n");
    return map;
}


int     *to_find_in_map(t_map ***map, int sizeofmap ,int player_type)
{
    int j,i;
    int *result;
    result = (int*)malloc(sizeof(int)*2);
    j = 0;

    while(j<sizeofmap)
    {
        i = 0;
        while(i<sizeofmap)
        {
            //printf("%d",map[j][i]->maj);
            if (map[j][i]->maj == player_type)
            {
                result[0]=j;
                result[1]=i;
                return result;
            }
            i++;
        }
        j++;
    }
    return 0,0;
}

int     *to_find_in_case(t_map_type *map_type, int sizeofmap ,int player_type)
{
    int j,i;
    int *result;
    result = (int*)malloc(sizeof(int)*2);
    j = 0;

    while(j<sizeofmap)
    {
        i = 0;
        while(i<sizeofmap)
        {
            if (map_type->design[j][i].maj == player_type)
            {
                result[0]=j;
                result[1]=i;
                return result;
            }
            i++;
        }
        j++;
    }
    return 0,0;
}



