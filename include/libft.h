/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:22:57 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 16:13:25 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				**ft_strsplit(char *s, char c);
char				*ft_strsub(char *s, int start, int len);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					get_next_line(const int fd, char **line);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_isspace(char c);
int					ft_strclen(char *str, int c);
int					ft_isspace(char c);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);

#endif
