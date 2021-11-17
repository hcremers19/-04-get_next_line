#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
	s = s2;
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (void *)malloc(size * count);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	int		i1;
	int		i2;
	char	*p;

	i = 0;
	i1 = 0;
	i2 = 0;
	if (!s1)
		return (0);
	p = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!p)
		return (0);
	while (i < ft_strlen((char *)s1))
		p[i++] = s1[i1++];
	while (i < ft_strlen((char *)s1) + ft_strlen((char *)s2))
		p[i++] = s2[i2++];
	p[i] = '\0';
	return (p);
}
