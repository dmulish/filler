/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:42:11 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/08 19:22:48 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map_cord(t_s *s, int *i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
}

void	fill_map(t_s *s, int *i)
{
	if (ft_strstr(s->buf, "000") || ((*i) > 0 && (*i) < s->y_map))
	{
		s->map[(*i)++] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
		get_map_cord(s, i);
	}
	else if (!ft_strncmp(s->buf, "Piece", 5))
	{
		read_piece(s);
		(*i) = s->y_map + 1;
	}
}

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
	i = -1;
	while (++i < s->y_map)
		s->pr_map[i] = ft_strdup(s->map[i]);
	fill_piece(s);
	return (1);
}
