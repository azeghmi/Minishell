/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:32:14 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/04 16:33:03 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char *str, int start, int len)
{
	char		*s;
	int			i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(char) * len + 1)) || !str)
		return (NULL);
	while (len--)
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}
