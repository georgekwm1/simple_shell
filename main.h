#ifndef MAIN_H_
#define MAIN_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_ARGS 10
extern char **environ;

char *read_input_line();
void parse_input(char *line, char *args[]);
void execute_command(char *args[]);
char **executor_2(char **envir_paths);
char* _strtok(char *str, const char *del);
char *_getenv(const char *name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void change_dir(char *line);

#endif
