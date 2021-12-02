#include "main.h"

/**
**_strcat - Function that concatenates two strings
*@dest: The string in wich the src string is going to be appended
*@src: The string that is going to be appended to the dest string
*Return: The resulting concatenated string
*/

char *_strcat(char *dest, char *src)
{
	int n, s = 0;

	while (dest[s])
		s++;
	for (n = 0; src[n] != '\0'; n++)
	{
		dest[s] = (src[n]);
		s++;
	}
	return (dest);
}
