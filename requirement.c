/*
** EPITECH PROJECT, 2018
** split.c
** File description:
** split
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
	int i = 0;

	while(str[i] != '\0') {
		i++;
	}
	return (i);
}

char *m_calloc(int lenght)
{
	int i = 0;
	char *res = malloc(lenght + 1);

	while (i < lenght) {
		res[i] = 0;
		i++;
	}
	return (res);
}

int char_counter(char const *str)
{
	int i = 0;

	for (int y = 0; str[y]; y++)
		if (str[y] < 48 || (str[y] > 57 && str[y] < 65) ||
		    (str[y] > 90 && str[y] < 97) || str[y] > 122)
			i++;
	return (i + 1);
}

char *clean_str(char const *str, int i, char *tmp)
{
	int a = 0;

	for (; i <= my_strlen(str); a = a + 1) {
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
	tmp = malloc(sizeof(char) * my_strlen(str));
	if (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
	    (str[i] > 90 && str[i] < 97) || str[i] > 122) {
		while (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
		       (str[i] > 90 && str[i] < 97) || str[i] > 122)
			i = i + 1;
	}
	clean_str(str, i, tmp);
	return (tmp);
}

char **my_str_to_word_array_synthesis(char const *str)
{
	int nb = char_counter(str);
	char **map = malloc((sizeof(char *) * nb) + 1);
	int i = 0;
	int y = 0;
	int z = 0;

	str = rostr(str);
	map[0] = m_calloc(my_strlen(str));
	while (str[i]) {
		if (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
		    (str[i] > 90 && str[i] < 97) || str[i] > 122) {
			y++;
			map[y] = m_calloc(my_strlen(str));
			z = 0;
		} else {
			map[y][z] = str[i];
			z++;
		}
		i++;
	}
	map[y] = NULL;
	return(map);
}
