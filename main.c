/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:13:56 by dolvin17          #+#    #+#             */
/*   Updated: 2023/01/30 18:16:24 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	putstr(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

int	main()
{
	int	pipefd[2];
	pid_t	pid;
	char	buf;

	pid = fork();
		
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		close(pipefd[1]);
		putstr(STDOUT_FILENO, "Hijo: Cuál es el secreto en este pipe?\n");
		putstr(STDOUT_FILENO, "Hijo: \"");
		while (read(pipefd[0], &buf, 1) > 0)
		{
			write(STDOUT_FILENO, &buf, 1);
		}
		write(STDOUT_FILENO, "\"\n");
		write(STDOUT_FILENO, "Hijo: Wow! Veré a mi padre\n");
		close(pipefd[0]);
		exit(EXIT_SUCCESS);
	}
		else
		{
			close(pipefd[0]);
			putstr(STDOUT_FILENO, "Padre: Estoy escribiendo un secreto en este pipe\n");
			putstr(pipefd[1], "\e[33mSoy tu padre mwahahahah!\e[0m");
			close(pipefd[1]);
			wait(NULL);
			putstr(STDOUT_FILENO, "Padre: Hola hijo\n");
			exit(EXIT_SUCCESS);
		}
}
