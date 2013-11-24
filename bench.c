#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <sys/time.h> 

int innerLoops =  1000000000;

struct timeval startTime;

void startTimer() {
	gettimeofday(&startTime, NULL);
}

void stopTimer() {
	struct timeval stopTime;
	gettimeofday(&stopTime, NULL);
	double total;
	
	total = (stopTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
	total += (stopTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms
	
	printf("%f\n", total);
}

void testFor() {
	int dummyVar = 0;
	int i;
	for (i = 0;i < innerLoops; i++) {
		dummyVar = !dummyVar;
	}
}

int main(int argc, char *args[]) {
	int i;
	for (i = 0; i<5; i++) {
		startTimer();
		testFor();
		stopTimer();
	}
}

