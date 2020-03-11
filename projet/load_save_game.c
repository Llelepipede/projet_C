//Renvoi true si fichier bien chargé, sinon false
/*int load(perso* joueur)
{
    FILE* inFile;
    inFile = fopen("data.txt", "r");
    if (inFile == NULL)
    {
        printf("Erreur de chargement de la sauvegarde.\n");
        return 0;
    }
    fgets(joueur->name, 80, inFile);
    if (joueur->name[strlen(joueur->name)-1] == '\n')
        joueur->name[strlen(joueur->name)-1] = '\0';

    fscanf(inFile, "%d/%d\n", &(joueur->hp), &(joueur->hp_max));
    fscanf(inFile, "%d %d\n", &(joueur->xp_not_lvl_up), &(joueur->lvl));

    fclose(inFile);

    printf("%s's Sauvegarde correctement chargée!\n", joueur->name);
    printf("\nTe revoila !, %s!\n", joueur->name);
    return 1;
}

//Sauvegarde les données joueur dans file
void save(perso* joueur)
{
    FILE* saveFile;
    saveFile = fopen("data.txt", "w");
    fprintf(saveFile, "%s\n", joueur.name);
    fprintf(saveFile, "%d/%d\n", joueur->hp, joueur->hp_max);
    fprintf(saveFile, "%d %d\n", joueur->xp_not_lvl_up, joueur.lvl);

    fclose(saveFile);

    printf("Reviens vite !\n");
}
*/
