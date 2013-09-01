#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "player.h"

char *aiNames[] = {"The Hamster", "CatMan", "see sharp"};

void getAiName(struct player* p) {
	int r = rand() % 3;//(sizeof(*aiNames)-1);
	//printf("random:%i\n", r);
	//printf("sizeof:%i\n", sizeof(aiNames));
	p->name = aiNames[r];
}

void getAiInteraction(struct player* ai, struct player* human, int actionType) {
	// TODO: create an AI!
	int input = 0;
	switch( actionType ) {
		case 1: // fight
			input = (rand() % 2) + 1;
			printf("action: %i\n", input);
			ai->lastAction = input;
			break;
		case 2: // monsters death
			getAiName(ai);
			initPlayer(ai);
			// TODO: another init system for evolving AI based on human state
			break;
		default:
			break;
	}
}
