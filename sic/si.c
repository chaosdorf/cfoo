#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "gameLogic.h"
#include "ai.h"

//global static foo
//char *aiNames[] = {"The Hamster", "CatMan", "see sharp"};
char humanName[255];

void getHumanName(struct player* p) {
	printf("enter your name: ");
	scanf("%255s", humanName);
	p->name = humanName;
}

void getHumanInteraction(struct player* human, struct player* ai, int actionType) {
	// do ALL user stuff here
	// inclusive drawing?
	// TODO: put in include file
	int input = 0;
	switch( actionType ) {
		case 1: // fight
			printf("\033[2J\033[1;1H");
			printf("name:%s\n", human->name);
			printf("hp:%i\n", human->hpLeft);
			printf("name:%s\n", ai->name);
			printf("last action:%i\n", ai->lastAction);
			printf("hp:%i\n", ai->hpLeft);
				
			//char buf[255];
			
			scanf("%i", &input);
			human->lastAction = input;
			
			break;
		case 2: // monsters death
			printf("you have beaten:%s\n", ai->name);
			scanf("%i", &input);
			human->lastAction = input;
			break;
		default:
			// main menu?
			break;
	}
}

int main(int argc, char *args[]) {
	// a game needs a banner, so draw one
	FILE *myfile;
	char buf[255];
	myfile=fopen("banner.txt", "r");
	while(!feof(myfile)){
		memset(buf, 0, 80);
		fread(buf, sizeof(char), sizeof(char)*79, myfile);
		printf("%s", buf);
	}
	fclose(myfile);

	// init
	srand(time(NULL));  // TODO: alternative for ATARI!
	// TODO: read a randomly generated name list into: aiNames
	
	struct player human;
	struct player ai;

	initPlayer( &human );
	//initPlayer( &ai );
	getHumanName( &human );
	//getAiName( &ai );
	
	// init AI, "simulate" its death
	getAiInteraction(&ai, &human, 2);

	int keepPlaying = 1;
	while (keepPlaying) {	
		getHumanInteraction( &human, &ai, 1 );
		getAiInteraction( &ai, &human, 1 );
		
		execActions( &human, &ai );
				
		if (isPlayerDead(&human)) {
			keepPlaying = 0;
		} else if(isPlayerDead(&ai)) {
			getHumanInteraction(&human, &ai, 2);
			getAiInteraction(&ai, &human, 2);
		}
	}

	// TODO: GAME OVER screen
	// maybe with stats?
	printf("    GAME OVER    \n");
	
	return 0;
}
