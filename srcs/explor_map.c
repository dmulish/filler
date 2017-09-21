/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:48:55 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/21 18:36:37 by dmulish          ###   ########.fr       */
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
				s->res = get_coord(s, x, y);
				return ;
			}
		}
	}
}
