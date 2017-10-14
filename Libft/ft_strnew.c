/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:00:34 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/31 18:48:53 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if ((tab = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	tab[size] = '\0';
	ft_bzero(tab, size);
	return (tab);
}
