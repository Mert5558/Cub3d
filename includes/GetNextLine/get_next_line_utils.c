/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:14:45 by merdal            #+#    #+#             */
/*   Updated: 2024/12/12 12:36:04 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr2(const char *s, int c)
{
	int		len;

	len = 0;
	if (s == NULL)
		return (NULL);
	while (s[len] != (char)c)
	{
		if (s[len] == '\0')
			return (0);
		len++;
	}
	return ((char *)s + len);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen2(s2);
	if (!s1)
		return (ft_strdup2(s2, len));
	len = len + ft_strlen2(s1);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	len = 0;
	while (s1[i])
		join[len++] = s1[i++];
	i = 0;
	while (s2[i])
		join[len++] = s2[i++];
	join[len] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup2(char *str, int len)
{
	char	*dup;
	int		i;

	if (!str || !len)
		return (NULL);
	i = -1;
	dup = (char *)malloc((len + 1) * sizeof(char));
	while (++i < len)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen2(const char *str)
{
	int	l;

	l = 0;
	while (*str != '\0')
	{
		l++;
		str++;
	}
	return (l);
}
