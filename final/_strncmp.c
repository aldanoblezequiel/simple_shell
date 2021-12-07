#include "main.h"

/**
*_strncmp - Compares strings up to a certain number of bytes
*@s1: String 1
*@s2: String 2
*@i: Top number of bytes to be compare
*Return: 0
*/

int _strncmp(char *s1, char *s2, unsigned int i)
{
	int n = 0;
	unsigned int t = 0;

	while (s1[t] == s2[t] && s1[t] != '\0' && s2[t] != '\0' && t < i)
		t++;
	if (s1[t] != s2[t])
		n = s1[t] - s2[t];
	return (n);
}
