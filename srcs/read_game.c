/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:16:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/15 18:24:47 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_s *s, int *j)
{
	if (!ft_strncmp(s->buf, "Piece", 5) && (*j) == 0)
	{
		s->x_piece = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
		s->y_piece = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
		s->piece = (char**)malloc((sizeof(char) * s->y_piece) + 1);
	}
	else if (s->buf[0] == '.' || s->buf[0] == '*')
		s->piece[(*j)++] = ft_strdup(s->buf);
}

void	read_map(t_s *s)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	s->map = (char**)malloc((sizeof(char*) * s->y_map) + 1);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (ft_isdigit(s->buf[0]) == 1)
			s->map[i++] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
		else
			read_piece(s, &j);
		if (s->y_piece && j == s->y_piece)
			break ;
	}
	free(s->buf);
	explor_map(s);
}

void	read_game(t_s *s)
{
	s->buf = (char*)malloc((sizeof(char) * 20) + 1);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (!ft_strncmp("Plateau", s->buf, 7))
		{
			s->x_map = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
			s->y_map = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
		}
		if (s->x_map != 0 && s->y_map != 0)
			break ;
	}
	free(s->buf);
	read_map(s);
}
