/*
** EPITECH PROJECT, 2018
** split.c
** File description:
** split
*/

#include "parser.h"

char *my_calloc(int lenght)
{
	int i = 0;
	char *res = malloc(lenght + 1);

	while (i < lenght) {
		res[i] = 0;
		i++;
	}
	return (res);
}

int counter(char *str, char c, char second, char third)
{
	int i = 0;

	for (int y = 0; str[y]; y++)
		if (str[y] == c || str[y] == second || str[y] == third)
			i++;
	return (i + 1);
}

char **str_to_wordTab(char *str, char s_char, char second, char third)
{
	int nb = counter(str, s_char, second, third);
	char **map = malloc((sizeof(char *) * nb) + 1);
	int i = 0;
	int y = 0;
	int z = 0;

	map[0] = my_calloc(strlen(str));
	while (str[i]) {
		if (str[i] == s_char || str[i] == second || str[i] == third) {
			y++;
			map[y] = my_calloc(strlen(str));
			z = 0;
		} else {
			map[y][z] = str[i];
			z++;
		}
		i++;
	}
	map[y] = NULL;
	return (map);
}
