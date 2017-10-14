/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:19:26 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/30 04:11:39 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcut(char *tab, int start, int len)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = ft_strnew(len);
	while (tab[start] != '\0' && i < len)
		tmp[i++] = tab[start++];
	tmp[i] = '\0';
	if ((void*)tab)
		free(tab);
	return (tmp);
}
