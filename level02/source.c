#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, const char **argv, const char **envp)
{
	char s2[96];
	int v5;
	char ptr[48];
	char s[96];
	int v8;
	int v9;
	FILE *stream;

	memset(s, 0, sizeof(s));
	v8 = 0;
	memset(ptr, 0, 41);
	memset(s2, 0, sizeof(s2));
	v5 = 0;
	stream = 0LL;
	v9 = 0;
	stream = fopen("/home/users/level03/.pass", "r");
	if (!stream)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	v9 = fread(ptr, 1, 41, stream);
	ptr[strcspn(ptr, "\n")] = 0;
	if (v9 != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(stream);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(s, 100, stdin);
	s[strcspn(s, "\n")] = 0;
	printf("--[ Password: ");
	fgets(s2, 100, stdin);
	s2[strcspn(s2, "\n")] = 0;
	puts("*****************************************");
	if (strncmp(ptr, s2, 41))
	{
		printf(s);
		puts(" does not have access!");
		exit(1);
	}
	printf("Greetings, %s!\n", s);
	system("/bin/sh");
	return 0;
}
