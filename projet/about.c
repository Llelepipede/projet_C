#include <stdio.h>
#include <stdlib.h>

void    about()
{
    char *pseudo = "Corrona";
    printf("\nCe jeu est un projet de groupe realise par 4 etudiants en premiere annee.\nIl a servit d'evaluation sur le chapitre \"programmation en C\"\n\n\n\t\tBon jeu <3\n\n\tles realisateurs: Llele, GuiGui, Kobu et Mishmish\n\n",pseudo);
    respond("retour au menu\n");
    menu();
}
