/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 05:04:27 by ede-sous          #+#    #+#             */
/*   Updated: 2016/12/09 05:40:25 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_epur(char *s)
{
	size_t		i;
	size_t		x;
	char		*tmp;

	if (s == NULL)
		return (NULL);
	tmp = ft_strdup(s);
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		while (s[i] > 32 && s[i] != 127 && s[i] != '\0')
			tmp[x++] = s[i++];
		while ((s[i] <= 32 || s[i] == 127) && s[i] != '\0')
			i++;
		if (s[i] != '\0' && x != 0)
			tmp[x++] = ' ';
	}
	tmp[x] = '\0';
	free(s);
	s = ft_strdup(tmp);
	free(tmp);
	return (s);
}
