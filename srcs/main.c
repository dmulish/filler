/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:55:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/11 00:25:53 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_it(t_s *s)
{
	first_read(s);
	explor_map(s);
	write(1, s->res, s->res_len);
	free_res(s);
	while (read_game(s))
	{
		explor_map(s);
		write(1, s->res, s->res_len);
		free_res(s);
	}
}

int		main(void)
{
	int	i;
	t_s	s;

	i = -1;
	init_str(&s);
	check_usr_num(&s);
	do_it(&s);
	while (++i < s.y_map)
	{
		ft_memdel((void**)&s.map[i]);
		ft_memdel((void**)&s.pr_map[i]);
	}
	ft_memdel((void**)&s.map);
	ft_memdel((void**)&s.pr_map);
	return (0);
}
