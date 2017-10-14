/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublelen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 02:18:56 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/07 02:21:09 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_doublelen(char **tmp)
{
	size_t				len;

	if (tmp == NULL)
		return (0);
	len = 0;
	while (tmp[len] != NULL)
		len++;
	return (len);
}
