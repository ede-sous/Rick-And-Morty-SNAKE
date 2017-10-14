/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 07:31:05 by ede-sous          #+#    #+#             */
/*   Updated: 2017/09/26 02:53:57 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		change_line(char **tmp, char **stock, char *test, int i)
{
	char	*map;

	if (*stock != NULL)
		ft_strdel(&*stock);
	ft_strdel(&*tmp);
	map = ft_strsub(test, (i + 1), (ft_strlen(test) - i - 1));
	test[i] = '\0';
	*tmp = ft_strdup(test);
	ft_strdel(&test);
	*stock = ft_strdup(map);
	ft_strdel(&map);
}

static int		check_line(char **tmp, char **stock, int y)
{
	int		i;
	char	*test;

	i = -1;
	test = (*stock ? ft_strjoin(*stock, *tmp, 0) : ft_strdup(*tmp));
	while (test[++i] != '\0')
		if (test[i] == '\n')
		{
			change_line(tmp, stock, test, i);
			return (1);
		}
	if (y == 0 && test[0] != '\0')
	{
		ft_strdel(&*tmp);
		*tmp = ft_strdup(test);
		ft_strdel(&test);
		if (*stock)
			ft_strdel(&*stock);
		return (1);
	}
	ft_strdel(&*stock);
	ft_strdel(&test);
	return (0);
}

static int		get_line(int fd, char **tmp)
{
	int		ret;
	char	buff[BUFF_SIZE + 2];
	char	*bonga;
	char	*test;

	if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	bonga = buff;
	if (ret < BUFF_SIZE && ret != 0 && bonga[ret - 1] != '\n')
	{
		bonga[ret] = '\n';
		bonga[ret + 1] = '\0';
	}
	else
		bonga[ret] = '\0';
	test = ft_strjoin(*tmp, bonga, 0);
	ft_bzero(bonga, BUFF_SIZE);
	ft_strdel(&*tmp);
	*tmp = ft_strdup(test);
	ft_strdel(&test);
	if (ret == 0)
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int				y;
	char			*tmp;
	static char		*stock = NULL;

	if (line == NULL || BUFF_SIZE < 1 || BUFF_SIZE > 8385030)
		return (-1);
	if ((tmp = (char*)malloc(BUFF_SIZE + 1)) == NULL)
		return (-1);
	ft_bzero(tmp, BUFF_SIZE);
	if (stock == NULL)
		y = get_line(fd, &tmp);
	else
		y = 1;
	while (y == 1 && check_line(&tmp, &stock, y) == 0)
		if ((y = get_line(fd, &tmp)) == -1)
			return (-1);
	if (y == 0)
		y = check_line(&tmp, &stock, y);
	*line = ft_strdup(tmp);
	ft_strdel(&tmp);
	if (y == 0)
		return (0);
	return (1);
}
