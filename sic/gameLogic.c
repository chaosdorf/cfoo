#include <stdio.h>
#include "gameLogic.h"
#include "player.h"

void calcActions( struct player* human, struct player* ai ) {
	//printf("human->lastAction:%i\n", human->lastAction);
	act(human, ai);
	act(ai, human);
}

void act( struct player* activePlayer, struct player* passivePlayer ) {
	switch( activePlayer->lastAction ) {
		case 1:
			damagePlayer( passivePlayer, activePlayer->ap );
			break;
		case 2:
			healPlayer( activePlayer, 1 );
			break;
		default:
			// just sit there
			printf("WARNING: '%s' IS JUST SITTING AROUND (action: %i)\n", activePlayer->name, activePlayer->lastAction);
			break;
	}
}
