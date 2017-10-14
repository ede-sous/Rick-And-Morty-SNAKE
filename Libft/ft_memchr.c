/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:34:41 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/10 04:04:55 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)s;
	while (n != 0)
	{
		if (tab[i] == (unsigned char)c)
			return (&tab[i]);
		i++;
		n--;
	}
	return (NULL);
}
