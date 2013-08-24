#ifndef _GAMELOGIC_
#define _GAMELOGIC_

#include "player.h"

void calcActions( struct player* human, struct player* ai );
void act( struct player* activePlayer, struct player* passivePlayer );

#endif
