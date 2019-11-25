/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:16:56 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/12 15:20:26 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_lst(t_lst *env)
{
	t_lst *tmp;

	while (env != NULL)
	{
		tmp = env->next;
		if (env->name)
			free(env->name);
		if (env->content)
			free(env->content);
		free(env);
		env = tmp;
	}
}

void		b_exit(t_shell *shell)
{
	shell->exit = 1;
}

char		*get_env(t_lst *env, char *id)
{
	while (env != NULL)
	{
		if (ft_strcmp(env->name, id) == 0)
			return (env->content);
		env = env->next;
	}
	return (NULL);
}

char		*search_dir(char **dir, char *name)
{
	char			*tmp;
	char			*c;
	int				ret;

	while (*dir)
	{
		if (!(tmp = ft_strjoin(*dir, "/")).
			|| !(c = ft_strjoin(tmp, name)))
			return (NULL);
		if ((ret = access(c, X_OK) == 0))
		{
			free(tmp);
			return (c);
		}
		free(tmp);
		free(c);
		dir++;
	}
	return (NULL);
}

void		exec_bin(char *tmp, t_shell *shell)
{
	pid_t	pid;
	char	**tab;

	tab = get_tab(shell->env);
	pid = fork();
	if (pid == 0)
	{
		execve(tmp, shell->str, tab);
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
	free_tab(tab);
}
