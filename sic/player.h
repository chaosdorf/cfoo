#ifndef _PLAYER_
#define _PLAYER_

struct player {
	char *name;
	unsigned int level;		// actual level
	unsigned int sp;		// skillpoints to set
	unsigned int gold;
	unsigned int hpLeft;	// health points left
	int lastAction;			// last action
	
	/* values that can be increased with skill points */
	unsigned int hp; // max health points
	unsigned int ap; // attack points
	unsigned int dp; // defense points
};
// access with: struct player human;

/*
typedef struct {

} player;

now without "struct accessible
player human;
*/

void initPlayer( struct player* p );
void damagePlayer( struct player* p, unsigned int damage );
int isPlayerDead( struct player* p );

#endif
