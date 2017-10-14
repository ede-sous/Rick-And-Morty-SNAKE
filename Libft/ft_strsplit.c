/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:14:03 by ede-sous          #+#    #+#             */
/*   Updated: 2016/11/09 13:53:43 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**is_split(char **tab, const char *s, char c, int count)
{
	int		i;
	int		start;
	int		x;

	i = 0;
	start = 0;
	x = 0;
	while (s[i++] != '\0' && x < count)
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[x++] = ft_strsub(s, start, i - start);
		}
	tab[x] = NULL;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		count;

	if (s == 0)
		return (NULL);
	count = ft_count(s, c);
	tab = NULL;
	if ((tab = (char**)malloc(sizeof(char*) * (count + 1))) == NULL)
		return (NULL);
	tab = is_split(tab, s, c, count);
	return (tab);
}
