/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:16:52 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/11 22:19:17 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_fill_map(t_s *s, int *i)
{
	int		j;
	char	**tmp;

	j = -1;
	if (ft_isdigit(s->buf[0]) && (*i) != -1)
	{
		tmp = ft_strsplit(s->buf, ' ');
		s->map[(*i)] = ft_strdup(tmp[1]);
		s->pr_map[(*i)] = ft_strdup(s->map[(*i)]);
		if (ft_strchr(s->map[(*i)], s->num))
		{
			s->y = (*i);
			s->x = s->x_map - ft_strlen(ft_strchr(s->map[(*i)], s->num));
		}
		else if (ft_strchr(s->map[(*i)], s->e_num))
		{
			s->e_y = (*i);
			s->e_x = s->x_map - ft_strlen(ft_strchr(s->map[(*i)], s->e_num));
		}
		while (tmp[++j])
			ft_memdel((void**)&tmp[j]);
		ft_memdel((void**)&tmp);
	}
	else if (!ft_strncmp(s->buf, "Piece", 5))
		read_piece(s);
}

void	first_read_map(t_s *s)
{
	int	i;

	i = -1;
	s->map = (char**)malloc(sizeof(char*) * (s->y_map + 1));
	s->pr_map = (char**)malloc(sizeof(char*) * (s->y_map + 1));
	s->map[s->y_map] = NULL;
	s->pr_map[s->y_map] = NULL;
	while (i <= s->y_map && get_next_line(0, &(s->buf)) > 0)
	{
		first_fill_map(s, &i);
		i++;
		ft_memdel((void**)&s->buf);
	}
	i = 0;
	s->buf = NULL;
	while (i < s->y_piece && get_next_line(0, &(s->buf)) > 0)
	{
		if (s->buf[0] == '.' || s->buf[0] == '*')
			s->piece[i++] = ft_strdup(s->buf);
		ft_memdel((void**)&s->buf);
	}
}

void	first_read(t_s *s)
{
	int		i;
	char	**tmp;

	i = -1;
	s->buf = NULL;
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (!ft_strncmp("Plateau", s->buf, 7))
		{
			tmp = ft_strsplit(s->buf, ' ');
			s->x_map = ft_atoi(tmp[2]);
			s->y_map = ft_atoi(tmp[1]);
			while (tmp[++i])
				ft_memdel((void**)&tmp[i]);
			ft_memdel((void**)&tmp);
			break ;
		}
		ft_memdel((void**)&s->buf);
	}
	ft_memdel((void**)&s->buf);
	first_read_map(s);
}
