/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:41:16 by dolvin17          #+#    #+#             */
/*   Updated: 2023/10/01 21:05:49 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

void	*ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	check_error(bool if_error, int value, char *str)
{
	if (if_error)
	{
		errno = value;
		perror(str);
		exit(EXIT_FAILURE);
	}
}

char	*total_path(char **paths, char *command)
{
	char	*final_path;
	char	*partial_path;
	int		j;

	j = -1;
	partial_path = NULL;
	final_path = NULL;
	while (paths[++j] != NULL)
	{
		partial_path = ft_strjoin(paths[j], "/");
		final_path = ft_strjoin(partial_path, command);
		if (!partial_path || !final_path)
		{
			ft_free(paths);
			free(partial_path);
			free(final_path);
			return (NULL);
		}
		if (access(final_path, F_OK | X_OK) == 0)
		{
			free(partial_path);
			return (final_path);
		}
	}
	return (NULL);
}

char	*get_path(char *command, char **environ)
{
	char	**paths;
	int		i;
	char	*final_path;

	i = 0;
	while (command && environ[i])
	{
		if (ft_strnstr(environ[i], "PATH=", 5))
		{
			paths = ft_split(&environ[i][5], ':');
			final_path = total_path(paths, command);
			free(paths);
			return (final_path);
		}
		i++;
	}
	return (NULL);
}

int	new_exec(char *command, char **environ)
{
	char	**split_arguments;
	char	*path;
	int		load_new;

	split_arguments = ft_split(command, ' ');
	path = get_path(split_arguments[0], environ);
	if (path && split_arguments)
	{
		load_new = execve(path, split_arguments, environ);
		free(path);
		free(split_arguments);
		return (load_new);
	}
	else
		load_new = -1;
	return (load_new);
}
