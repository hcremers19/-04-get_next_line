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
/*
Tant que rd == BUFFER_SIZE, on envoie le contenu de buf dans ret.
Il faut d'abord avoir alloué l'espace en question dans ret pour y faire rentrer
buf.
Une fois que rd < BUFFER_SIZE, on envoie le contenu de buf dans ret mais on a-
joute un \0 à la fin de buf.
Peut-on simplement insérer un \0 après le dernier caractère ou doit-on vraiment
allouer juste la mémoire correspondante à buf ? Et remplir le reste de la mé-
moire allouée avec des \0 ?

Il faudra ensuite insérer le fait que si read tombe sur un \n, il est censé
s'arrêter là, et get_next_line renverra la ligne jusque là.
Ne pas oublier non plus de renvoyer NULL si la fonction n'a rien à lire.
*/