#include <stdio.h>
#include <stdlib.h>

void Reverse(char *str)
{
	char *begin = str;
	char *end = str;
	
	while (*end)
		++end;

	--end;

	while (begin < end)
	{
		char t = *begin;
		*begin++ = *end;
		*end-- = t;
	}
}

int main()
{
	char str[100];
	gets_s(str);
	Reverse(str);
	puts(str);
}