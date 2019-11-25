/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:13:22 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/04 18:13:27 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		cases(t_shell *shell)
{
	while (shell->exit == 0)
	{
		recup_arg(shell);
		if (ft_strchr(shell->str[0], '/'))
			exec_bin(shell->str[0], shell);
		else if (ft_strcmp(shell->str[0], "exit") == 0)
			b_exit(shell);
		else if (ft_strcmp(shell->str[0], "echo") == 0)
			echo(shell);
		else if (ft_strcmp(shell->str[0], "setenv") == 0)
			set_env(shell);
		else if (ft_strcmp(shell->str[0], "unsetenv") == 0)
			unset_env(shell);
		else if (ft_strcmp(shell->str[0], "cd") == 0)
			change_dir(shell);
		else if (ft_strcmp(shell->str[0], "env") == 0)
			aff_env(shell);
		else
			exec_command(shell);
		free_tab(shell->str);
	}
	free_lst(shell->env);
}

int			main(int ac, char **av, char **envp)
{
	t_shell shell;

	(void)ac;
	(void)av;
	ft_bzero(&shell, sizeof(shell));
	copy_env(&shell, envp);
	cases(&shell);
	return (0);
}
