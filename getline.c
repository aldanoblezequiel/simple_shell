#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *s;
	
	putchar('$');
	s = getline();
	while (s != '\n')
	{
		printf("%s\n", s);
	}
	return (0);
}
