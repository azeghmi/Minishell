/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:53:22 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/04 18:53:24 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char*str;
	int i;
	int	j;

	str = (char*)s1;
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (n > 0 && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
		n--;
	}
	str[i] = '\0';
	return (str);
}
