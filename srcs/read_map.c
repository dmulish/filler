/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:16:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/07 17:32:48 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_s *s)
{
	char	**arr;

	arr = 0;
	s->buf = (char*)malloc((sizeof(char) * 20) + 1);
	ft_bzero(s->buf, 20);
	while (get_next_line(1, &(s->buf)) > 0)
	{
		if (!ft_strncmp("Plateau", s->buf, 7))
		{
			arr = ft_strsplit(s->buf, ' ');
			s->x_map = ft_atoi(arr[1]);
			s->y_map = ft_atoi(arr[2]);
		}
	}
	free(s->buf);
}
