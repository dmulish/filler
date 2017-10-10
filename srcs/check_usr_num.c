/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_usr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:40:19 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/10 20:33:52 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_usr_func(t_s *s)
{
	s->num = 'O';
	s->e_num = 'X';
}

void	check_usr_num(t_s *s)
{
	while (1)
	{
		(!s->buf) ? s->buf = (char*)malloc((sizeof(char) * (100) + 1)) : 0;
		if (get_next_line(0, &(s->buf)) > 0)
		{
			if (ft_strstr(s->buf, "exec p1") && (ft_strstr(s->buf, "[./filler]")
			|| ft_strstr(s->buf, "[./vizual_filler]")))
			{
				check_usr_func(s);
				break ;
			}
			else if (ft_strstr(s->buf, "exec p2")
			&& (ft_strstr(s->buf, "[./filler]")
			|| ft_strstr(s->buf, "[./vizual_filler]")))
			{
				check_usr_func(s);
				break ;
			}
			ft_memdel((void**)&s->buf);
		}
		else
			break ;
	}
	ft_memdel((void**)&s->buf);
}
