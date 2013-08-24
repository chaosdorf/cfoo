#include "gameLogic.h"
#include "player.h"

void calcActions( struct player* human, struct player* ai ) {
	//printf("human->lastAction:%i\n", human->lastAction);
	if (human->lastAction == 1) {
		damagePlayer( ai, human->ap );
	}
	
	if (ai->lastAction == 1) {
		damagePlayer( human, ai->ap );
	}
}
