/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:55:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/05 17:49:37 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_str(t_s *s)
{
	s = (t_s*)malloc(sizeof(t_s));
	s->buf = 0;
	s->num = 0;
	s->name_len = 0;
}

void	buf_len(t_s *s, int i, char *str1, char *str2)
{
	int	len1;
	int	len2;

	len1 = 0;
	len2 = 0;
	if (!ft_strcmp("-p1", str1))
		len1 = ft_strlen(str2);
	else if (!ft_strcmp("-p2", str1))
		len2 = ft_strlen(str2);
	if (len1 && len2)
		s->name_len = (len1 > len2) ? len1 : len2;
	else
		i++;
}

int		main(int argc, char **argv)
{
	int	i;
	t_s	s;

	i = 0;
	init_str(&s);
	while ((i < argc - 1) && !s.name_len)
		buf_len(&s, i, argv[i], argv[i + 1]);
	s.buf = (char*)malloc((sizeof(char) * (s.name_len + 16) + 1));
	while (get_next_line(1, &(s.buf)) > 0)
	{
		if (s.buf && !ft_strncmp("$$$ exec p1", s.buf, 11))
			s.num = 'o';
		else if (s.buf && !ft_strncmp("$$$ exec p2", s.buf, 11))
			s.num = 'x';
	}
	return (0);
}
