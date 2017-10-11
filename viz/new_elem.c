/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:34:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/11 16:34:49 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_lst	*new_elem(char *arr, int i, int j)
{
	char	*col;
	t_lst	*el;

	// if (!(el = (t_lst*)malloc(sizeof(t_lst))))
	// 	return (0);
	el = malloc(sizeof(t_lst));
	el->x = i + 1;
	el->y = j + 1;
	el->z = ft_atoi(arr);
	el->x1 = 0;
	el->y1 = 0;
	el->z1 = 0;
	if ((col = ft_strchr(arr, '5')))
		el->col = 0xe7e25c;
	else if ((col = ft_strchr(arr, '6')))
		el->col = 0x365e45;
	else
		el->col = 0xe1e1e1;
	el->next = NULL;
	return (el);
}
