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
	while (str[i])
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = 0;
	if (dest[0] == 0)
		ft_free(&dest);
	return (dest);
}

char	*ft_keepstart(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc(i + 2, sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		dest[i++] = '\n';
	dest[i] = 0;
	if (dest[0] == 0)
		ft_free(&dest);
	return (dest);
}

char	*sub_gnl(char *r, char **stat, char *temp)
{
	r = ft_keepstart(*stat);
	temp = *stat;
	*stat = ft_keepend(temp);
	free(temp);
	if (!stat)
		ft_free(stat);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	int			rd;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*r;

	rd = BUFFER_SIZE;
	r = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX - 2)
		return (0);
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (0);
		buf[rd] = 0;
		temp = stat;
		stat = ft_strjoin(temp, buf);
		ft_free(&temp);
		if (ft_srch_nl(stat))
			break ;
	}
	return (sub_gnl(r, &stat, temp));
}
