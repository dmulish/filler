/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:16:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/21 18:40:26 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_read_piece(t_s *s)
{
	if (!ft_strncmp(s->buf, "Piece", 5))
	{
		s->x_piece = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
		s->y_piece = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
		s->piece = (char**)malloc((sizeof(char) * s->y_piece) + 1);
	}
}

void	first_read_map(t_s *s)
{
	int		i;
	FILE	*f;

	f = fopen("file1.txt", "w");
	i = -1;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	s->map = (char**)malloc((sizeof(char*) * s->y_map) + 1);
	while (i <= s->y_map)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (ft_isdigit(s->buf[0]) && i != -1)
			{
				s->map[i] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
				fprintf(f, "%d	%s\n", i, (ft_strsplit(s->buf, ' '))[1]);
			}
			else
				first_read_piece(s);
		}
		i++;
	}
	i = -1;
	while (++i < s->y_piece)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (s->buf[0] == '.' || s->buf[0] == '*')
			{
				s->piece[i] = ft_strdup(s->buf);
				fprintf(f, "%d	%s\n", i, s->piece[i]);
			}
		}
	}
	fclose(f);
	free(s->buf);
	explor_map(s);
}

void	first_read(t_s *s)
{
	s->buf = (char*)malloc((sizeof(char) * 20) + 1);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (!ft_strncmp("Plateau", s->buf, 7))
		{
			s->x_map = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
			s->y_map = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
			break ;
		}
	}
	free(s->buf);
	first_read_map(s);
}
