/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:14:22 by dmulish           #+#    #+#             */
/*   Updated: 2017/09/16 18:17:08 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(void)
{
	int		fd;
	char	*buf;

	fd = open("map.txt", O_RDONLY);
	buf = (char*)malloc((sizeof(char) * 21) + 1);
	while (get_next_line(fd, &buf) > 0)
	{
		if (!ft_strncmp("Plateau", buf, 7))
		{
			printf("1. %s\n", buf);
			break ;
		}
	}
	printf("you shall not pass\n");
	while (get_next_line(fd, &buf) > 0)
		printf("2. %s\n", buf);
	close(fd);
	return (0);
}
