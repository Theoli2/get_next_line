/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:32:34 by tlivroze          #+#    #+#             */
/*   Updated: 2022/11/28 11:54:50 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_line
{
	char			content[BUFFER_SIZE + 1];
	struct s_line	*next;
}	t_line;

char	*get_next_line(int fd);
int		check_buff(char *buff);

#endif