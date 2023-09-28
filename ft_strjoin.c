/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:11:56 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/28 18:12:39 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* reserva con malloc un nuevo string, basado en la union
de los dos strings dados como parámetros */
static size_t ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char const *str_1, char const *str_2)
{
	size_t len;
	char *sum_str;
	size_t i;
	size_t j;

	if (!str_1 || !str_2)
		return (NULL);
	len = ft_strlen(str_1) + ft_strlen(str_2) + 1;
	sum_str = malloc(sizeof(char) * len + 1);
	if (!sum_str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str_1))
	{
		sum_str[i] = str_1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(str_2))
	{
		sum_str[i + j] = str_2[j];
		j++;
	}
	sum_str[i + j] = '\0';
	return (sum_str);
}