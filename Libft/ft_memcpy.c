/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:41:10 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/10 04:41:53 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tab1;
	char	*tab2;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	tab1 = (char *)src;
	tab2 = (char *)dst;
	while (i < n)
	{
		tab2[i] = tab1[i];
		i++;
	}
	return (tab2);
}
