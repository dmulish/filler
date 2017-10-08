/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:21:05 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/07 13:53:52 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		exit_hook(void)
{
	exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_v *v)
{
	(void)x;
	(void)y;
	(button == 4) ? v->mult_z -= 0.5 : v->mult_z;
	(button == 5) ? v->mult_z += 0.5 : v->mult_z;
	return (0);
}

void	draw_grid(t_s *s)
{
	s->v->mlx = mlx_init();
	s->v->win = mlx_new_window(s->v->mlx, W, H, "filler");
	mlx_mouse_hook(s->v->win, mouse_hook, s->v);
	mlx_hook(s->v->win, 17, 0, exit_hook, 0);
	mlx_loop_hook(s->v->mlx, loop_hook, s);
	mlx_loop(s->v->mlx);
}
