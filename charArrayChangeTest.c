#include <stdio.h>
#include <stdlib.h>

void test(char testAr[]) {
	testAr[2] = 'a';
}

int main(int argc, char *args[]) {
	printf("%s\n", "start");
	//char testAr[] = {'g', 'g', 'g', '\0'};
	char testAr[] = {"gggg"};
	printf("%s\n", testAr);
	test(testAr);
	printf("%s\n", testAr);
	return 0;
}
