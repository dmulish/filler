/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:55:33 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/09 15:02:57 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*trans_map(t_s *s, char *raw, int *i)
{
	int	x;
	int	x_map;

	x = -1;
	x_map = -1;
	raw = (char*)malloc((sizeof(char) * (2 * s->x_map)) + 1);
	while (++x_map < s->x_map)
	{
		if (s->map[*i][x_map] == '.')
		{
			raw[++x] = '0';
			raw[++x] = (x_map != s->x_map - 1) ? ' ' : '\n';
		}
		else
		{
			if (s->map[*i][x_map] == s->num)
				raw[++x] = '6';
			else if (s->map[*i][x_map] == s->e_num)
				raw[++x] = '5';
			raw[++x] = (x_map != s->x_map - 1) ? ' ' : '\n';
		}
	}
	return (raw);
}

void	vizual(t_s *s)
{
	int		i;

	i = -1;
	s->v_map = (char**)malloc((sizeof(char*) * s->y_map) + 1);
	while (++i < s->y_map)
		s->v_map[i] = trans_map(s, s->v_map[i], &i);
}
