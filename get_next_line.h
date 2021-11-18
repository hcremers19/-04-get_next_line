/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:46:17 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/15 18:46:24 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_keepend(char *ptr);
char	*ft_keepstart(char *ptr);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_srch_nl(const char *str);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif