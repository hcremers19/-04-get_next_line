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
	dest[i++] = '\n';
	dest[i] = 0;
	if (str[0] == '\n' && str[1] == 0)
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*rtn;
	size_t	i;

	rtn = (char *)malloc(size * count);
	if (!rtn)
		return (0);
	i = -1;
	while (++i < count)
		rtn[i] = 0;
	return (rtn);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		j;
	size_t	len;

	if (!s1 && !s2)
		return (0);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[len] = s2[j];
		len++;
		j++;
	}
	str[len] = 0;
	return (str);
}

int	ft_srch_nl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (0);
}
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	int			rd;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*r;

	rd = BUFFER_SIZE;
	r = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 2)
		return (0);
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (0);
		buf[rd] = 0;
		temp = stat;
		stat = ft_strjoin(temp, buf);
		free(temp);
		if (ft_srch_nl(stat))
			break ;
	}
	r = ft_keepstart(stat);
	temp = stat;
	stat = ft_keepend(temp);
	free(temp);
	if (!*stat)
	{
		stat = NULL;
		free(stat);
	}
	return (r);
}
