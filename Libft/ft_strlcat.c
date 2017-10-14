/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:09:31 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/10 19:05:04 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = ft_strlen(dst);
	x = ft_strlen(src);
	if (i >= size)
		return (x + size);
	ft_strncat(dst, src, size - i - 1);
	return (i + x);
}
