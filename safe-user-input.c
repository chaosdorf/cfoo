// Read an aribritary amount of input from stdin, in a safe and portable manner.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *buf = NULL;
	size_t len = 0;

#if defined(_GNU_SOURCE) || _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700
	getline(&buf, &len, stdin);
#else
	int c;

	while ((c = getchar()) != EOF) {
		buf = realloc(buf, ++len);
		buf[len - 1] = (char) c;

		if (c == '\n')
			break;
	}
#endif

	printf("You entered: %.*s", len, buf);
	free(buf);

	return 0;
}
