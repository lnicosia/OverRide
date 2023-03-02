#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool main(void)

{
	int buf;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &buf);
	if (buf != 5276) {
		puts("\nInvalid Password!");
	}
	else {
		puts("\nAuthenticated!");
		system("/bin/sh");
	}
	return buf != 5276;
}

