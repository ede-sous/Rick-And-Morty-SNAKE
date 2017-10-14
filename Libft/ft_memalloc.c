/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:48:40 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/09 12:27:11 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;

	if ((tab = (char *)malloc(size)) == NULL)
		return (NULL);
	ft_memset(tab, 0, size);
	return (tab);
}
