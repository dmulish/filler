/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:52:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/11 22:19:33 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*get_coord(t_s *s, int x, int y)
{
	char	*str_x;
	char	*str_y;

	str_x = ft_itoa(x);
	str_y = ft_itoa(y);
	s->res_len = (int)ft_strlen(str_x) + (int)ft_strlen(str_y) + 2;
	s->res = ft_strnew(s->res_len + 1);
	s->res = ft_strcat(ft_strcat(ft_strcat(ft_strcat(s->res, str_y), " "),
		str_x), "\n");
	ft_memdel((void**)&str_y);
	ft_memdel((void**)&str_x);
	return (s->res);
}
