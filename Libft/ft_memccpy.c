/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:44:33 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/10 19:16:52 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;
	unsigned char	*clone;

	i = 0;
	tab = (unsigned char*)src;
	clone = (unsigned char*)dst;
	while (i < n)
	{
		clone[i] = tab[i];
		if (tab[i] == (unsigned char)c)
			return ((void*)&clone[i + 1]);
		i++;
	}
	return (NULL);
}
