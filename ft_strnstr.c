/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:54:04 by dolvin17          #+#    #+#             */
/*   Updated: 2023/09/28 19:28:46 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* localiza un substring en un string */
static	size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static	int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
			i++;
		else
			return ((*((unsigned char *)s1 + i)) - *((unsigned char *)s2 + i));
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	position;

	if (*needle == '\0')
		return ((char *)haystack);
	position = ft_strlen((char *)needle);
	while (*haystack != '\0' && len-- >= position)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, position) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
