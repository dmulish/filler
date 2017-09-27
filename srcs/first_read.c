/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:16:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/27 19:58:08 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_read_map(t_s *s)
{
	int		i;

	i = -1;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	s->map = (char**)malloc((sizeof(char*) * s->y_map) + 1);
	while (i <= s->y_map)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (ft_isdigit(s->buf[0]) && i != -1)
				s->map[i] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
			else if (!ft_strncmp(s->buf, "Piece", 5))
				read_piece(s);
		}
		i++;
	}
	i = 0;
	while (i < s->y_piece)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			(s->buf[0] == '.' || s->buf[0] == '*') ?
				s->piece[i++] = ft_strdup(s->buf) : 0;
		}
	}
}

void	first_read(t_s *s)
{
	s->buf = (char*)malloc((sizeof(char) * 20) + 1);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (!ft_strncmp("Plateau", s->buf, 7))
		{
			s->x_map = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
			s->y_map = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
			break ;
		}
	}
	if (s->buf)
		free(s->buf);
	first_read_map(s);
	explor_map(s);
}
