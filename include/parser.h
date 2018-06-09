/*
** EPITECH PROJECT, 2018
** parser.h
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct file_s {
	char *string;
	int nb;
	char **new_tab;
} file_t;

void my_putchar(char c);
int my_putstr(char const *str);
void print_array(char **array);
char **str_to_wordTab(char *str, char s_char, char second, char third);
int get_file(char *arg, file_t *, char *str);
char *clean_str(char const *str, int i, char *tmp);
char *rostr(char const *str);
char **my_str_to_word_array_synthesis(char const *str, file_t *);
int check_string(char *string, file_t *, char *str);
void help();
int error_mngmt(char **array);
int count_att(char **array);

#endif
