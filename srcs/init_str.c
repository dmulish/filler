/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 17:17:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/09 18:37:19 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_str(t_s *s)
{
	s = (t_s*)malloc(sizeof(t_s));
	s->name_len = 0;
	s->x_piece = 0;
	s->y_piece = 0;
	s->res_len = 0;
	s->pr_map = 0;
	s->x_map = 0;
	s->y_map = 0;
	s->piece = 0;
	s->e_num = 0;
	s->buf = 0;
	s->res = 0;
	s->map = 0;
	s->num = 0;
	s->e_x = 0;
	s->e_y = 0;
	s->fl = 0;
	s->x = 0;
	s->y = 0;
}
