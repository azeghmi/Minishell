/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:41:25 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/04 16:41:34 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_index
{
	int i;
	int j;
	int k;
}				t_index;

static	int		ft_nbw(char *s, char c)
{
	int i;
	int nbw;

	i = 0;
	nbw = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\t')
		{
			i++;
			nbw++;
		}
		else
		{
			while ((s[i] != c || s[i] == '\t') && s[i])
				i++;
			nbw++;
		}
	}
	return (nbw);
}

int				quote(char **tab, char *s, char c, t_index *idx)
{
	while (s[idx->i])
		if (s[idx->i] == c || s[idx->i] == '\t')
			idx->i++;
		else if (s[idx->i] == '"')
		{
			idx->i++;
			if (s[idx->i] != '"')
			{
				idx->j = idx->i;
				while (s[idx->i] && s[idx->i] != '"')
					idx->i++;
				if (!(tab[idx->k++] = ft_strsub(s, idx->j, idx->i - idx->j)))
					return (-1);
			}
		}
		else
		{
			idx->j = idx->i;
			while ((s[idx->i] != c || s[idx->i] == '\t') && s[idx->i])
				idx->i++;
			if (!(tab[idx->k++] = ft_strsub(s, idx->j, idx->i - idx->j)))
				return (-1);
		}
	return (0);
}

char			**ft_strsplit(char *s, char c)
{
	char	**tab;
	t_index index;

	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_nbw(s, c) + 1))))
		return (NULL);
	tab[ft_nbw(s, c)] = 0;
	ft_bzero(&index, sizeof(index));
	if (quote(tab, s, c, &index) < 0)
		return (NULL);
	tab[index.k] = NULL;
	return (tab);
}
