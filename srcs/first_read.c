/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:16:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/02 18:23:19 by dmulish          ###   ########.fr       */
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
			{
				s->map[i] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
				if (ft_strchr(s->map[i], s->num))
				{
					s->y = i;
					s->x = s->x_map - ft_strlen(ft_strchr(s->map[i], s->num));
				}
				else if (ft_strchr(s->map[i], s->e_num))
				{
					s->e_y = i;
					s->e_x =
						s->x_map - ft_strlen(ft_strchr(s->map[i], s->e_num));
				}
			}
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
	if (s->e_y < s->x)
	{
		if (!explor_map_forw(s))
			explor_map_back(s);
	}
	else
	{
		if (!explor_map_back(s))
			explor_map_forw(s);
	}
}
