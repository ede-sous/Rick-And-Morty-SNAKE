/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:04:05 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/10 04:07:45 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tab;
	unsigned char	security[len + 1];
	unsigned char	*clone;

	if (len >= 128 * 1024 * 1024)
		return (NULL);
	i = 0;
	tab = (unsigned char*)src;
	clone = (unsigned char*)dst;
	while (i < len)
	{
		security[i] = tab[i];
		i++;
	}
	security[i] = '\0';
	i = 0;
	while (i < len)
	{
		clone[i] = security[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}
