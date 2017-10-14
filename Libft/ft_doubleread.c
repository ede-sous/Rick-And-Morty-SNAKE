/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:03:03 by ede-sous          #+#    #+#             */
/*   Updated: 2016/12/13 01:07:09 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_doubleread(char *file)
{
	size_t		i;
	int			fd;
	char		**tab;
	char		*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		i++;
	}
	close(fd);
	if ((tab = (char**)malloc(sizeof(char*) * (i + 1))) == NULL
			|| (fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		tab[i++] = ft_strdup(line);
		free(line);
	}
	close(fd);
	tab[i] = NULL;
	return (tab);
}
