/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:55:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/08 17:45:30 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_it(t_s *s)
{
	int	j;

	j = 0;
	first_read(s);
	write(1, s->res, s->res_len);
	free_res(s);
	while (++j)
	{
		if (read_game(s) > 0)
		{
			explor_map(s);
			write(1, s->res, s->res_len);
		}
		else
			break ;
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
	i = -1;
	while (++i < s.y_map)
	{
		free(s.map[i]);
		free(s.pr_map[i]);
	}
	free(s.map);
	free(s.pr_map);
	return (0);
}
