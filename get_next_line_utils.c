/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:53:27 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/22 18:53:32 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
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
	ft_free(&s1);
	j = 0;
	while (s2 && s2[j])
		str[len++] = s2[j++];
	str[len] = 0;
	ft_free(&s2);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*rtn;
	size_t	i;

//	rtn = (char *)malloc(size * count);
	rtn = malloc((sizeof(size)) * count);
	if (!rtn)
		return (0);
	i = -1;
	while (++i <= count)
		rtn[i] = 0;
	return (rtn);
}

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
