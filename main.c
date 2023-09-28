/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:04:40 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/28 18:58:30 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char **environ;

int main(int argc, char *argv[])
{
	int fd[2];
	int infile;
	int outfile;
	int childs[2];

	check_error((argc != 5), EINVAL, "Faltan argumentos");
	infile = open(argv[1], O_RDONLY);
	check_error((infile == -1), EACCES, "No hay permisos de lectura para abrir");
	outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
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
