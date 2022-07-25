/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:50 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/07/25 16:41:57 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)

{
	char	*string;
	int		len;
	char	*dest;
	int		i;

	i = 0;
	if (!(s1))
		return (NULL);
	string = (char *) s1;
	len = ft_strlen(s1);
	dest = (char *) malloc (len + 1);
	if (!(dest))
		return (NULL);
	while (string[i])
	{
		dest[i] = string[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(const char *str)

{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)

{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *) &s[i]);
	return (NULL);
}

char	*join_string(char *s1, char *s2)

{
	char	*string;
	int		len_s1;
	int		len_s2;

	if (!(s1))
		return (ft_strdup("\0"));
	if ((!s1) || (!s2))
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(string))
		return (NULL);
	while (s1[len_s1])
	{
		string[len_s1] = s1[len_s1];
		len_s1++;
	}
	while (s2[len_s2])
		string[len_s1++] = s2[len_s2++];
	string[len_s1] = '\0';
	free(s1);
	s1 = NULL;
	return (string);
}
