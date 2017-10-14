/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:17:22 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/07 02:11:05 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_doubledup(char **tab)
{
	int			i;
	char		**tmp;

	if (tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
		i++;
	if ((tmp = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	tmp[i] = NULL;
	i = -1;
	while (tab[++i] != NULL)
		tmp[i] = ft_strdup(tab[i]);
	return (tmp);
}
