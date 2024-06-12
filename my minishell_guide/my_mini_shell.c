#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototypes for built-in commands
int cd(char **args);
int shell_exit(char **args);
int help(char **args);

// List of built-in commands and their corresponding functions
char *builtin_str[] = {
    "cd",
    "exit",
    "help"
};

int (*builtin_func[]) (char **) = {
    &cd,
    &shell_exit,
    &help
};

// Number of built-in commands
int num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

// Built-in command: change directory
int cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "minishell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("minishell");
        }
    }
    return 1;
}

// Built-in command: exit the shell
int shell_exit(char **args) {
    return 0;
}

// Built-in command: print help
int help(char **args) {
    printf("Minishell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built-in commands:\n");

    for (int i = 0; i < num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

// Function to execute built-in commands
int execute(char **args) {
    if (args[0] == NULL) {
        // An empty command was entered
        return 1;
    }

    for (int i = 0; i < num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return 0;
}

// Function to launch an external program
void launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("minishell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("minishell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Function to read a line of input from the user
char *read_line(void) {
    char *line = NULL;
    ssize_t bufsize = 0; // getline() will allocate a buffer for us
    getline(&line, &bufsize, stdin);
    return line;
}

// Function to split the input line into arguments
char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "minishell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "minishell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

// Main loop of the shell
void loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();
        args = split_line(line);
        status = execute(args);
        if (status == 0) {
            launch(args);
        }

        free(line);
        free(args);
    } while (status);
}

// Main entry point
int main(int argc, char **argv) {
    // Run command loop
    loop();

    return EXIT_SUCCESS;
}
