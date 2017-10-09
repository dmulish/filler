/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:54:39 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/09 16:12:59 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# define H 1200
# define W 1200
# define RAD(x) ((x) * M_PI / 360)
# define SWAP(a, b) { a ^= b; b ^= a; a ^= b; }
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_lst
{
	int				x;
	int				y;
	int				z;
	int				x1;
	int				y1;
	int				z1;
	int				col;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_d
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z0;
	int				z1;
	int				dx;
	int				dy;
	int				s;
	double			step;
	double			error;
}					t_d;

typedef struct		s_v
{
	int				max_x;
	int				max_y;
	int				rand;
	int				dx;
	int				dy;
	int				fl_l;
	int				fl_r;
	int				fl_u;
	int				fl_d;
	int				fl_ai;
	int				fl_ad;
	int				fl_bi;
	int				fl_bd;
	int				fl_gi;
	int				fl_gd;
	int				fl_zin;
	int				fl_zout;
	void			*mlx;
	void			*win;
	double			zoom;
	double			alpha;
	double			beta;
	double			gamma;
	double			dist_x;
	double			dist_y;
	double			mult_z;
	t_lst			*el;
}					t_v;

void				iso(t_v *v);
void				draw(t_v *v);
void				zero_angles(t_v *v);
void				line(t_lst *d0, t_lst *d1, t_v *v);

t_lst				*rot(t_lst *lst, t_v *v);
t_lst				*new_elem(char *arr, int i, int j);

#endif
