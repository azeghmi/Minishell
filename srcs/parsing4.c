/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:19:16 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/04 18:19:18 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define FUN	new_node_senv("OLDPWD", exist_name_env(cd->env, "PWD")->content)

t_lst		*exist_name_env(t_lst *head, char *name)
{
	while (head != NULL)
	{
		if (ft_strcmp(head->name, name) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void		set_env(t_shell *senv)
{
	t_lst *ptr;

	if (senv->str[1] && senv->str[2])
	{
		ptr = exist_name_env(senv->env, senv->str[1]);
		if (!ptr)
			lst_add(&senv->env, new_node_senv(senv->str[1], senv->str[2]));
		else
		{
			free(ptr->content);
			ptr->content = ft_strdup(senv->str[2]);
		}
	}
}

void		unset_env(t_shell *uenv)
{
	t_lst	*head;
	t_lst	*tmp;

	head = uenv->env;
	tmp = head;
	if (ft_strcmp(head->name, uenv->str[1]) == 0)
	{
		uenv->env = head->next;
		free(head->name);
		free(head->content);
		free(head);
	}
	else
		while ((head = head->next) != NULL)
		{
			if (ft_strcmp(head->name, uenv->str[1]) == 0)
			{
				free(head->name);
				free(head->content);
				tmp->next = head->next;
				free(head);
				return ;
			}
			tmp = tmp->next;
		}
}

void		change_dir(t_shell *cd)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	char	*pwd;

	minus_arg(cd, cd->env, cd->str[1]);
	if (cd->str[1] && (access(cd->str[1], F_OK | W_OK | R_OK) != 0))
		return ((void)write(2, "Access Denied\n", 14));
	if (!(tmp = exist_name_env(cd->env, "PWD")))
	{
		if (!(pwd = getcwd(NULL, 0)))
			return ;
		lst_add(&cd->env, new_node_senv("PWD", pwd));
		tmp = exist_name_env(cd->env, "PWD");
		free(pwd);
	}
	if (!(tmp2 = exist_name_env(cd->env, "OLDPWD")))
		lst_add(&cd->env, FUN);
	else
	{
		free(tmp2->content);
		tmp2->content = ft_strdup(exist_name_env(cd->env, "PWD")->content);
	}
	chdir(!cd->str[1] ? exist_name_env(cd->env, "HOME")->content : cd->str[1]);
	free(tmp->content);
	tmp->content = getcwd(NULL, 0);
}
