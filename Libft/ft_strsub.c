/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:56:52 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/09 15:12:18 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((tab = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
