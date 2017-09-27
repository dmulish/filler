/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:42:11 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/27 20:41:03 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_game(t_s *s)
{
	int	i;

	i = 0;
	s->buf = (char*)malloc((sizeof(char) * (s->x_map + 4)) + 1);
	while (i <= s->y_map)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (ft_strstr(s->buf, "000") || (i > 0 && i < s->y_map))
				s->map[i++] = ft_strdup((ft_strsplit(s->buf, ' '))[1]);
			else if (!ft_strncmp(s->buf, "Piece", 5))
			{
				read_piece(s);
				i = s->y_map + 1;
			}
		}
	}
	i = 0;
	while (i < s->y_piece)
	{
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (s->buf[0] == '.' || s->buf[0] == '*')
				s->piece[i++] = ft_strdup(s->buf);
		}
	}
	explor_map(s);
	// ft_putendl_fd("|||||||||||||", 2);
	// ft_putendl_fd(s->res, 2);
	// ft_putendl_fd("|||||||||||||", 2);
}
