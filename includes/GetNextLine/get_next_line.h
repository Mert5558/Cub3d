/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:14:57 by merdal            #+#    #+#             */
/*   Updated: 2024/12/12 12:34:43 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*readtext(int fd, char *text);
char	*countlen(char *text);
char	*readline(char *buffer);
char	*ft_strchr2(const char *str, int c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup2(char *str, int len);
size_t	ft_strlen2(const char *str);

#endif