/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:04:40 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/10 20:21:19 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
extern char **environ;

int main()
{
	int i = 0;

	// Mientras environ[i] no sea NULL, imprime las variables de entorno.
	while (environ[i] != NULL)
	{
		if (ft_strnstr(environ[i], "PATH=", 5))
			printf("Variable de entorno %d: %s\n", i, environ[i]);
		i++;
	}

	return 0;
}