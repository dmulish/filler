/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:56:16 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/14 12:03:01 by dmulish          ###   ########.fr       */
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

#include <fcntl.h>

typedef struct	s_s
{
	int			x_map;
	int			y_map;
	int			x_piece;
	int			y_piece;
	int			res_len;
	int			name_len;
	char		num;
	char		*buf;
	char		*res;
	char		**map;
	char		**piece;
}				t_s;

void			read_game(t_s *s);
void			explor_map(t_s *s);

#endif
