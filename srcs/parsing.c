/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:26:04 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/01 15:26:06 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		prompt(void)
{
	write(1, "$> ", 3);
}

t_lst		*new_node(char *s)
{
	t_lst *node;

	if (!(node = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(node->name = ft_strndup(s, ft_strclen(s, '='))))
		return (NULL);
	if (!(node->content = ft_strdup(s + ft_strclen(s, '=') + 1)))
		return (NULL);
	node->next = NULL;
	return (node);
}

void		lst_add(t_lst **head, t_lst *new)
{
	t_lst *tmp;

	tmp = *head;
	if (!(*head))
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		copy_env(t_shell *shell, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		lst_add(&shell->env, new_node(envp[i++]));
}

void		recup_arg(t_shell *shell)
{
	char	*str;
	char	*s;
	char	*tmp;
	t_lst	*ptr;
	int		n;

	ptr = shell->env;
	n = 0;
	s = NULL;
	prompt();
	str = ft_strnew(1024);
	read(0, str, 1023);
	str[ft_strlen(str) - 1] = 0;
	if ((tmp = ft_strchr(str, '$')))
		dollars_arg(&str, &s, tmp, ptr);
	shell->str = ft_strsplit(str, ' ');
	free(str);
	tilde_arg(shell, ptr, s);
}
