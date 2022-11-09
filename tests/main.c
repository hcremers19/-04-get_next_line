/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:53:39 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/22 18:53:41 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd = open("tests/prive_ne_pas_ouvrir.txt", O_RDONLY) ;
	char	*gnl;

	while ((gnl = get_next_line(fd)))
	{
		printf("%s", gnl);
		free(gnl);
		gnl = NULL;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%s", get_next_line(0));
	return (0);
}
*/
