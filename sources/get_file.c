/*
** EPITECH PROJECT, 2018
** get_file.c
** File description:
** get_file
*/

#include "parser.h"

int get_file(char *arg, file_t *file, char *str)
{
	FILE *sbml = fopen(arg, "r");
	file->nb = 0;

	if (sbml == NULL)
		exit(84);
	fseek(sbml, 0, SEEK_END);
	int size = ftell(sbml);
	if (size == 0)
		exit(84);
	file->string = malloc(sizeof(char) * size + 1);
	rewind(sbml);
	for (size_t i = 0; i < size + 1; i++)
		file->string[i] = 0;
	if (sbml != NULL) {
		while ((fgets(file->string, size, sbml) != NULL) &&
			(file->nb != 1))
			check_string(file->string, file, str);
		fclose(sbml);
	}
	free(file->string);
	return (0);
}

int count_att(char **array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}

static int compare(const void *p1, const void *p2)
{
	return strcmp(* (char * const *) p1, * (char * const *) p2);
}

char **sort(char **array)
{
	int j;

	qsort(array, count_att(array), sizeof(char *), compare);

	return (array);
}

int check_string(char *str, file_t *file, char *attribut)
{
	int i = 0;
	int a = 1;
	int x = 0;
	char **tab = my_str_to_word_array_synthesis(file->string, file);
	file->new_tab = malloc(sizeof(char *) * 100);

	if (strcmp(tab[0], attribut) == 0 && tab[1] != NULL) {
		puts(tab[0]);
		while (tab[a] && tab[a + 1]) {
			if (tab[a + 1][0] == '"') {
				file->new_tab[i] = tab[a];
				i++;
			}
			a++;
		}
		file->new_tab[i] = NULL;
		print_array(sort(file->new_tab));
		file->nb = 1;
	} else
		return (0);
	free(tab);
}
