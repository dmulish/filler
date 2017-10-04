/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map_forw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:47:03 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/04 18:30:15 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*get_coord(t_s *s, int x, int y)
{
	s->res_len = (int)ft_strlen(ft_itoa(x)) + (int)ft_strlen(ft_itoa(y)) + 2;
	s->res = (char*)malloc((sizeof(char) * s->res_len) + 1);
	s->res = ft_strcat(ft_strcat(ft_strcat(ft_strdup(ft_itoa(y)), " "),
		ft_itoa(x)), "\n");
	return (s->res);
}

int		explor_map_forw(t_s *s)
{
	int	x;
	int	y;

	y = s->y - 1;
	while (++y < s->y_map)
	{
		x = s->x - 1;
		while (++x < s->x_map)
		{
			if (s->map[y][x] == s->num)
			{
				if (is_match_f(s, x, y) == 1)
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
