/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:55:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/09 18:37:12 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int	i;
	t_s	s;

	i = -1;
	init_str(&s);
	check_usr_num(&s);
	first_read(&s);
	explor_map(&s);
	write(1, s.res, s.res_len);
	free_res(&s);
	if (get_next_line(0, &(s.buf)) > 0 && s.fl)
		draw_map(&s);
	while (++i < s.y_map)
	{
		free(s.map[i]);
		free(s.pr_map[i]);
	}
	(s.map) ? free(s.map) : 0;
	(s.pr_map) ? free(s.pr_map) : 0;
	free(&s);
	return (0);
}
