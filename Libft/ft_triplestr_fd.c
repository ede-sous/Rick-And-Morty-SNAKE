/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triplestr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:27:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/02/04 18:22:32 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_triplestr_fd(int fd, char *a, char *b, char *c)
{
	ft_putstr_fd(a, fd);
	ft_putstr_fd(b, fd);
	ft_putstr_fd(c, fd);
}
