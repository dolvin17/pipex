# Pipex

Pipex is a C program designed to replicate the functionality of the shell command `<<` to redirect input from a file and `>>` to redirect output to a file. It allows you to execute a series of shell commands while redirecting input and output to specified files.

## Project Description

Pipex is a powerful tool for streamlining and automating tasks that involve file input and output redirection. It lets you perform complex operations with data pipelines, while providing clear control over input and output files.

## Features

- Input and output redirection: Pipex replicates the behavior of the `<<` and `>>` operators in the shell, making it possible to redirect the standard input and output of commands to specified files.
- Command execution: The program allows you to execute a series of shell commands, providing flexibility and automation for various tasks.
- Error handling: Pipex includes error handling to ensure that commands execute as expected and that the specified files exist.

## Usage

To use Pipex, provide two input files and a sequence of commands. The program will execute the commands with the first input file as standard input and redirect the standard output to the second input file.

```bash
./pipex infile cmd1 cmd2 outfile
```

## Getting Started

To get started with Pipex, clone the repository and compile the code using the provided Makefile. Then, you can run the program with your input data.

```bash
git clone https://github.com/yourusername/pipex.git
cd pipex
make
./pipex infile cmd1 cmd2 outfile
```

## Contributing

 All contributions are welcomed! If you have any ideas for improvements, bug fixes, or new features, please open an issue or submit a pull request.
