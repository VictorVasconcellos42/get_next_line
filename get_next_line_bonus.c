/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:49:29 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/07/25 16:42:15 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*check_string(char *string, int i)

{
	if (!(string))
		return (NULL);
	else if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	return (string);
}

char	*read_rest(char *string)

{
	int		i;
	int		count;
	char	*rest;

	i = 0;
	if (!(string) || string[i] == '\0')
	{
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

char	*line_cut(char *string, int i)

{
	char	*line;

	if (!(string) || string[i] == '\0')
		return (check_string(string, 0));
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		line = malloc(sizeof(char) * (++i) + 1);
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
		line[i++] = '\n';
	line[i] = '\0';
	free(string);
	return (line);
}

char	*read_string(int fd, char *backup)

{
	char	*aux;
	int		buffer;

	buffer = 1;
	aux = malloc(BUFFER_SIZE + 1);
	if (!(backup))
		backup = ft_strdup("\0");
	if (!(aux))
		return (NULL);
	while (buffer > 0 && !(ft_strchr(backup, '\n')))
	{
		buffer = read(fd, aux, BUFFER_SIZE);
		if (buffer < 0)
			break ;
		aux[buffer] = '\0';
		backup = join_string(backup, aux);
	}
	free(aux);
	if (buffer < 0)
	{
		free(backup);
		return (NULL);
	}
	else
		return (backup);
}

char	*get_next_line(int fd)

{
	static char	*backup[MAX_FD];
	char		*my_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	backup[fd] = read_string(fd, backup[fd]);
	if (!(backup[fd]))
		return (NULL);
	my_line = line_cut(backup[fd], 0);
	if (!(my_line))
	{
		if (backup[fd] != NULL)
			backup[fd] = NULL;
		return (NULL);
	}
	backup[fd] = read_rest(backup[fd]);
	return (my_line);
}
