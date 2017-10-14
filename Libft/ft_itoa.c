/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 05:12:11 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/12 01:48:51 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*is_val(int n, int i, int s)
{
	char	*tab;

	n *= s;
	if ((tab = (char *)malloc(i + 1)) == NULL)
		return (NULL);
	tab[i--] = '\0';
	while (n != 0)
	{
		tab[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (s == -1)
		tab[0] = '-';
	return (tab);
}

char			*ft_itoa(int n)
{
	int		i;
	int		s;
	int		x;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
		i++;
	if (n == 0)
		return (ft_strdup("0"));
	s = ft_isval(n);
	x = s * n;
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	return (is_val(n, i, s));
}
