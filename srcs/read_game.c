/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:42:11 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/21 18:58:06 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_game(t_s *s)
{
	int		i;
	FILE	*f;

	f = fopen("file.txt", "w");
	i = -1;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	s->map = (char**)malloc((sizeof(char*) * s->y_map) + 1);
	while (i < s->y_map)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (ft_isdigit(s->buf[0]) && i != -1)
			{
				s->map[i] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
				fprintf(f, "%d	%s\n", i, (ft_strsplit(s->buf, ' '))[1]);
			}
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
