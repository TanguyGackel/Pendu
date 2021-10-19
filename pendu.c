#include <stdio.h>
#include <ctype.h>
#include "pendu.h"

char lireCaractere()
{
    char caractere;
    caractere = getchar();
    caractere = toupper(caractere);

    while(getchar() != '\n');

    return caractere;
}
void presente(int nbrDeCoups, char motTrouve[])
{
    printf("Il vous reste %d coups\n", nbrDeCoups);
    printf("Quelle est le mot secret ?");
    for(int i = 0; i < size(motTrouve); i++)
    {
        printf("%c", motTrouve[i]);
    }
    printf("\n Proposer une lettre :");
}
int size(char mot[])
{
    int i = 0;
    int a = 0;
    while(mot[i] != '\0')
    {
        if(mot[i] == '\n')
        {
            a++;
        }
        i++;
    }
    return i - a;
}
int compare(char lettre, char mot[])
{
    for(int i = 0; i < size(mot); i++)
    {
        if(mot[i] == lettre)
        {
            return 0;
        }
    }
    return 1;
}
void change(char lettre, char mot[], char motCache[])
{
    for(int i = 0; i < size(mot); i++)
    {
        if(mot[i] == lettre)
        {
            motCache[i] = lettre;
        }
    }
}
int verif(char mot[])
{
    for(int i = 0; i < size(mot); i++)
    {
        if(mot[i] == '*')
        {
            return 1;
        }
    }
    return 0;
}