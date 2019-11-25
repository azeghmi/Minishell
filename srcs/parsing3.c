/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:18:08 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/04 18:18:11 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_command(t_shell *shell)
{
	char *s;
	char **dir;
	char *tmp;

	if (!shell->str[0])
		return (-1);
	if (!(s = get_env(shell->env, "PATH")))
		return (write(2, "Command Not Found\n", 18));
	if (!(dir = ft_strsplit(s, ':')))
		return (write(2, "Command Not Found\n", 18));
	if (!(tmp = search_dir(dir, shell->str[0])))
		return (write(2, "Command Not Found\n", 18));
	free_tab(dir);
	exec_bin(tmp, shell);
	free(tmp);
	return (0);
}

int			get_lst_size(t_lst *lst)
{
	int cpt;

	cpt = 0;
	while (lst != NULL)
	{
		cpt++;
		lst = lst->next;
	}
	return (cpt);
}

char		**get_tab(t_lst *env)
{
	char	**tab;
	int		size;
	int		n;

	n = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (get_lst_size(env) + 2))))
		return (NULL);
	ft_bzero(tab, sizeof(char*) * (get_lst_size(env) + 2));
	while (env != NULL)
	{
		size = ft_strlen(env->content) + ft_strlen(env->name) + 2;
		if (!(tab[n] = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		ft_bzero(tab[n], size);
		ft_strcat(tab[n], env->name);
		ft_strcat(tab[n], "=");
		ft_strcat(tab[n++], env->content);
		env = env->next;
	}
	return (tab);
}

void		echo(t_shell *echo)
{
	int i;

	i = 1;
	if (echo->str[1] && ft_strcmp(echo->str[1], "-n") == 0)
	{
		if (echo->str[2])
			++i;
		else
			return ;
	}
	while (echo->str[i])
	{
		write(1, echo->str[i], ft_strlen(echo->str[i]));
		if (echo->str[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (ft_strcmp(echo->str[1], "-n"))
		write(1, "\n", 1);
}

t_lst		*new_node_senv(char *s1, char *s2)
{
	t_lst *node;

	if (!(node = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(node->name = ft_strdup(s1)))
		return (NULL);
	if (!(node->content = ft_strdup(s2)))
		return (NULL);
	node->next = NULL;
	return (node);
}
