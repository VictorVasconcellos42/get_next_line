/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:06:52 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/07/25 10:18:48 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)

{
	int		fd;
	char	*string;
	fd = open("empty", O_RDONLY);
	string = get_next_line(fd);
	printf("%s", string);
	free(string);
	return 0;	
}
