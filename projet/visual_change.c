#include <stdio.h>
#include <stdlib.h>

int     ask_space()
{
    int     choice;

    printf("\t>");
    scanf("%d",&choice);

    return choice;
}

void    respond(char *sentence)
{
    printf("\t\t->%s",sentence);
}
