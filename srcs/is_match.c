/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:38:16 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/29 00:07:42 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_fit(t_s *s)
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
			if (s->map[s->y + i][s->x + j] == s->num && s->piece[i][j] == '*')
				res++;
			if ((s->map[s->y + i][s->x + j] == s->e_num
			|| s->map[s->y + i][s->x + j] == s->e_num + 32)
			&& s->piece[i][j] == '*')
				res = 2;
		}
	}
	return (res);
}

int		inner_loop(t_s *s, int i)
{
	int	j;

	j = -1;
	while (++j < s->x_piece)
	{
		if (s->piece[i][j] == '*')
		{
			(s->y) -= i;
			(s->x) -= j;
			if ((s->x) >= 0 && (s->y) >= 0 && (s->x + s->x_piece - 1) < s->x_map
				&& (s->y + s->y_piece - 1) < s->y_map && is_fit(s) == 1)
				return (1);
		}
	}
	return (0);
}

int		is_match(t_s *s, int a, int b)
{
	int	i;

	i = -1;
	s->x = a;
	s->y = b;
	while (++i < s->y_piece)
	{
		if (inner_loop(s, i) == 1)
			return (1);
	}
	return (0);
}
