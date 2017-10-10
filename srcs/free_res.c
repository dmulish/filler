/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:54:21 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/10 18:39:32 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_res(t_s *s)
{
	int	i;

	i = -1;
	while (s->piece[++i])
		ft_memdel((void**)&s->piece[i]);
	ft_memdel((void**)&s->buf);
	ft_memdel((void**)&s->res);
	s->res_len = 0;
	s->x_piece = 0;
	s->y_piece = 0;
	s->e_x = 0;
	s->e_y = 0;
	s->x = 0;
	s->y = 0;
}
