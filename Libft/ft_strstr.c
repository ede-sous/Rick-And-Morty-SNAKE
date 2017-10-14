/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:03:46 by ede-sous          #+#    #+#             */
/*   Updated: 2016/12/08 04:59:13 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		x;

	if (little[0] == '\0')
		return ((char *)big);
	x = 0;
	while (big[x] != '\0')
	{
		i = x;
		j = 0;
		if (little[j] == big[i])
		{
			while (little[j++] == big[i] && big[i] != '\0')
				i++;
			if (little[j] == '\0' && little[i - 1] == big[i - 1])
				return ((char *)&big[x]);
		}
		x++;
	}
	return (NULL);
}
