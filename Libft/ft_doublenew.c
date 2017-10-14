/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublenew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 02:15:59 by ede-sous          #+#    #+#             */
/*   Updated: 2017/02/08 21:45:37 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_doublenew(int len)
{
	char			**tmp;

	if (len == 0)
		return (NULL);
	tmp = (char**)malloc(sizeof(char*) * (len + 1));
	tmp[len] = NULL;
	return (tmp);
}
