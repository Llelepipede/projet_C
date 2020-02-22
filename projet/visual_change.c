#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

void     ask_space(char *choice)
{
    printf("\t>");
    scanf("%s",choice);
}

void    back_to_menu(int time)
{
    printf("Back to menu");
    while(time)
    {
        printf(" .");
        Sleep(1000);
        time--;
    }
    system("cls");
    menu();
}

void    respond(char *sentence)
{

    color(4,0);
    printf("\t\t->%s",sentence);
    color(3,0);

}

/*0:noir|1:bleu fonce|2:vert|3:Bleu Vert|4:rouge|5:rose|6:jaune kaki|7:gris blanc|8:gris fonce|9:bleu electrique*/
void    color(int text,int font)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,font*16+text);
}
