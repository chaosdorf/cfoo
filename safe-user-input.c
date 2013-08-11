// Read an aribritary amount of input from stdin, in a safe manner.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 100

int main(int argc, char *argv[]) {
	char *buf = NULL;
	size_t n_read = 0;
	size_t n_allocated = 0;

	while (1) {
		char *end;

		n_allocated += CHUNK_SIZE;
		buf = realloc(buf, n_allocated);
		end = &buf[n_read];

		if (!fgets(end, n_allocated - n_read, stdin))
			break;

		if (strchr(end, '\n'))
			break;

		n_read += strlen(end);
	}

	printf("You entered: %s\n", buf);
	free(buf);

	return 0;
}
