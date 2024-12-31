/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:12:42 by merdal            #+#    #+#             */
/*   Updated: 2024/12/12 15:03:22 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*returnline;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	text = readtext(fd, text);
	if (text == NULL)
		return (NULL);
	returnline = countlen(text);
	temp = readline(text);
	free(text);
	if (!temp)
		text = NULL;
	text = temp;
	return (returnline);
}

char	*readtext(int fd, char *text)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytesread;

	bytesread = 1;
	while (bytesread > 0 && !ft_strchr2(text, '\n'))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(text);
			return (NULL);
		}
		if (bytesread > 0)
		{
			buffer[bytesread] = '\0';
			text = ft_strjoin2(text, buffer);
		}
	}
	return (text);
}

char	*countlen(char *text)
{
	char	*singleline;
	size_t	length;
	size_t	i;

	if (text == NULL || *text == '\0')
		return (NULL);
	length = 0;
	while (text[length] != '\n' && text[length] != '\0')
		length++;
	singleline = malloc(length + 2);
	if (singleline == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		singleline[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		singleline[i] = text[i];
		i++;
	}
	singleline[i] = '\0';
	return (singleline);
}

char	*readline(char *buffer)
{
	char	*nextline;
	char	*newlinepos;
	size_t	i;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	nextline = NULL;
	newlinepos = ft_strchr2(buffer, '\n');
	if (!newlinepos || !newlinepos[1])
		return (NULL);
	len = ft_strlen2(newlinepos) + 1;
	nextline = malloc((len + 1) * sizeof(char));
	if (!nextline)
		return (NULL);
	i = 0;
	while (newlinepos[i + 1])
	{
		nextline[i] = newlinepos[i + 1];
		i++;
	}
	nextline[i] = '\0';
	return (nextline);
}
