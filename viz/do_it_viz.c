/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_viz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:44:25 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/10 21:47:39 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_it_viz(t_s *s)
{
	int	j;

	j = -1;
	if (read_game(s) > 0)
	{
		vizual(s);
		s->v->el = read_map(s->v->el, s, s->v);
		while (++j < s->y_map)
			ft_memdel((void**)&s->v_map[j]);
		ft_memdel((void**)&s->v_map);
		explor_map(s);
		write(1, s->res, s->res_len);
		ft_memdel((void**)&s->res);
	}
	else
		s->fl = 1;
}
