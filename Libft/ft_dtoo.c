/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:59:22 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/12 01:45:43 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

static char			*ft_change(int n, size_t i)
{
	char	*tab;

	tab = ft_strnew(i);
	tab[i--] = '\0';
	while (n != 0)
	{
		tab[i] = n % 8 + '0';
		n /= 8;
		i--;
	}
	return (tab);
}

int					ft_dtoo(int nb)
{
	size_t		i;
	int			z;
	char		*tab;

	z = nb;
	i = 0;
	while (z != 0)
	{
		z /= 8;
		i++;
	}
	tab = ft_change(nb, i);
	z = ft_atoi(tab);
	free(tab);
	return (z);
}
