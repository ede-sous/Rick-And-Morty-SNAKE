/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:08:40 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/01 22:23:01 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strendl(char *line)
{
	size_t		i;
	char		*tmp;

	if (line == NULL)
		return (NULL);
	i = ft_strlen(line);
	tmp = ft_strdup(line);
	free(line);
	line = (char*)malloc(i + 2);
	line = ft_strcpy(line, tmp);
	free(tmp);
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}
