/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:39:45 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/15 18:40:37 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{	
	char	buf[BUFFER_SIZE];
	char	*ret;
	int		rd;

	rd = read(fd, buf, BUFFER_SIZE);
	if (rd < BUFFER_SIZE)
	{
		buf[rd] = 0;
		return (buf);
	}
	else
		return (buf);
}

int	main(void)
{
	printf("%s\n", get_next_line(0));
	return (0);
}
