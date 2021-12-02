#include "main.h"

/**
 * main - a function that runs a custom made shell
 * @ac: argument count
 * @av: argumetn value
 * @env: enviroment variables
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;

	shell(env);

	return (0);
}
