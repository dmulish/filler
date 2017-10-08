/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:56:16 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/08 17:47:57 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "fdf.h"

typedef struct	s_s
{
	int			x;
	int			y;
	int			fl;
	int			e_x;
	int			e_y;
	int			x_map;
	int			y_map;
	int			x_piece;
	int			y_piece;
	int			res_len;
	int			name_len;
	char		num;
	char		e_num;
	char		*buf;
	char		*res;
	void		*win;
	void		*mlx;
	char		**map;
	char		**piece;
	char		**v_map;
	char		**pr_map;
	t_v			*v;
}				t_s;

int				loop_hook(t_s *s);
int				read_game(t_s *s);
int				explor_map_forw(t_s *s);
int				explor_map_back(t_s *s);

void			iso(t_v *v);
void			draw(t_v *v);
void			do_it(t_s *s);
void			vizual(t_s *s);
void			draw_map(t_s *s);
void			free_res(t_s *s);
void			init_str(t_s *s);
void			draw_grid(t_s *s);
void			do_it_viz(t_s *s);
void			explor_map(t_s *s);
void			first_read(t_s *s);
void			read_piece(t_s *s);
void			zero_angles(t_v *v);
void			check_usr_num(t_s *s);
void			line(t_lst *d0, t_lst *d1, t_v *v);

char			*get_coord(t_s *s, int x, int y);

t_lst			*rot(t_lst *lst, t_v *v);
t_lst			*new_elem(char *arr, int i, int j);
t_lst			*read_map(t_lst *list, t_s *s, t_v *v);

#endif
