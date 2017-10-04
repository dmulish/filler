/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_match_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:15:15 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/04 18:15:45 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_fit_f(t_s *s, int x, int y)
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

int		inner_loop_f(t_s *s, int i)
{
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	j = -1;
	while (++j < s->x_piece)
	{
		if (s->piece[i][j] == '*')
		{
			y = (s->y) - i;
			x = (s->x) - j;
			if ((x) >= 0 && (y) >= 0 && (x + s->x_piece) < s->x_map
				&& (y + s->y_piece) < s->y_map && is_fit_f(s, x, y) == 1)
				return (1);
		}
	}
	return (0);
}

int		is_match_f(t_s *s, int a, int b)
{
	int	i;

	i = -1;
	s->x = a;
	s->y = b;
	while (++i < s->y_piece)
	{
		if (inner_loop_f(s, i) == 1)
			return (1);
	}
	return (0);
}
