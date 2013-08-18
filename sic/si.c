#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "player.h"

//global static foo
char *aiNames[] = {"The Hamster", "CatMan", "see sharp"};
char humanName[255];

void humanInteraction(struct player* p) {
	
}

void aiInteraction(struct player* p) {
	
}


void humanGetName(struct player* p) {
	printf("enter your name: ");
	scanf("%255s", humanName);
	p->name = humanName;
}

void aiGetName(struct player* p) {
	int r = rand() % 3;//(sizeof(*aiNames)-1);
	//printf("random:%i\n", r);
	//printf("sizeof:%i\n", sizeof(aiNames));
	p->name = aiNames[r];
}

int main(int argc, char *args[]) {
	// init
	srand(time(NULL));  // TODO: alternative for ATARI!

	struct player human;
	struct player ai;
	initPlayer( &human );
	initPlayer( &ai );
	

	humanGetName( &human );
	aiGetName( &ai );
	
	
	int keepPlaying = 0;
	while (keepPlaying) {
		
	}
	
	printf("hp:%i\n", human.hp);
	printf("name:%s\n", human.name);
	printf("hp:%i\n", ai.hp);
	printf("name:%s\n", ai.name);

	return 0;
}
