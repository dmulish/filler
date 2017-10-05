/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:45:23 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/05 15:55:45 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_fit_b(t_s *s, int x, int y)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	res = 0;
	while (++i < s->y_piece)
	{
		j = -1;
		while (++j < s->x_piece)
		{
			if (s->map[y + i][x + j] == s->num && s->piece[i][j] == '*')
				res++;
			if ((s->map[y + i][x + j] == s->e_num
			|| s->map[y + i][x + j] == s->e_num + 32)
			&& s->piece[i][j] == '*')
				return (0);
		}
	}
	if (res == 1)
	{
		s->x = x;
		s->y = y;
	}
	return (res);
}

int		inner_loop_b(t_s *s, int i)
{
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	j = s->x_piece;
	while (--j >= 0)
	{
		if (s->piece[i][j] == '*')
		{
			y = (s->y) - i;
			x = (s->x) - j;
			if ((x) >= 0 && (y) >= 0 && (x + s->x_piece) < s->x_map
				&& (y + s->y_piece) < s->y_map && is_fit_b(s, x, y) == 1)
				return (1);
		}
	}
	return (0);
}

int		is_match_b(t_s *s, int a, int b)
{
	int	i;

	s->x = a;
	s->y = b;
	i = s->y_piece;
	while (--i >= 0)
	{
		if (inner_loop_b(s, i) == 1)
			return (1);
	}
	return (0);
}

int		explor_map_back(t_s *s)
{
	int	x;
	int	y;

	y = s->y_map;
	while (--y >= 0)
	{
		x = s->x_map;
		while (--x >= 0)
		{
			if (s->map[y][x] == s->num)
			{
				if (is_match_b(s, x, y) == 1)
				{
					s->res = get_coord(s, s->x, s->y);
					return (1);
				}
			}
		}
	}
	s->res = ft_strdup("0 0\n");
	s->res_len = 4;
	return (0);
}
