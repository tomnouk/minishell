
# **minishell**

## **Project overview**
The **minishell** project is an essential part of the **42 curriculum**.
It tasks students with creating a simple shell, similar to bash.
This project aims to improve understanding of processes, file descriptors, and the intricacies of shell programming in C.

#### **Objective**
- **Create a Shell**: Implement a functional shell that can execute commands, handle pipes, redirections, and more.
- **Builtin Commands**: Implement built-in commands such as `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Signal Handling**: Ensure proper handling of signals like `ctrl-C`, `ctrl-D`, and `ctrl-\`.
- **History Management**: Maintain a working command history.
- **Bonus Features**: Implement logical operators `&&` and `||`, wildcard expansion using `*`, and support for parentheses for command grouping.

#### **Key features**
- **Prompt Display**: The shell displays a prompt when waiting for a new command.
- **Command Execution**: The shell searches for and launches the right executable based on the `PATH` variable or using a relative or absolute path.
- **Quotes Handling**: Properly handle single (`'`) and double (`"`) quotes, preventing interpretation of metacharacters within the quoted sequence.
- **Redirections**: Support for input (`<`), output (`>`), append (`>>`), and heredoc (`<<`) redirections.
- **Pipes**: Implement the pipe (`|`) functionality to connect commands.
- **Environment Variables**: Handle environment variables and special variables like `$?` and `$$` (which returns the PID).
- **Advanced Command Handling**: Support for logical operators `&&` and `||`, and wildcard expansion with `*`.

#### **Compiling the Project**
The **minishell** project includes a Makefile for easy compilation. Simply run:
```
make
```
This will generate the `minishell` executable.

#### **Running the Project**
To start the shell, run:
```
./minishell
```
