#include <stdio.h>
#include "basicplayer.h"

void printPlayerStats(BasicPlayer* player, char** statNames);

int main(void)
{
    BasicPlayer player;
    char* statNames[6] = {"AB", "Walks", "Singles", "Doubles", "Triples", "Homeruns"};

    while (GetNextPlayer(&player))
        printPlayerStats(&player, statNames);
}

void printPlayerStats(BasicPlayer* player, char** statNames)
{
    printf("ID: %d, Name: %s\n\t", player->id, player->name);

    for (int i = 0; i < 6; ++i)
        printf("%s: %d, ", statNames[i], GetStat(player->id, i));

    printf("\n");  
}

