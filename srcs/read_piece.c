/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:32:33 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/10 20:28:45 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_s *s)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = ft_strsplit(s->buf, ' ');
	s->x_piece = ft_atoi(tmp[2]);
	s->y_piece = ft_atoi(tmp[1]);
	s->piece = (char**)malloc(sizeof(char*) * (s->y_piece + 1));
	s->piece[s->y_piece] = NULL;
	while (tmp[++i])
		ft_memdel((void**)&tmp[i]);
}
