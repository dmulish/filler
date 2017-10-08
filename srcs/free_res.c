/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:54:21 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/07 17:55:12 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_res(t_s *s)
{
	int	i;

	i = -1;
	if (s->piece)
	{
		while (++i < s->y_piece)
			free(s->piece[i]);
		free(s->piece);
	}
	if (s->buf)
		free(s->buf);
	if (s->res)
		free(s->res);
	s->res_len = 0;
	s->x_piece = 0;
	s->y_piece = 0;
	s->e_x = 0;
	s->e_y = 0;
	s->x = 0;
	s->y = 0;
}
