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
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strpbrk(char *str, const char *delimiter);
void executeCommand(char *command, char *path[]);
void excute_cmd(char *path[], char *args[]);
char *readInput();
void handle_env(char *args[]);
void handle_setenv(char *args[], int count_arg);
void handle_unsetenv(char *args[], int count_arg);
void handleCommands(char *path[]);
char *_getenv(const char *target_key);
char *_strtok(char *str, const char *delimiter);
int main(void);

#endif
