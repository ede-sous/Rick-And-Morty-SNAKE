/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:44:19 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/09 18:15:58 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	if (little[0] == '\0')
		return ((char *)big);
	x = 0;
	while (big[x] != '\0' && x < len)
	{
		i = x;
		j = 0;
		if (little[j] == big[i])
			while (little[j++] == big[i] && big[i] != '\0' && i < len)
				i++;
		if (little[j] == '\0' && little[j - 1] == big[i - 1])
			return ((char *)&big[x]);
		x++;
	}
	return (NULL);
}
