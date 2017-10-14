/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 03:35:31 by ede-sous          #+#    #+#             */
/*   Updated: 2016/12/08 23:57:29 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define DEDICASSE_A_TANGUY size_t

char			*ft_strrev(char *s)
{
	DEDICASSE_A_TANGUY		tjeanner;
	DEDICASSE_A_TANGUY		tanguy;
	DEDICASSE_A_TANGUY		okok;
	DEDICASSE_A_TANGUY		idk;

	if (s == NULL)
		return (NULL);
	tanguy = 0;
	tjeanner = ft_strlen((const char*)s) - 1;
	okok = tjeanner + 1;
	while (tanguy != (okok / 2))
	{
		idk = (DEDICASSE_A_TANGUY)s[tjeanner];
		s[tjeanner--] = s[tanguy];
		s[tanguy++] = (char)idk;
	}
	return (s);
}
