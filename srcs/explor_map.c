/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:48:55 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/12 16:13:42 by dmulish          ###   ########.fr       */
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
	s->res_len = (int)ft_strlen(ft_itoa(x)) + (int)ft_strlen(ft_itoa(y)) + 2;
	s->res = (char*)malloc((sizeof(char) * s->res_len) + 1);
	s->res = ft_strcat(ft_strcat(ft_strcat(ft_strdup(ft_itoa(x)), " "),
		ft_itoa(y)), "\n");
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
