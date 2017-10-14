/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:30:54 by ede-sous          #+#    #+#             */
/*   Updated: 2016/12/08 05:22:07 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		x;

	if (s == NULL)
		return (NULL);
	i = 0;
	x = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[x] == ' ' || s[x] == '\n' || s[x] == '\t' || s[x] == '\0')
			&& x != 0)
		x--;
	return (ft_strsub(s, (unsigned int)i, x - i + 1));
}
