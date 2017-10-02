/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:56:16 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/02 18:15:14 by dmulish          ###   ########.fr       */
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

typedef struct	s_s
{
	int			x;
	int			y;
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
	char		**map;
	char		**piece;
}				t_s;

int				explor_map_forw(t_s *s);
int				explor_map_back(t_s *s);
int				read_game(t_s *s, int j);
int				is_match(t_s *s, int a, int b);

void			first_read(t_s *s);
void			read_piece(t_s *s);

#endif
