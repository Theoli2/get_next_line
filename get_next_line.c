/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:32:31 by tlivroze          #+#    #+#             */
/*   Updated: 2022/12/13 03:55:34 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_clearstash(char *stash)
{
	int		i;
	char	*tmp;

	if (stash == NULL)
		return (NULL);
	if (ft_strchr(stash, '\n'))
	{
		i = 0;
		while (stash[i] != '\n')
			i++;
		i++;
		tmp = malloc(ft_strlen(stash) - i + 1);
		if (!tmp)
			return (NULL);
		if (ft_strlen(stash) - i != 0)
			ft_strlcpy(tmp, &stash[i], ft_strlen(stash) - i + 1);
		else
			tmp[0] = '\0';
		free(stash);
		return (tmp);
	}
	free(stash);
	return (NULL);
}

char	*ft_line(char *line, char *stash)
{
	int	len_stash;

	if (ft_strchr(stash, '\n'))
	{
		len_stash = 0;
		while (stash[len_stash] != '\n')
			len_stash++;
		line = malloc(sizeof(char) * len_stash + 2);
		if (!line)
			return (NULL);
		ft_strlcpy(line, stash, len_stash + 2);
		return (line);
	}
	else
	{
		if (!stash || ft_strlen(stash) == 0)
			return (NULL);
		line = malloc(ft_strlen(stash) + 2);
		if (!line)
			return (NULL);
		ft_strlcpy(line, stash, ft_strlen(stash) + 1);
	}
	return (line);
}

char	*ft_readfd(int fd, char *stash)
{
	int		size;
	char	*buffer;

	size = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (size > 0 && !(ft_strchr(stash, '\n')))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (free(buffer), free(stash), NULL);
		buffer[size] = '\0';
		if (stash == NULL)
		{
			stash = malloc(1);
			if (!stash)
				return (NULL);
			*stash = 0;
		}
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	return (line = NULL, stash = ft_readfd(fd, stash),
		line = ft_line(line, stash),
		stash = ft_clearstash(stash), line);
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	if (ac == 2)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
