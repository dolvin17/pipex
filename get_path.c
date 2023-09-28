/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:41:16 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/28 19:02:24 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char **environ;

void check_error(bool if_error, int value, char *str)
{
	if (if_error)
	{
		errno = value;
		perror(str);
		exit(EXIT_FAILURE);
	}
}
char *get_path(char *command, char **environ)
{
	char **paths;		// array de arrays con todas las rutas
	char *final_path;	// array con la ruta completa "/+command"
	char *partial_path; // array con la ruta parcial "/"
	int i;
	int j;

	i = 0;
	partial_path = NULL;
	final_path = NULL;
	while (command && environ[i])
	{
		if (ft_strnstr(environ[i], "PATH=", 5))
		{
			paths = ft_split(&environ[i][5], ':');
			j = 0;
			while (paths[j] != NULL)
			{
				partial_path = ft_strjoin(paths[j], "/");
				final_path = ft_strjoin(partial_path, command);
				if (!partial_path || !final_path) // si join falla
				{
					free(paths);
					free(partial_path);
					free(final_path);
					return (NULL);
				}
				if (access(final_path, F_OK) == 0)
				{
					free(partial_path);
					return (final_path);
				}
				free(partial_path);
				free(final_path);
				j++;
			}
			free(paths);
		}
		i++;
	}
	return (NULL);
}

int loading_new_exec(char *argument, char **environ) // prepararo y cargo un nuevo programa.
{
	char **split_arguments; // dividir argumwnt en varios arrays.
	char *path;				// array con la ruta completa "/bin/cat".
	int load_new;

	split_arguments = ft_split(argument, ' ');	  // guardo los argumentos separados.
	path = get_path(split_arguments[0], environ); // paso esos argumentos al path
	if (path && split_arguments)
	{
		load_new = execve(path, split_arguments, environ); // cargo y ejecuto el nuevo programa.
		free(path);
		free(split_arguments);
		return (load_new);
	}
	else
		load_new = -1;
	return (load_new);
}

int duplicate_and_execve(int fd[2], int stdin, int stdout, char *cmd)
{
	int child;

	child = fork();
	if (child < 0)
		printf("fallo al crear el hijo");
	if (child == 0)
	{
		dup2(stdout, STDOUT_FILENO);
		dup2(stdin, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		check_error((loading_new_exec(cmd, environ) != 0), errno, "execve failed");
	}
	return (child);
}
