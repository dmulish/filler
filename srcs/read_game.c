/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:16:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/12 19:29:46 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_s *s, int *j)
{
	if ((*j) == -1)
	{
		s->x_piece = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
		s->y_piece = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
		s->piece = (char**)malloc((sizeof(char) * s->y_piece) + 1);
	}
	if (s->buf[0] == '.' || s->buf[0] == '*')
		s->piece[*j] = ft_strdup(s->buf);
	(*j)++;
}

void	read_map(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	s->map = (char**)malloc((sizeof(char*) * s->y_map) + 1);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (ft_isdigit(s->buf[0]) || s->buf[0] == ' ')
			s->map[i] = (ft_strsplit(s->buf, ' '))[1];
		else if (!ft_strncmp(s->buf, "Piece", 5)
			|| s->buf[0] == '.' || s->buf[0] == '*')
			read_piece(s, &j);
		else if (j == s->y_piece)
			break ;
		i++;
	}
	explor_map(s);
}

void	read_game(t_s *s)
{
	FILE	*f;

	f = fopen("file.txt", "w");
	fprintf(f, "hello1\n");
	s->buf = (char*)malloc((sizeof(char) * 20) + 1);
	while (get_next_line(0, &(s->buf)) > 0)
	{
		fprintf(f, "hello2\n");
		if (!ft_strncmp("Plateau", s->buf, 7))
		{
			s->x_map = ft_atoi(ft_strsplit(s->buf, ' ')[2]);
			s->y_map = ft_atoi(ft_strsplit(s->buf, ' ')[1]);
			fprintf(f, "x: %d, y: %d\n", s->x_map, s->y_map);
			break ;
		}
	}
	fclose(f);
	free(s->buf);
	read_map(s);
}
