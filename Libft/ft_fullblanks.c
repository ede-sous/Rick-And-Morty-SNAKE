/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullblanks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:02:50 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/31 18:52:01 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_fullblanks(char *tab, size_t size)
{
	size_t			i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	if (size == 0)
		return (tab);
	while (i < size)
		tab[i++] = ' ';
	return (tab);
}
