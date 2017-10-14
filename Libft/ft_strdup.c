/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:27:33 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/10 00:07:57 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if ((tab = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
