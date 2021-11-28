/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:36:18 by hcremers          #+#    #+#             */
/*   Updated: 2021/11/28 20:36:57 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

char	*ft_calloc(size_t count, size_t size);
void	ft_free(char **ptr);
char	*ft_keepend(char *ptr);
char	*ft_keepstart(char *ptr);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_srch_nl(const char *str);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
