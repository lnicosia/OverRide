#include <string.h>
#include <stdio.h>

char *a_user_name;

int		verify_user_pass()
{
	return memcmp(a_user_name, "admin", 5);
}

int		verify_user_name()
{
	puts("verifying username....\n");
	return memcmp(a_user_name, "dat_wil", 7);
}

int		main(void)
{
	char buf[64];
	int ret;

	memset(buf, 0, 64);
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	ret = verify_user_name();
	if (ret == 0)
	{
		puts("Enter Password: ");
		fgets(buf, 100, stdin);
		ret = verify_user_pass(buf);
		puts("nope, incorrect password...\n");
	}
	else {
		puts("nope, incorrect username...\n");
		ret = 1;
	}
	return ret;
}

