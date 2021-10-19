#include <stdio.h>
#include <malloc.h>
#include "pendu.h"
#include "dico.h"

int main(int argc, char *argv[]) {

    FILE* fichier = NULL;
    int nbrDeCoups = 10;
    char essaiChar;
    int resultat;
    int gagne;
    char motSecret[50]= {0} ;
    char motTrouve[50] = {0};
    ouvertureFichier(&fichier);
    choixMot(motSecret, &fichier);
    cacheMot(motSecret, motTrouve);

    while(nbrDeCoups != 0)
    {
        presente(nbrDeCoups, motTrouve);
        essaiChar = lireCaractere();
        resultat = compare(essaiChar, motSecret);
        if(!resultat)
        {
            change(essaiChar, motSecret, motTrouve);
        }
        else
        {
            nbrDeCoups--;
        }
        gagne = verif(motTrouve);
        if(!gagne)
        {
            printf("Bravo, vous avez gagne\nLe mot etait : ");
            printf("%s", motSecret);
            nbrDeCoups = 0;
        }
    }
    if(gagne)
    {
        printf("Perdu, le mot etait :");
        printf("%s", motSecret);
    }


    fclose(fichier);
    system("pause");

    return 0;
}

