/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:24:47 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/01 15:24:49 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>

typedef struct		s_lst
{
	char			*name;
	char			*content;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_shell
{
	char			**str;
	t_lst			*env;
	int				exit;
}					t_shell;

void				free_tab(char **str);
void				recup_arg(t_shell *shell);
void				copy_env(t_shell *shell, char **envp);
void				aff_lst(t_lst *env);
void				free_lst(t_lst *env);
void				b_exit(t_shell *shell);
void				echo(t_shell *echo);
void				set_env(t_shell *senv);
void				unset_env(t_shell *uenv);
void				change_dir(t_shell *cd);
void				exec_bin(char *tmp, t_shell *shell);
void				lst_add(t_lst **head, t_lst *new);
void				dollars_arg(char **str, char **s, char *tmp, t_lst *ptr);
void				tilde_arg(t_shell *shell, t_lst *ptr, char *s);
void				aff_env(t_shell *env);
void				minus_arg(t_shell *shell, t_lst *ptr, char *s);
int					exec_command(t_shell *shell);
int					get_lst_size(t_lst *lst);
char				**get_tab(t_lst *env);
char				*get_env(t_lst *env, char *id);
char				*search_dir(char **dir, char *name);
t_lst				*exist_name_env(t_lst *head, char *name);
t_lst				*new_node(char *s);
t_lst				*new_node_senv(char *s1, char *s2);

#endif
