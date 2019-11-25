/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:54:23 by azeghmi           #+#    #+#             */
/*   Updated: 2018/11/13 10:54:25 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;
	char *ptr;

	if (!s1)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	str = ptr;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (str);
}
