/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:47:55 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/04 18:48:00 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						ft_strcmp(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (*(s1 - 1) - *(s2 - 1));
	return ((*s1) - (*s2));
}