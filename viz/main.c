/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:55:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/08 20:18:54 by dmulish          ###   ########.fr       */
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
	write(1, s.res, s.res_len);
	free_res(&s);
	if (get_next_line(0, &(s.buf)) > 0 && s.fl)
		draw_map(&s);
	while (++i < s.y_map)
	{
		free(s.map[i]);
		free(s.pr_map[i]);
	}
	free(s.map);
	free(s.pr_map);
	return (0);
}
