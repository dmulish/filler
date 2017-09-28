/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:42:11 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/29 00:20:04 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_piece(t_s *s)
{
	int	i;

	i = 0;
	while (i < s->y_piece)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (s->buf[0] == '.' || s->buf[0] == '*')
				s->piece[i++] = ft_strdup(s->buf);
		}
	}
}

int		read_game(t_s *s, int j)
{
	int	i;

	i = 0;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	while (i <= s->y_map)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (ft_strstr(s->buf, "000") || (i > 0 && i < s->y_map))
				s->map[i++] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
			else if (!ft_strncmp(s->buf, "Piece", 5))
			{
				read_piece(s);
				i = s->y_map + 1;
			}
		}
		else
			return (0);
	}
	fill_piece(s);
	if (j % 2 == 0)
	{
		if (!explor_map_forw(s))
			explor_map_back(s);
	}
	else
	{
		if (!explor_map_back(s))
			explor_map_forw(s);
	}
	return (1);
}
