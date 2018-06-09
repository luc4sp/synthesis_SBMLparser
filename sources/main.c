/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "parser.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

void print_array(char **array)
{
	int i = 0;

	while (i < count_att(array)) {
		printf("--->%s\n", array[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	file_t *file = malloc(sizeof(file_t));

	if (argc < 2 || argc > 6)
		return (84);
	if (strcmp(argv[1], "-h") == 0)
		help();
	if (argc > 2 && strcmp(argv[2], "-i") != 0 && strcmp(argv[2], "-e") != 0 &&
	    strcmp(argv[2], "-json") != 0) {
		return (84);
	} else {
		get_file(argv[1], file, "compartment");
		get_file(argv[1], file, "model");
		get_file(argv[1], file, "reaction");
		get_file(argv[1], file, "sbml");
		get_file(argv[1], file, "species");
		get_file(argv[1], file, "speciesReference");
		return (0);
	}
	free(file->new_tab);
}
