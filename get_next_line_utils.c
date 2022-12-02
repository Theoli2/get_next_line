/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:15:16 by tlivroze          #+#    #+#             */
/*   Updated: 2022/12/02 05:23:28 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_maybe_malloc_set_zero(char *buffer, size_t size)
{
	unsigned char	*pointer;
	size_t			i;

	i = 0;
	if (buffer)
		return (buffer);
	if (size == 0)
		return (NULL);
	pointer = malloc(size);
	if (!pointer)
		return (NULL);
	while (i++ < size)
	{
		pointer[i] = '\0';
	}
	return (pointer);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	r = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	ft_strlcpy((r + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (r);
}
