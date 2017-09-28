/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:45:23 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/29 00:11:16 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*get_coord_b(t_s *s, int x, int y)
{
	s->res_len = (int)ft_strlen(ft_itoa(x)) + (int)ft_strlen(ft_itoa(y)) + 2;
	s->res = (char*)malloc((sizeof(char) * s->res_len) + 1);
	s->res = ft_strcat(ft_strcat(ft_strcat(ft_strdup(ft_itoa(y)), " "),
		ft_itoa(x)), "\n");
	return (s->res);
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
			if (s->map[y][x] == s->e_num || s->map[y][x] == s->e_num + 32)
			{
				s->e_x = x;
				s->e_y = y;
			}
			if (s->map[y][x] == s->num)
			{
				if (is_match(s, x, y) == 1)
				{
					s->res = get_coord_b(s, s->x, s->y);
					return (1);
				}
			}
		}
	}
	s->res = ft_strdup("0 0\n");
	s->res_len = 4;
	return (0);
}
