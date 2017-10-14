/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:28:53 by ede-sous          #+#    #+#             */
/*   Updated: 2017/02/05 01:19:16 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	tab1 = (unsigned char *)s1;
	tab2 = (unsigned char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (1);
	if (n == 0)
		return (0);
	while (tab1[i] != '\0' && tab2[i] != '\0' && i < n)
	{
		if (tab1[i] != tab2[i])
			return (tab1[i] - tab2[i]);
		i++;
	}
	if (i == n)
		return (tab1[i - 1] - tab2[i - 1]);
	return (tab1[i] - tab2[i]);
}
