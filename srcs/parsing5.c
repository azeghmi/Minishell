/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:10:58 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/05 16:10:59 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		dollars_arg(char **str, char **s, char *tmp, t_lst *ptr)
{
	int n;

	n = ft_strlen(ptr->content);
	if (tmp)
	{
		tmp++;
		while (ptr)
		{
			if (ft_strncmp(tmp, ptr->name, ft_strclen(tmp, ' ')) == 0)
			{
				n = ft_strlen(ptr->content);
				if (!(*s = (char*)malloc(sizeof(char) * (ft_strlen(*str) + n))))
					return ;
				ft_bzero(*s, ft_strlen(*str) + n);
				ft_strncat(*s, *str, tmp - *str - 1);
				ft_strcat(*s, ptr->content);
				ft_strcat(*s, tmp + ft_strlen(ptr->name));
				free(*str);
				*str = *s;
				break ;
			}
			ptr = ptr->next;
		}
	}
}

void		tilde_arg(t_shell *shell, t_lst *ptr, char *s)
{
	int n;

	n = 0;
	while (shell->str[n])
	{
		if (shell->str[n][0] == '~')
		{
			ptr = exist_name_env(shell->env, "HOME");
			if (!ptr)
				break ;
			if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(shell->str[n])
				+ ft_strlen(ptr->content) + 1))))
				return ;
			ft_bzero(s, ft_strlen(shell->str[n]) + ft_strlen(ptr->content));
			ft_strcat(s, ptr->content);
			ft_strcat(s, shell->str[n] + 1);
			free(shell->str[n]);
			shell->str[n] = s;
		}
		n++;
	}
}

void		aff_env(t_shell *env)
{
	t_lst *lst;

	lst = env->env;
	while (lst != NULL)
	{
		write(1, lst->name, ft_strlen(lst->name));
		write(1, "=", 1);
		write(1, lst->content, ft_strlen(lst->content));
		write(1, "\n", 1);
		lst = lst->next;
	}
}

void		free_tab(char **str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

void		minus_arg(t_shell *shell, t_lst *ptr, char *s)
{
	int n;

	n = 0;
	while (shell->str[n])
	{
		if (shell->str[n][0] == '-')
		{
			ptr = exist_name_env(shell->env, "OLDPWD");
			if (!ptr)
				break ;
			if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(shell->str[n])
				+ ft_strlen(ptr->content) + 1))))
				return ;
			ft_bzero(s, ft_strlen(shell->str[n]) + ft_strlen(ptr->content));
			ft_strcat(s, ptr->content);
			ft_strcat(s, shell->str[n] + 1);
			free(shell->str[n]);
			shell->str[n] = s;
		}
		n++;
	}
}
