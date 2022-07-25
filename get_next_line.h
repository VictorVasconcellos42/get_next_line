/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:00:30 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/07/25 16:06:13 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*read_rest(char *string);
char	*read_string(int fd, char *backup);
char	*get_next_line(int fd);
char	*join_string(char *s1, char *s2);
char	*ft_strdup(const char *string);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*line_cut(char *string, int i);
char	*check_string(char *string, int i);
#endif
