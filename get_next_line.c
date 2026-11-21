/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <joacarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:33:07 by joacarva          #+#    #+#             */
/*   Updated: 2026/11/20 14:33:07 by joacarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_stash(int fd, char *stash, char *buffer)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 0;
	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (!stash)
			return (NULL);
	}
	if (bytes < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*rest;
	size_t	len;

	len = 0;
	while ((*stash)[len] && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	line = ft_substr(*stash, 0, len);
	rest = NULL;
	if (line && (*stash)[len])
	{
		rest = ft_substr(*stash, len, ft_strlen(*stash) - len);
		if (!rest)
		{
			free(line);
			line = NULL;
		}
	}
	free(*stash);
	*stash = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_stash(fd, stash, buffer);
	free(buffer);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (extract_line(&stash));
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(int c, char **v)
{
	int fd;
	char *line;

	if (c != 2)
		return (printf("Usage: %s filename\n", v[0]), 1);
	fd = open(v[1], O_RDONLY);
	if (fd == -1)
		return (perror(v[1]), 1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/