#include <stdio.h>
#include <stdlib.h>



void    new_game()
{
    int     sizeofmap = 6;
    int     ***map = map_create(map,sizeofmap);



    show_map(map,sizeofmap);
}


