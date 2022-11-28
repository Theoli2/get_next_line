/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:15:16 by tlivroze          #+#    #+#             */
/*   Updated: 2022/11/28 12:07:41 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//retourne la position de la premiere occurence de  \n ou de \0 
//(fin du buffer si il n'est pas present)
int	check_buff(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		i++;
	}
	return (i);
}

