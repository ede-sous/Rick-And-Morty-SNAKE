/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takeout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:18:00 by ede-sous          #+#    #+#             */
/*   Updated: 2017/02/09 02:12:37 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_takeout(char *sort, char c)
{
	int			i;
	int			x;
	char		*tmp;
	int			len;

	i = -1;
	x = 0;
	len = ft_strlen(sort);
	tmp = ft_strnew(len);
	while (sort[++i] != '\0')
		if (sort[i] != c)
			tmp[x++] = sort[i];
	tmp[x] = '\0';
	sort = ft_fullblanks(sort, len);
	sort = ft_strcpy(sort, tmp);
	free(tmp);
	return (sort);
}
