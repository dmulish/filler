/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:32:33 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/09 17:48:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_tmp(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	read_piece(t_s *s)
{
	char	**tmp;

	tmp = ft_strsplit(s->buf, ' ');
	s->x_piece = ft_atoi(tmp[2]);
	s->y_piece = ft_atoi(tmp[1]);
	s->piece = (char**)malloc((sizeof(char*) * s->y_piece) + 1);
	free_tmp(tmp);
}
