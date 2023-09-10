/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:04:40 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/10 20:54:59 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
extern char **environ;

int main()
{
	int i;
	char **path;

	i = 0;
	path = NULL;

	while (environ[i] != NULL)
	{
		if (ft_strnstr(environ[i], "PATH=", 5))
		{
			path = ft_split(&environ[i][5], ':');
			break;
		}
		i++;
	}
	if (path != NULL)
	{
		i = 0;
		while (path[i])
		{
			printf("string: %d %s\n", i, path[i]);
			i++;
		}
		free(path);
	}
	return 0;
}
