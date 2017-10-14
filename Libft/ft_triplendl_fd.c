/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triplendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 22:37:19 by ede-sous          #+#    #+#             */
/*   Updated: 2017/01/25 20:37:18 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_triplendl_fd(int fd, char *a, char *b, char *x)
{
	ft_putstr_fd(a, fd);
	ft_putstr_fd(b, fd);
	ft_putendl_fd(x, fd);
}
