/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:30:51 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/08/02 00:48:00 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t		size;
	size_t		i;
	char		*string;

	i = 0;
	while (s[i])
		i++;
	size = (i + 1);
	string = (char *)malloc(size * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < size)
	{
		string[i] = s[i];
		i++;
	}
	return (string);
}

char	*ft_strchr(const char *s, int c)

{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char	*s)

{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*string;
	size_t		i;
	size_t		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	free(s1);
	return (string);
}
