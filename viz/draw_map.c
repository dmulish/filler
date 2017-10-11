/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:23:36 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/11 22:16:01 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	tlst_del(t_lst **head)
{
	t_lst	*tmp;
	t_lst	*next;

	if (!head || !*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*head = NULL;
}

void	init(t_v *v)
{
	v->dy = 0;
	v->dx = 0;
	v->fl_l = 0;
	v->fl_r = 0;
	v->fl_d = 0;
	v->fl_u = 0;
	v->zoom = 1;
	v->rand = 42;
	v->fl_ai = 0;
	v->fl_ad = 0;
	v->fl_bi = 0;
	v->fl_bd = 0;
	v->fl_gi = 0;
	v->fl_gd = 0;
	v->max_x = 0;
	v->fl_zin = 0;
	v->mult_z = 5;
	v->fl_zout = 0;
	iso(v);
}

void	draw_map(t_s *s)
{
	int	i;

	i = -1;
	s->v = (t_v*)malloc(sizeof(t_v) + 1);
	init(s->v);
	draw_grid(s);
	while (++i < s->y_map)
		free(s->v_map);
	(s->v_map) ? free(s->v_map) : 0;
	tlst_del(&(s->v->el));
	(s->v) ? free(s->v) : 0;
}
