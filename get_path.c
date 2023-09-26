/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:41:16 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/26 21:39:55 by dolvin17         ###   ########.fr       */
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
				printf("partial_path\n%s %d \n ", partial_path, j);
				final_path = ft_strjoin(partial_path, command);
				printf("final_path\n%s %d \n ", final_path, j);
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
