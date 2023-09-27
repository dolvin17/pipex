/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:58:50 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/27 19:52:07 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <fcntl.h>

int main();
size_t ft_strlen(const char *str);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char **ft_split(char const *s, char c);
char *ft_strjoin(char const *str_1, char const *str_2);
int loading_new_exec(char *argument, char **environ);
char *get_path(char *command, char **environ);
#endif