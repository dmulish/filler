/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_usr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:40:19 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/08 18:56:53 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_usr_num(t_s *s)
{
	s->buf = (char*)malloc((sizeof(char) * (100) + 1));
	while (get_next_line(0, &(s->buf)) > 0)
	{
		if (ft_strstr(s->buf, "exec p1") && (ft_strstr(s->buf, "[./filler]")
			|| ft_strstr(s->buf, "[./vizual_filler]")))
		{
			s->num = 'O';
			s->e_num = 'X';
			break ;
		}
		else if (ft_strstr(s->buf, "exec p2")
				&& (ft_strstr(s->buf, "[./filler]")
				|| ft_strstr(s->buf, "[./vizual_filler]")))
		{
			s->num = 'X';
			s->e_num = 'O';
			break ;
		}
	}
	if (s->buf)
		free(s->buf);
}
