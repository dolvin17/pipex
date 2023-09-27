/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:41:16 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/27 20:22:25 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
