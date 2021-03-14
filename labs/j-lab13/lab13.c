/*****************************
* Name:      Evan Dobson
* Pawprint:  ejdwcf
* Course:    CS 1050
* Lab:       Lab 13
****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basicplayer.h"

typedef struct _AdvancedPlayer
{
    char name[256];
    float avg;
    float obp;
    float slug;

} AdvancedPlayer;

enum SortType
{
    INITIAL,
    AVERAGE,
    ONBASE,
    SLUGGING,
    SORT_TYPE_MAX
};

void registerPlayerStats(BasicPlayer* b_player, AdvancedPlayer* a_player);
void printPlayersStats(AdvancedPlayer* a_players, int num_players, enum SortType sort_type);
void sortPlayers(AdvancedPlayer* a_players, int num_players, enum SortType sort_type);
void swap(AdvancedPlayer* a_player1, AdvancedPlayer* a_player2);

int main(void)
{
    BasicPlayer b_player;
    AdvancedPlayer* a_players;
    int num_players;

    while(GetNextPlayer(&b_player))
        ++num_players;

    ResetToFirstPlayer();

    // Dynamically allocates the a_players array based on the number of players
    a_players = malloc(num_players * sizeof(AdvancedPlayer)); 
    if (a_players)
    {
        for (int i = 0; ; ++i)
        {
            if (GetNextPlayer(&b_player))
                registerPlayerStats(&b_player, &a_players[i]);
            else
                break;
        }

        for (int i = 0; i < SORT_TYPE_MAX; ++i)
        {
            sortPlayers(a_players, num_players, i);
            printPlayersStats(a_players, num_players, i);
        }

        free(a_players);

    } else
        printf("ERROR: Could not allocate the required memory for a_players\n");
}

void registerPlayerStats(BasicPlayer* b_player, AdvancedPlayer* a_player)
{
    float b_player_total_hits = GetStat(b_player->id, SINGLES) + GetStat(b_player->id, DOUBLES) + GetStat(b_player->id, TRIPLES) + GetStat(b_player->id, HOMERUNS);
    float b_player_total_bases = GetStat(b_player->id, SINGLES) + 2 * GetStat(b_player->id, DOUBLES) + 3 * GetStat(b_player->id, TRIPLES) + 4 * GetStat(b_player->id, HOMERUNS);

    strcpy(a_player->name, b_player->name);
    a_player->avg  = b_player_total_hits / GetStat(b_player->id, ATBATS);
    a_player->obp  = (b_player_total_hits + GetStat(b_player->id, WALKS)) / (GetStat(b_player->id, ATBATS) + GetStat(b_player->id, WALKS));
    a_player->slug = b_player_total_bases / GetStat(b_player->id, ATBATS);
}

void printPlayersStats(AdvancedPlayer* a_players, int num_players, enum SortType sort_type)
{
    switch(sort_type)
    {
        case INITIAL:
            printf("\n*** Initial order ***\n");
            break;

        case AVERAGE:
            printf("\n*** By Average ***\n");
            break;

        case ONBASE:
            printf("\n*** By OnBase Pct ***\n");
            break;

        case SLUGGING:
            printf("\n*** By Slugging Pct ***\n");
            break;

        default:
            break;
    }

    printf("%5s %5s %5s %-5s\n", "AVG", "OBP", "SLUG", "NAME");
    
    for (int i = 0; i < num_players; ++i)
        printf("%5.3f %5.3f %5.3f %s\n", a_players[i].avg, a_players[i].obp, a_players[i].slug, a_players[i].name);
}

void sortPlayers(AdvancedPlayer* a_players, int num_players, enum SortType sort_type)
{
    for (int i = 0; i < num_players - 1; ++i)
    {
        for (int j = 0; j < num_players - 1 - i; ++j)
        {
            if (sort_type == AVERAGE && a_players[j].avg < a_players[j + 1].avg)
                swap(&a_players[j], &a_players[j + 1]);

            else if (sort_type == ONBASE && a_players[j].obp < a_players[j + 1].obp)
                swap(&a_players[j], &a_players[j + 1]);
            
            else if (sort_type == SLUGGING && a_players[j].slug < a_players[j + 1].slug)
                swap(&a_players[j], &a_players[j + 1]);
        }
    }
}

void swap(AdvancedPlayer* a_player1, AdvancedPlayer* a_player2)
{
    AdvancedPlayer temp;

    temp = *a_player1;
    *a_player1 = *a_player2;
    *a_player2 = temp;
}
