/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:23:36 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/07 16:47:29 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	v->fl_noise = 0;
	iso(v);
}

void	draw_map(t_s *s)
{
	s->v = (t_v*)malloc(sizeof(t_v) + 1);
	init(s->v);
	s->v->el = (t_lst*)malloc(sizeof(t_lst) + 1);
	draw_grid(s);
}
