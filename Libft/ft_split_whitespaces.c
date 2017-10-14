/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:46:26 by ede-sous          #+#    #+#             */
/*   Updated: 2017/03/26 05:40:14 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_whitespaces(const char *s)
{
	int				i;
	int				x;
	unsigned char	*tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	x = 0;
	tab = (unsigned char*)s;
	while (s[i] != '\0')
	{
		while ((s[i] <= 32 || s[i] == 127) && s[i] != '\0')
			i++;
		while (s[i] > 32 && s[i] != 127 && s[i] != '\0')
			tab[x++] = s[i++];
	}
	tab[x] = '\0';
	return ((char*)tab);
}
