#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 20

extern char *environ;

void _strcpy(chardest, const char src);
void _strcat(chardest, const char src);
int _strcmp(charstr1, char str2);
size_t _strlen(const charstr);
void executeCommand(char command, charpath[]);
char readInput();
void handleCommands(charpath[]);
int main(void);

#endif