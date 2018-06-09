/*
** EPITECH PROJECT, 2018
** clean_str.c
** File description:
** clean_str
*/

#include "parser.h"

char *clean_str(char const *str, int i, char *tmp)
{
	int a = 0;

	for (; i <= strlen(str); a = a + 1) {
		if (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
		(str[i] > 90 && str[i] < 97) || str[i] > 122) {
			while (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
			(str[i] > 90 && str[i] < 97) || str[i] > 122)
				i++;
			if (str[i] == '\0') {
				tmp[a] = '\0';
				return (tmp);
			}
			tmp[a] = ' ';
		} else {
			tmp[a] = str[i];
			i = i + 1;
		}
	}
	return (tmp);
}

char *rostr(char const *str)
{
	int i = 0;
	char *tmp;

	if (str == NULL) {
		return (NULL);
	}
	tmp = malloc(sizeof(char) * strlen(str));
	if (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
	(str[i] > 90 && str[i] < 97) || str[i] > 122) {
		while (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
		(str[i] > 90 && str[i] < 97) || str[i] > 122)
			i++;
	}
	clean_str(str, i, tmp);
	return (tmp);
}
