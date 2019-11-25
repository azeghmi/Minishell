/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:50:17 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/05 16:44:51 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_line(const int fd, char **line)
{
	int			check;
	static char	*str;
	char		*ptr;
	char		*buff;

	if (!str)
		str = ft_strnew(1);
	buff = ft_strnew(BUFF_SIZE + 1);
	while (!ft_strchr(str, '\n') && (check = read(fd, buff, BUFF_SIZE)))
	{
		ptr = str;
		if (!(str = ft_strnjoin(ptr, buff, check)))
			return (-1);
		free((void *)ptr);
	}
	check = 0;
	while (str[check] != '\n' && str[check])
		check++;
	*line = ft_strndup(str, check);
	check += ((str[check] == '\n') ? 1 : 0);
	ptr = str;
	str = ft_strdup(ptr + check);
	free((void *)ptr);
	free((void *)buff);
	return (check > 0 ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	return (read_line(fd, line));
}
