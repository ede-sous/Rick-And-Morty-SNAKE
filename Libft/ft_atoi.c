/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:26:39 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/06 23:23:17 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		s;

	s = 1;
	i = 0;
	nb = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == 45)
	{
		s = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	else if (str[i] < 48 || str[i] > 57)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
		nb = nb * 10 + (str[i++] - 48);
	return (s * nb);
}
