#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>

int auth(char *s, int a2)
{
	int i;
	int nb;
	int len;

	s[strcspn(s, "\n")] = 0;
	len = strnlen(s, 32);
	if (len <= 5)
		return 1;
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
	{
		puts("\x1B[32m.---------------------------.");
		puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
		puts("\x1B[32m'---------------------------'");
		return 1;
	}
	else
	{
		nb = (s[3] ^ 4919) + 6221293;
		for ( i = 0; i < len; ++i )
		{
			if ( s[i] <= 31 )
				return 1;
			nb += (nb ^ (unsigned int)s[i]) % 1337;
		}
		return a2 != nb;
	}
}
// 80485D0: using guessed type int __cdecl strnlen(_DWORD, _DWORD);

//----- (08048879) --------------------------------------------------------
int main(int argc, const char **argv)
{
	int nb;
	char s[28];
	unsigned int v6;

	// Setup stack canary
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(s, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &nb);
	if (auth(s, nb))
		return 1;
	puts("Authenticated!");
	system("/bin/sh");
	return 0;
}
