#ifndef _GAMELOGIC_
#define _GAMELOGIC_

#include "player.h"

void calcActions( struct player* human, struct player* ai );
void act( struct player* aPlayer, struct player* pPlayer );

#endif