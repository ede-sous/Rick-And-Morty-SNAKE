/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:13:53 by ede-sous          #+#    #+#             */
/*   Updated: 2017/02/05 03:28:24 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	if (!s1 || !s2)
		return (1);
	tab1 = (unsigned char *)s1;
	tab2 = (unsigned char *)s2;
	i = 0;
	while (tab1[i] != '\0' && tab2[i] != '\0')
	{
		if (tab1[i] != tab2[i])
			return (tab1[i] - tab2[i]);
		i++;
	}
	return (tab1[i] - tab2[i]);
}
