/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explor_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:54:54 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/07 13:55:14 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	explor_map(t_s *s)
{
	if (s->e_y <= s->y)
	{
		if (!explor_map_forw(s))
			explor_map_back(s);
	}
	else
	{
		if (!explor_map_back(s))
			explor_map_forw(s);
	}
}
