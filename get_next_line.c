/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:32:31 by tlivroze          #+#    #+#             */
/*   Updated: 2022/11/28 12:52:27 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*buffer;
	int			len;
	t_line		*line;

	if (!fd || fd < 1 || BUFFER_SIZE == 1)
		return (NULL);
	len == 0;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (check_buff == BUFFER_SIZE)
		read(fd, *buffer, BUFFER_SIZE);
		strcpy(stash, buffer);

}

int main (int ac, char **av)
{
	int		fd;

	(void)	ac;
	(void)	**av;

	fd = open(av[1], O_RDONLY);
	get_next_line(fd);
	return (0);
}