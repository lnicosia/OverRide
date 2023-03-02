#include <string.h>
#include <stdio.h>

int clear_stdin()
{
	int result;

	do
		result = getchar();
	while ( (char)result != 10 && (char)result != 0xFF );
	return result;
}

int get_unum()
{
	int nb;

	nb = 0;
	fflush(stdout);
	scanf("%u", &nb);
	clear_stdin();
	return nb;
}

int store_number(int buff)
{
	unsigned int value;
	unsigned int index;

	printf(" Number: ");
	value = get_unum();
	printf(" Index: ");
	index = get_unum();
	if ( index % 3 == 0 || value >> 24 == 0xb7 )
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return 1;
	}
	else
	{
		*(int *)(buff + 4 * index) = value;
		return 0;
	}
}

int read_number(int a1)
{
	int unum;

	printf(" Index: ");
	unum = get_unum();
	printf(" Number at data[%u] is %u\n", unum, *(int *)(a1 + 4 * unum));
	return 0;
}

int main(int argc, const char **argv, const char **envp)
{
	char v6[400];
	int number;
	char s[4];
	int v9;
	int v10;
	int v11;
	int v12;
	unsigned int v13;

	// Setup stack canary
	number = 0;
	s[0] = 0;
	v9 = 0;
	v10 = 0;
	v11 = 0;
	v12 = 0;
	memset(v6, 0, sizeof(v6));
	while ( *argv )
	{
		memset((void *)*argv, 0, strlen(*argv));
		++argv;
	}
	while ( *envp )
	{
		memset((void *)*envp, 0, strlen(*envp));
		++envp;
	}
	puts(
			"----------------------------------------------------\n"
			"  Welcome to wil's crappy number storage service!   \n"
			"----------------------------------------------------\n"
			" Commands:                                          \n"
			"    store - store a number into the data storage    \n"
			"    read  - read a number from the data storage     \n"
			"    quit  - exit the program                        \n"
			"----------------------------------------------------\n"
			"   wil has reserved some storage :>                 \n"
			"----------------------------------------------------\n");
	while (1)
	{
		printf("Input command: ");
		number = 1;
		fgets(s, 20, stdin);
		s[strlen(s) - 1] = 0;
		if (!memcmp(s, "store", 5))
		{
			number = store_number((int)v6);
			goto LABEL_13;
		}
		if (!memcmp(s, "read", 4))
		{
			number = read_number((int)v6);
			goto LABEL_13;
		}
		if (!memcmp(s, "quit", 4))
			return 0;
LABEL_13:
		if (number)
			printf(" Failed to do %s command\n", s);
		else
			printf(" Completed %s command successfully\n", s);
		*(int *)s = 0;
		v9 = 0;
		v10 = 0;
		v11 = 0;
		v12 = 0;
	}
}
