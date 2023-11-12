#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 20

extern char **environ;

void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _strcmp(char *str1, char *str2);
size_t _strlen(const char *str);
void executeCommand(char *command, char *path[]);
char *readInput();
void handleCommands(char *path[]);
int main(void);

#endif