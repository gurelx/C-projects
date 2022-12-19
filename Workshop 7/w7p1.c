/*
*****************************************************************************
						  Workshop - #7 (P1)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_PATH_LEN 70
#define MIN_PATH_LEN 10
#define PATH_MOD 5
#define MAX_LIVES 10
#define MIN_LIVES 1

struct PlayerInfo
{
	int lives;
	char nickName;
	int treasureCounter;
	int history[MAX_PATH_LEN];
};

struct GameInfo
{
	int moves;
	int pathLength;
	int bombs[MAX_PATH_LEN];
	int treasures[MAX_PATH_LEN];
};

void Placement(int a, int b[])
{
	int i;

	for (i = 0; i < a; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &b[i], &b[i + 1], &b[i + 2], &b[i + 3], &b[i + 4]);
	}
}

int main(void)
{
	struct PlayerInfo player = { 0, 'c', 0 , {0} };
	struct GameInfo game = { 0 };
	int i;

	printf("================================\n"
		"         Treasure Hunt!\n"
		"================================\n\n");

	printf("PLAYER Configuration\n"
		"--------------------\n"
		"Enter a single character to represent the player: ");
	scanf(" %c", &player.nickName);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.lives);

		if (player.lives > MAX_LIVES || player.lives < MIN_LIVES)
		{
			printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
		}

	} while (player.lives > MAX_LIVES || player.lives < MIN_LIVES);

	printf("Player configuration set-up is complete\n\n");

	printf("GAME Configuration\n"
		"------------------\n");

	do
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", PATH_MOD, MIN_PATH_LEN, MAX_PATH_LEN);
		scanf("%d", &game.pathLength);

		if (game.pathLength > MAX_PATH_LEN || game.pathLength < MIN_PATH_LEN || game.pathLength % PATH_MOD != 0)
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_MOD, MIN_PATH_LEN, MAX_PATH_LEN);
		}

	} while (game.pathLength > MAX_PATH_LEN || game.pathLength < MIN_PATH_LEN || game.pathLength % PATH_MOD != 0);

	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.moves);

		if (game.moves < player.lives || game.moves > (int)((game.pathLength * 75) / 100))// It automatically truncates to the smallest whole number but I put an (int) just in case.
		{
			printf("    Value must be between %d and %d\n", player.lives, (int)((game.pathLength * 75) / 100));
		}

	} while (game.moves < player.lives || game.moves > (int)((game.pathLength * 75) / 100));

	printf("\n");

	printf("BOMB Placement\n"
		   "--------------\n"
		   "Enter the bomb positions in sets of %d where a value\n"
		   "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
		   "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", PATH_MOD, game.pathLength);

	Placement(game.pathLength, game.bombs);

	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n"
		"------------------\n"
		"Enter the treasure placements in sets of %d where a value\n"
		"of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
		"(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", PATH_MOD, game.pathLength);

	Placement(game.pathLength, game.treasures);

	printf("TREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");

	printf("------------------------------------\n"
		   "TREASURE HUNT Configuration Settings\n"
		   "------------------------------------\n"
		   "Player:\n"
		   "   Symbol     : %c\n", player.nickName);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n"
		   "   History    : [ready for gameplay]\n\n");

	printf("Game:\n"
		   "   Path Length: %d\n", game.pathLength);
	printf("   Bombs      : ");

	for (i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.bombs[i]);
	}

	printf("\n");
	printf("   Treasure   : ");

	for (i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.treasures[i]);
	}

	printf("\n\n");
	printf("====================================\n"
	   	   "~ Get ready to play TREASURE HUNT! ~\n"
		   "====================================\n");

	return 0;
}
