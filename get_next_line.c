/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:49:29 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/07/25 10:27:43 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_rest(char *string)

{
	int		i;
	int		count;
	char	*rest;

	i = 0;
	if (!(string) || string[i] == '\0')
	{i
		free(string);
		return (NULL);
	}
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(string) - i + 1));
	if (!(rest))
		return (NULL);
	count = 0;
	while (string[i])
		rest[count++] = string[i++];
	rest[count] = '\0';
	return (rest);
}

char	*line_cut(char *string)

{
	int		i;
	char	*line;

	i = 0;
	if ((!(string) || string[i] == '\0'))
	{
		free(string);
		return (NULL);
	}
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
	{
		i++;
		line = malloc(sizeof(char) * i + 1);
	}
	else
		line = malloc(i + 1);
	if (!(line))
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	free(string);
	return (line);
}

char	*read_string(int fd, char *backup)

{
	char	*aux;
	int		buffer;

	buffer = 1;	
	if (!(backup))
		backup = ft_strdup("\0");
	aux = malloc(BUFFER_SIZE + 1);
	if (!(aux))
		return (NULL);
	while (buffer && !(ft_strchr(backup, '\n')))
	{
		buffer = read(fd, aux, BUFFER_SIZE);
		if (buffer < 0 || fd < 0)
		{
			free(aux);
			return (NULL);
		}
		aux[buffer] = '\0';
		backup = join_string(backup, aux);
	}
	free(aux);
	return (backup);
}


char	*get_next_line(int fd)

{
	static char	*backup;
	char		*my_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_string(fd, backup);
	if (!(backup))
		return (NULL);
	my_line = line_cut(backup);
	if (!(my_line))
		return (NULL);
	backup = read_rest(backup);
	return (my_line);	
}
