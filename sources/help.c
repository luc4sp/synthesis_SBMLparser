/*
** EPITECH PROJECT, 2018
** help.c
** File description:
** help
*/

#include "parser.h"

void help(void)
{
	puts("USAGE");
	puts("     ./SBMLparser SBMLfile [-i ID [-e]] [-json]");
	my_putchar('\n');
	puts("DESCRIPTION");
	puts("      SBMLfile   SBML file");
	puts("      -i ID      id of the compartment, reaction"
		"or product to be extracted");
	puts("                 (ignored if uncorrect)");
	puts("      -e         print the equation if a reaction"
		"ID is given as argument");
	puts("                 (ignored otherwise)");
	puts("      -json      transform the file into a JSON file");
}
