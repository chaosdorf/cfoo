#include "player.h"
void initPlayer( struct player* p ) {
	// -> dereference the pointer for p and acccess directly the values
	
	p->level = 1;
	p->sp = 0;
	p->gold = 0;
	p->hpLeft = 99;
	
	p->hp = 99;
	p->ap = 10;
	p->dp = 8;
}
