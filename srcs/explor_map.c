/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:48:55 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/10 16:44:43 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// int		find_island(t_s *s, int x, int y)
// {
// 	(void)s;
// 	(void)x;
// 	(void)y;
// 	return (0);
// }

char	*get_coord(t_s *s, int x, int y)
{
	s->res_len = ft_strlen(ft_itoa(x)) + ft_strlen(ft_itoa(y)) + 2;
	s->res = (char*)malloc((sizeof(char) * s->res_len) + 1);
	s->res = ft_strdup(ft_itoa(x));
	s->res = ft_strcat(s->res, " ");
	s->res = ft_strcat(s->res, ft_itoa(y));
	s->res = ft_strcat(s->res, "\n");
	return (s->res);
}

void	explor_map(t_s *s)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < s->y_map)
	{
		while (++x < s->x_map)
		{
			// find_island(s, x, y);
			if ((s->map[y][x] == s->num) && (!s->map[y][x]
				|| (s->map[y][x] == '.')))
				s->res = get_coord(s, x, y);
		}
	}
}
