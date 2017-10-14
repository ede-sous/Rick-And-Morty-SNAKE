/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:13:19 by ede-sous          #+#    #+#             */
/*   Updated: 2017/09/26 02:53:40 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int value)
{
	int		i;
	int		len;
	char	*tab;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return ((char*)s2);
	else if (!s2 && s1)
		return ((char*)s1);
	len = ft_strlen(s1);
	i = ft_strlen(s2);
	if ((tab = (char *)malloc(sizeof(char *) * (len + i + 1))) == NULL)
		return (NULL);
	i = -1;
	len = 0;
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	while (s2[len] != '\0')
		tab[i++] = s2[len++];
	tab[i] = '\0';
	(value == 1 || value == 3 ? ft_strdel((char**)&s1) : 0);
	(value == 2 || value == 3 ? ft_strdel((char**)&s1) : 0);
	return (tab);
}
