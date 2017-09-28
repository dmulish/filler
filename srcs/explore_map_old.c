/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore_map_old.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:47:03 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/28 19:31:16 by dmulish          ###   ########.fr       */
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

char	*get_coord(t_s *s, int x, int y)
{
	s->res_len = (int)ft_strlen(ft_itoa(x)) + (int)ft_strlen(ft_itoa(y)) + 2;
	s->res = (char*)malloc((sizeof(char) * s->res_len) + 1);
	s->res = ft_strcat(ft_strcat(ft_strcat(ft_strdup(ft_itoa(y)), " "),
		ft_itoa(x)), "\n");
	return (s->res);
}

void	explor_map(t_s *s)
{
	int	x;
	int	y;

	y = -1;
	while (++y < s->y_map)
	{
		x = -1;
		while (++x < s->x_map)
		{
			if (s->map[y][x] == s->num)
			{
				if (is_match(s, x, y) == 1)
				{
					s->res = get_coord(s, s->x, s->y);
					return ;
				}
			}
		}
	}
	s->res = ft_strdup("0 0\n");
	s->res_len = 4;
}
