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

char	*ft_keepend(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	if (!dest)
		return (0);
	j = 0;
	i++;
	while (str && str[i])
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = 0;
	if (!dest || dest[0] == 0)
		ft_free(&dest);
//	printf("[dest = %p]		", *dest);
	return (dest);
}

char	*ft_keepstart(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return (0);
	j = 0;
	while (i >= j)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = 0;
	if (!dest || dest[0] == 0)
		ft_free(&dest);
	return (dest);
}

char	*sub_gnl(char **stat)
{
	char	*r;
	char	*temp;

	r = ft_keepstart(*stat);
	temp = *stat;
	*stat = ft_keepend(temp);
	ft_free(&temp);
	if (!stat)
		ft_free(stat);
//	write(1, "Z", 1);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	int			rd;
	char		*buf;

	rd = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX - 2)
		return (0);
	while (rd > 0)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (0);
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			ft_free(&buf);
			ft_free(&stat);
			return (0);
		}
		stat = ft_strjoin(stat, buf);
		if (ft_srch_nl(stat) != -1)
			break ;
	}
//	printf("Static [%s]", stat);
	return (sub_gnl(&stat));
}
/*
À faire : réviser les calloc -> s'assurer que le bon nombre de char est assigné
à chaque fois
(pas de leaks et peu de seg fault, donc les caractères superflus ne peuvent
s'afficher que parce que le code va chercher dans sa mmémoire précédente)
Checker aussi les \0 que je rajoute ou pas à la fin des chaînes allouées pour
voir si je sécurise ou pas
Et tester voir à chaque fois que je rajoute un truc si le résultat est mieux ou
moins bien 
*/