
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;
#define MAX_INPUT_SIZE 1024

size_t _strlen(char *str);
size_t find_newline(char *str);
char **splite_command(char *input);
void execute(char **args);
void interactive_mode(void);
void non_interactive_mode(char *file_path);
void print_error(void);
void exit_status(char **args);
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);


#endif
