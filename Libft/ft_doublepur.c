/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublepur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:25:19 by ede-sous          #+#    #+#             */
/*   Updated: 2016/12/10 22:27:21 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_doublepur(char **tab)
{
	int		i;

	if (tab == NULL)
		return (NULL);
	i = -1;
	while (tab[++i] != NULL)
		tab[i] = ft_epur(tab[i]);
	tab[i] = NULL;
	return (tab);
}
