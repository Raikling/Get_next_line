/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <aben-hzz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:19:20 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/12/14 17:16:49 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

static char	*fill_line(int fd, char *buffer, char *line)
{
	ssize_t		re;
	char		*tmp;

	re = 1;
	while (re)
	{
		re = read(fd, buffer, BUFFER_SIZE);
		if (re == -1)
		{
			free(line);
			return (NULL);
		}
		if (re == 0)
			break ;
		buffer[re] = '\0';
		if (!line)
			line = ft_strdup("");
		tmp = line;
		line = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

static char	*sep_line(char *line)
{
	ssize_t	i;
	char	*remainder;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == 0)
		return (NULL);
	remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!remainder)
	{
		free(remainder);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*stach;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stach);
		stach = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = fill_line(fd, buffer, stach);
	if (!line)
	{
		free(buffer);
		return (buffer = NULL, NULL);
	}
	stach = sep_line(line);
	free(buffer);
	buffer = NULL;
	return (line);
}
