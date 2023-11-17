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
ssize_t reader(char **line, size_t *size_line);
void exit_status(int my_status, char **single_command, char **token, int *status);
void custom_exit(int my_status, char **commands,
char *line, int *status);


void excute_cmd(char **commands, char **envp, int *status);
int _locate(char *command, char **full_path);
void wait_child_process(int *status);
char *_getenv(const char *path);


char **split_cmd(char *string, char *delim);


void handle_err(char *command);
void write_exit_error(char *number);
void _env(void);
void _getline_error(char *line);


void _strcat(char *dest, const char *src);
char *_strdup(const char *src);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strto_i(char *s);
void _strcpy(char *dest, const char *src);



ssize_t _getline(char **line, size_t *n_ch, int fd);
char *_strchr(char* str, int c);
char *_strtok(char *str, const char *delim);

void free_arr(char **array);

#endif