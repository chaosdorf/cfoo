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
	
	p->lastAction = 0;
}

int isPlayerDead( struct player* p ) {
	if (p->hpLeft == 0) {
		return 1;
	} else {
		return 0;
	}
}

void damagePlayer( struct player* p, unsigned int damage ) {
	//printf("damage:%i - hpleft:%i\n", damage, p->hpLeft);
	if (p->hpLeft >= damage) {
		p->hpLeft -= damage;
	} else {
		p->hpLeft = 0;
	}
	//printf("damage:%i - hpleft:%i\n", damage, p->hpLeft);
}

void healPlayer( struct player* p, unsigned int healing ) {
	p->hpLeft += p->dp * healing;
	
	if (p->hpLeft > p->hp) {
		p->hpLeft = p->hp;
	}	
}

/*
 max health points: 0
 attack points:     1
 defense points:    2
*/
void assignSkillPoint( struct player* p, unsigned int forWhat ) {
	if (p->sp > 0) {
		p->sp -= 1;
		switch( forWhat ) {
			case 1:
				p->hp += 1;
				break;
			case 2:
				p->ap += 1;
				break;
			case 3:
				p->dp += 1;
				break;
		}
	}
}
