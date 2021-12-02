#include "main.h"

/**
*_strcmp - Compares two or more strings
*@s1: String 1
*@s2: String 2
*Return: 0
*/

int _strcmp(char *s1, char *s2)
{
	int n = 0, t = 0;

	while (s1[n] == s2[n] && s1[n] != '\0' && s2[n] != '\0')
		n++;
	if (s1[n] != s2[n])
		t = s1[n] - s2[n];
	return (t);
}
