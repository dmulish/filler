/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:55:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/07 18:24:58 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_str(t_s *s)
{
	s = (t_s*)malloc(sizeof(t_s));
	s->name_len = 0;
	s->x_piece = 0;
	s->y_piece = 0;
	s->x_map = 0;
	s->y_map = 0;
	s->buf = 0;
	s->res = 0;
	s->num = 0;
	s->fl = 1;
}

void	buf_len(t_s *s, char *param, char *usrname)
{
	printf("|||%s|%s|||0", param, usrname);
	if (!ft_strcmp("-p1", param))
		s->name_len = (ft_strstr(usrname, "filler")) ? ft_strlen(usrname) : 0;
	else if (!ft_strcmp("-p2", param))
		s->name_len = (ft_strstr(usrname, "filler")) ? ft_strlen(usrname) : 0;
	write(1, "UUUUUU", 6);
}

void	check_usr_num(t_s *s)
{
	s->buf = (char*)malloc((sizeof(char) * (s->name_len + 16) + 1));
	while (get_next_line(1, &(s->buf)) > 0)
	{
		if (ft_strstr(s->buf, "exec p1") && ft_strstr(s->buf, "filler"))
		{
			s->num = 'o';
			write(1, "OOOOOOOOOO", 10);
			break ;
		}
		else if (ft_strstr(s->buf, "exec p2") && ft_strstr(s->buf, "filler"))
		{
			s->num = 'x';
			write(1, "XXXXXXXXXX", 10);
			break ;
		}
	}
	free(s->buf);
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
	// while (s.fl)
	// {
		read_map(&s);
		// write(1, s.res, ft_strlen(s.res));
		write(1, "8 2\n", 4);
	// }
	return (0);
}
