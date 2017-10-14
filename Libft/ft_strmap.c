/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:25:57 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/09 15:34:34 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if ((tab = (char *)malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		tab[i] = (*f)(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
