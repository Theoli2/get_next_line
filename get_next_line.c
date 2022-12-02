/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:32:31 by tlivroze          #+#    #+#             */
/*   Updated: 2022/12/02 10:44:49 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_line(char **line, char *buffer, char *stash)
{

}

int	ft_readfd(int fd, char *buffer, char *stash, int ret)
{
	if (ft_strchr(stash, '\n') == NULL && ft_strchr(stash, '\0') == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			return (ret)
		if (ft_strchr(buffer, '\n') != NULL || ft_strchr(buffer, '\0') != NULL)
			ret = 0;
		return (ret);
	}
	else
		return (1);
}

char	*get_next_line(int fd)
{
	static char		stash[BUFFER_SIZE + 1];
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	int				ret;

	while (ret > 0)
	{
		ret = ft_readfd(fd, buffer, stash, ret);
		if (ret > 0)
			ret = ft_line()
	}
	return (line);
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf ("%s", line);
		free(line);
		if (line == NULL)
			break ;
	}
	return (0);
}
