/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:04:40 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/29 21:18:12 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

pid_t	duplicate_and_execve(int fd[2], int stdin, int stdout, char *cmd)
{
	pid_t	child;

	child = fork();
	check_error((child < 0), ECHILD, "error al crear proceso");
	if (child == 0)
	{
		dup2(stdout, STDOUT_FILENO);
		dup2(stdin, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (loading_new_exec(cmd, environ) != 0)
		{
			perror("error al ejecutar el comando");
			exit(EXIT_FAILURE);
		}
	}
	return (child);
}

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	infile;
	int	outfile;
	int	childs[2];

	check_error((argc != 5), EINVAL, "Faltan argumentos");
	infile = open(argv[1], O_RDONLY);
	check_error((infile == -1), EACCES, "No hay permisos de lectura");
	outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	check_error((outfile == -1), ENOENT, "No hay permisos de escritura");
	check_error((pipe(fd) == -1), errno, "Falló la creación de la tubería");
	childs[0] = duplicate_and_execve(fd, infile, fd[1], argv[2]);
	childs[1] = duplicate_and_execve(fd, fd[0], outfile, argv[3]);
	close(fd[0]);
	close(fd[1]);
	waitpid(childs[0], NULL, 0);
	waitpid(childs[1], NULL, 0);
	return (0);
}
