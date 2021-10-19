#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dico.h"
#include "pendu.h"

void ouvertureFichier(FILE** fichier)
{
    *fichier = fopen("dico.txt", "r+");
    if(*fichier == NULL)
    {
        printf("Error : l'ouverture du fichier a echoue");
        exit(0);
    }
}
void choixMot(char motSecret[], FILE** fichier)
{
    time_t t;
    srand((unsigned) time(&t));
    int nbrDeMots = 0;
    while(fgets(motSecret, 50, *fichier) != NULL){
        nbrDeMots ++;
    }
    rewind(*fichier);
    int a = rand()%nbrDeMots;
    int i = 0;
    while(i <= a){
        fgets(motSecret, 50, *fichier);
        i++;
    }
}
void cacheMot(char motSecret[], char motTrouve[])
{
    for(int i = 0; i < size(motSecret); i++)
    {
        motTrouve[i] = '*';
    }
}