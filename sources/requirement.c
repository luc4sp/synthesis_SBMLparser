/*
** EPITECH PROJECT, 2018
** requirement.c
** File description:
** requirement
*/

#include "parser.h"

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
		if (str[y] == '/' || str[y] == ' ' || str[y] == '>' ||
			str[y] == '=' || str[y] == '<' || str[y] == '\t')
			i++;
	return (i + 1);
}

char *clean(char const *str, int i, char *tmp)
{
	int a = 0;

	for (; i <= strlen(str); a++ ) {
		if (str[i] == '/' || str[i] == ' ' || str[i] == '>' ||
			str[i] == '=' || str[i] == '<' || str[i] == '\t') {
			if (str[i] == '\0') {
				tmp[a] = '\0';
				return (tmp);
			}
			while (str[i] && str[i] == ' ' || str[i] == '>' ||
				str[i] == '=' || str[i] == '<' || str[i] == '/'
				|| str[i] == '\t')
				i++;
			tmp[a] = ' ';
		} else {
			tmp[a] = str[i];
			i = i + 1;
		}
	}
	return (tmp);
}

char *clean_string(char const *str)
{
	int i = 0;
	char *tmp;

	if (str == NULL) {
		return (NULL);
	}
	tmp = malloc(sizeof(char) * strlen(str));
	if (str[i] == ' ' || str[i] == '>' || str[i] == '=' ||
		str[i] == '<' || str[i] == '/' || str[i] == '\t') {
		while (str[i] == ' ' || str[i] == '>' || str[i] == '=' ||
			str[i] == '<' || str[i] == '/' || str[i] == '\t')
			i++;
	}
	clean(str, i, tmp);
	return (tmp);
}

char **my_str_to_word_array_synthesis(char const *str, file_t *file)
{
	int nb = char_counter(file->string);
	char **map = malloc((sizeof(char *) * nb) + 1);
	int i = 0;
	int y = 0;
	int z = 0;

	str = clean_string(file->string);
	map[0] = m_calloc(strlen(str));
	while (str[i]) {
		if (str[i] == '/' || str[i] == ' ' || str[i] == '\t' ||
			str[i] == '>' || str[i] == '=' || str[i] == '<') {
			y++;
			map[y] = m_calloc(strlen(str));
			z = 0;
		} else {
			map[y][z] = str[i];
			z++;
		}
		i++;
	}
	map[y + 1] = NULL;
	return (map);
}
