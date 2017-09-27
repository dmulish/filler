/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:32:33 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/27 19:23:05 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_s *s)
{
	s->x_piece = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
	s->y_piece = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
	s->piece = (char**)malloc((sizeof(char*) * s->y_piece) + 1);
}
