/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:48:55 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/26 19:38:01 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_fit(t_s *s, int *x, int *y)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	j = -1;
	res = 0;
	while (++i < s->y_piece)
	{
		while (++j < s->x_piece)
		{
			if (s->map[(*y) + i][(*x) + j] == s->num && s->piece[i][j] == '*')
				res++;
			else
				continue ;
		}
	}
	return (res);
}

int		inner_loop(t_s *s, int i, int *x, int *y)
{
	int	j;

	j = -1;
	while (++j < s->x_piece)
	{
		if (s->piece[i][j] == '*')
		{
			(*y) -= i;
			(*x) -= j;
			if ((*x) > 0 && (*y) > 0 && ((*x) + s->x_piece - 1) < s->x_map
				&& ((*y) + s->y_piece - 1) < s->y_map && is_fit(s, x, y) == 1)
				return (1);
		}
	}
	return (0);
}

int		is_match(t_s *s, int *x, int *y)
{
	int	i;

	i = -1;
	while (++i < s->y_piece)
	{
		if (inner_loop(s, i, x, y))
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
				if (is_match(s, &x, &y))
					s->res = get_coord(s, x, y);
				else
					s->res = ft_strdup("-1 -1\n");
				return ;
			}
		}
	}
}
