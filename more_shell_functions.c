#include "main.h"


int environ_size(void) {
    int size = 0;
    char **env = environ;

    /* Count the number of non-NULL elements in the environ array */
    while (*env != NULL) {
        size++;
        env++;
    }

    return size;
}
/** 
 * _setenv - Set or update an environment variable.
 * @variable: The name of the environment variable.
 * @value: The value to set for the environment variable.
 *
 * Return: Returns 0 on success, -1 on failure.
 */
int _setenv(const char *variable, const char *value) {
    char *existing_value;
    if (!variable || !value) {
        perror("setenv");
        return -1;
    }

    existing_value = _getenv(variable);

    if (existing_value != NULL) {
         char **new_environment;
        int variable_length = _strlen(variable);
        int existing_value_length = _strlen(existing_value);
        int i;

        char *new_entry = malloc(variable_length + 1 + existing_value_length + 1);
        if (!new_entry) {
            perror("setenv");
            return -1;
        }

        strcpy(new_entry, variable);
        strcat(new_entry, "=");
        strcat(new_entry, value);

        for (i = 0; environ[i] != NULL; i++) {
            if (!strncmp(variable, environ[i], variable_length)) {
                free(environ[i]);
                environ[i] = new_entry;
                 free(existing_value);
                return 0;
            }
        }

        new_environment = malloc((environ_size() + 2) * sizeof(char *));
        if (!new_environment) {
            perror("setenv");
            return -1;
        }

        for (i = 0; environ[i] != NULL; i++) {
            new_environment[i] = environ[i];
        }

        new_environment[environ_size()] = new_entry;
        new_environment[environ_size() + 1] = NULL;

        environ = new_environment;

        return 0;
    } else {
        int variable_length = _strlen(variable);
        int value_length = _strlen(value);
        char **new_environment;
        int i;

        char *new_entry = malloc(variable_length + 1 + value_length + 1);
        if (!new_entry) {
            perror("setenv");
            return -1;
        }

        strcpy(new_entry, variable);
        strcat(new_entry, "=");
        strcat(new_entry, value);

        new_environment = malloc((environ_size() + 2) * sizeof(char *));
        if (!new_environment) {
            perror("setenv");
            return -1;
        }

        for (i = 0; environ[i] != NULL; i++) {
            new_environment[i] = environ[i];
        }

        new_environment[environ_size()] = new_entry;
        new_environment[environ_size() + 1] = NULL;
        environ = new_environment;
        free(new_environment);
        free(new_entry);
        return (0);
    }
}

/**
 * _unsetenv - Unset an environment variable.
 * @variable: The name of the environment variable to unset.
 *
 * Return: Returns 0 on success, -1 on failure.
 */
int _unsetenv(const char *variable) {
    int variable_length;
    int i, j;

    if (!variable) {
        perror("unsetenv");
        return -1;
    }

    variable_length = _strlen(variable);

    for (i = 0; environ[i] != NULL; i++) {
        if (!strncmp(variable, environ[i], variable_length)) {
            for (j = i; environ[j] != NULL; j++) {
                environ[j] = environ[j + 1];
            }

            return 0;
        }
    }

    fprintf(stderr, "unsetenv: %s: not found\n", variable);
    return -1;
}
