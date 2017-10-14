/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 23:26:48 by ede-sous          #+#    #+#             */
/*   Updated: 2017/02/05 03:39:33 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_sortit(char **files)
{
	int				i;
	int				j;
	char			*tmp;

	j = 1;
	while (j == 1)
	{
		j = 0;
		i = -1;
		while (files[(++i) + 1] != NULL)
			if (ft_strcmp(files[i], files[i + 1]) > 0)
			{
				tmp = files[i];
				files[i] = files[i + 1];
				files[i + 1] = tmp;
				j = 1;
			}
	}
	tmp = NULL;
	return (files);
}
