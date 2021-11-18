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

char	*ft_keepend(char *ptr)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (ptr && ptr[i] && ptr[i] != '\n')
		i++;
	dest = ft_calloc(ft_strlen(ptr) - i + 1, sizeof(char));
	if (!dest)
		return (0);
	j = 0;
	i++;
	while (ptr[i])
	{
		dest[j] = ptr[i];
		j++;
		i++;
	}
	dest[j] = 0;
	return (dest);
}

char	*ft_keepstart(char *ptr)
{
	int		i;
	char	*dest;

	i = 0;
	while (ptr && ptr[i] && ptr[i] != '\n')
		i++;
	dest = ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		dest[i] = ptr[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		j;
	size_t	len;

	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	j = 0;
	while (s2[j])
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
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	int			rd;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*r;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	while (BUFFER_SIZE > 0)
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
		free(stat);
		stat = NULL;
	}
	return (r);
}
