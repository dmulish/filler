/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:24 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/11 02:56:53 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	t_lst_del(t_lst *head)
{
	t_lst	*tmp;
	t_lst	*next;

	if (!head)
		return ;
	tmp = head;
	next = tmp->next;
	while (tmp)
	{
		next = tmp->next;
		ft_memdel((void**)&tmp);
		tmp = next;
	}
}

t_lst	*next_y(t_lst *orig, int max_x)
{
	t_lst	*tmp;

	tmp = orig;
	while (max_x-- > 0 && tmp)
		tmp = tmp->next;
	return (tmp);
}

void	tips(t_v *v)
{
	mlx_string_put(v->mlx, v->win, 1050, 30, 0xfff4e3, "Iso: I");
	mlx_string_put(v->mlx, v->win, 1050, 50, 0xfff4e3, "Grid: Z");
	mlx_string_put(v->mlx, v->win, 860, 30, 0xfff4e3, "Zoom: + -");
	mlx_string_put(v->mlx, v->win, 860, 50, 0xfff4e3, "Move: arrows");
	mlx_string_put(v->mlx, v->win, 860, 70, 0xfff4e3, "Rotate: W A S D");
}

void	draw(t_v *v)
{
	t_lst	*tmp;

	tmp = v->el;
	v->dist_x = (double)W / (double)(v->max_x + 2);
	v->dist_y = (double)H / (double)(v->max_y + 1);
	tmp = rot(tmp, v);
	tips(v);
	while (tmp)
	{
		if (tmp->next && tmp->x != v->max_x + 1)
			line(tmp, tmp->next, v);
		line(tmp, next_y(tmp, v->max_x + 1), v);
		tmp = tmp->next;
	}
	// t_lst_del(tmp); tmp tut NULL!!
	t_lst_del(v->el);
}
