/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:42:11 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/04 20:38:14 by dmulish          ###   ########.fr       */
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

void	fill_map(t_s *s, int *i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (ft_strstr(s->buf, "000") || ((*i) > 0 && (*i) < s->y_map))
	{
		s->map[(*i)++] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
		if (!s->y && !s->x && ft_strchr(s->map[(*i) - 1], s->num))
		{
			s->y = (*i) - 1;
			s->x = s->x_map - ft_strlen(ft_strchr(s->map[(*i) - 1], s->num));
		}
		if (!s->e_y && !s->e_x && ft_strchr(s->map[(*i) - 1], s->e_num))
		{
			x = s->x_map - ft_strlen(ft_strchr(s->map[(*i) - 1], s->e_num)) - 1;
			while (++x < s->x_map)
			{
				if (s->map[(*i) - 1][x] == s->e_num &&
				s->pr_map[(*i) - 1][x] != s->e_num)
				{
					s->e_y = (*i) - 1;
					s->e_x = x;
					break ;
				}
			}
		}
		s->pr_map[(*i) - 1] = ft_strdup(s->map[(*i) - 1]);
	}
	else if (!ft_strncmp(s->buf, "Piece", 5))
	{
		read_piece(s);
		(*i) = s->y_map + 1;
	}
}

int		read_game(t_s *s)
{
	int	i;

	i = 0;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	while (i <= s->y_map)
	{
		if (get_next_line(0, &(s->buf)) > 0)
			fill_map(s, &i);
		else
			return (0);
	}
	fill_piece(s);
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
	return (1);
}
