/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:15:20 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/09 19:37:16 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_lst	*push_back(t_lst *old, t_lst *new1)
{
	t_lst	*cur;

	if (!old)
		return (new1);
	cur = old;
	while (cur->next)
		cur = cur->next;
	cur->next = new1;
	return (old);
}

t_lst	*fill_cord(char **arr, int j, t_v *v)
{
	int		i;
	t_lst	*lst;

	i = -1;
	lst = NULL;
	if (v->max_x == 0)
	{
		while (arr[++i])
			lst = push_back(lst, new_elem(arr[i], i, j));
		v->max_x = i - 1;
	}
	else
	{
		while (arr[++i] && i <= v->max_x)
			lst = push_back(lst, new_elem(arr[i], i, j));
		if (i <= v->max_x)
			return (0);
	}
	return (lst);
}

t_lst	*read_map(t_lst *list, t_s *s, t_v *v)
{
	int		j;
	char	**arr;

	j = -1;
	list = NULL;
	while (++j < s->y_map)
	{
		arr = ft_strsplit(s->v_map[j], ' ');
		list = push_back(list, fill_cord(arr, j, v));
		if (fill_cord(arr, j, v) == 0)
		{
			(arr) ? free(arr) : 0;
			return (0);
		}
		(arr) ? free(arr) : 0;
	}
	v->max_y = j;
	return (list);
}
