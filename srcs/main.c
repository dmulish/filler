/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:55:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/27 20:44:41 by dmulish          ###   ########.fr       */
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
	s->x_map = 0;
	s->y_map = 0;
	s->piece = 0;
	s->e_num = 0;
	s->buf = 0;
	s->res = 0;
	s->map = 0;
	s->num = 0;
	s->x = 0;
	s->y = 0;
}

void	buf_len(t_s *s, char *param, char *usrname)
{
	if (!ft_strcmp("-p1", param))
	{
		if (ft_strstr(usrname, "[filler]") || ft_strstr(usrname, "[./filler]"))
			s->name_len = ft_strlen(usrname);
	}
	else if (!ft_strcmp("-p2", param))
	{
		if (ft_strstr(usrname, "[filler]") || ft_strstr(usrname, "[./filler]"))
			s->name_len = ft_strlen(usrname);
	}
}

void	check_usr_num(t_s *s)
{
	s->buf = (char*)malloc((sizeof(char) * (s->name_len + 16) + 1));
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (ft_strstr(s->buf, "exec p1") && ft_strstr(s->buf, "[./filler]"))
		{
			s->num = 'O';
			s->e_num = 'X';
			break ;
		}
		else if (ft_strstr(s->buf, "exec p2") &&
			ft_strstr(s->buf, "[./filler]"))
		{
			s->num = 'X';
			s->e_num = 'O';
			break ;
		}
	}
	if (s->buf)
		free(s->buf);
}

void	free_res(t_s *s)
{
	int	i;

	i = -1;
	if (s->piece)
	{
		while (++i < s->y_piece)
			free(s->piece[i]);
		free(s->piece);
	}
	if (s->buf)
		free(s->buf);
	if (s->res)
		free(s->res);
	s->res_len = 0;
	s->x_piece = 0;
	s->y_piece = 0;
	s->x = 0;
	s->y = 0;
}

int		main(int argc, char **argv)
{
	int	i;
	t_s	s;

	i = -1;
	init_str(&s);
	while ((++i < argc - 1))
		buf_len(&s, argv[i], argv[i + 1]);
	check_usr_num(&s);
	first_read(&s);
	write(1, s.res, s.res_len);
	free_res(&s);
	while (1)
	{
		read_game(&s);
		write(1, s.res, s.res_len);
		free_res(&s);
	}
	return (0);
}
