#ifndef MAIN_H
#define MAIN_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stddef.h>
#include<string.h>
#include<sys/wait.h>
#include <limits.h>

extern char **environ;


void _myshell(void);
void non_inter_md(char *token, int *status);
ssize_t read_input(char **line, size_t *size_line);
void exit_status(int my_status, char **single_command,
char **token, int *status);
void _exit_(int my_status, char **commands,
char *line, int *status);

void _execvep(char **commands, char **envp, int *status);
int _locate(char *command, char **full_path);
void wait_pid(int *status);
char *_getenv(const char *path);
int str_to_int(char *s);

char **split_cmd(char *str, char *delimiters);
ssize_t _getline(char **line, size_t *size);
void write_error(char *command);
void _exit_error(char *number);
void print_env_var(void);
void _getline_error(char *line);
int _setenv(const char *variable, const char *value);
int _unsetenv(const char *variable);
int environ_size(void);
char *_strdup(const char *src);
int _strlen(const char *str);
int _strcmp(char *s1, char *s2);
void free_array(char **array);
int environ_size(void);

#endif
