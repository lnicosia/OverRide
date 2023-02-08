#include <stdio.h>
#include <string.h>

int main()
{
	char c[32];
	c[0] = 'C';
	c[1] = 'o';
	c[2] = 'n';
	c[3] = 'g';
	c[4] = 'r';
	c[5] = 'a';
	c[6] = 't';
	c[7] = 'u';
	c[8] = 'l';
	c[9] = 'a';
	c[10] = 't';
	c[11] = 'i';
	c[12] = 'o';
	c[13] = 'n';
	c[14] = 's';
	c[15] = 0;
	for (int i = 0; i < 15; i++)
	{
		c[i] ^= c[i];
		printf("%c", c[i]);
	}
	printf("\nRes = |%s|\n", c);
	if (strcmp(c, "Congratulations"))
		printf("Error\n");
	else
		printf("Equal\n");
	return 0;
}
