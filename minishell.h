/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:33:12 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/21 09:57:49 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFF_SIZE 1024
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"

char			**g_env;

typedef struct	s_env
{
	char		**env;
}				t_env;

void	putstring(char *s);
void	ft_echo(char **arguments);
void	displays_env(char **s);
char	**env_dup(char **env_new);
char	**ft_setenv(char **info, char *key, char *value);
void	*ft_realloc(void *ptr, int size, int new_size);
void	execute(t_env main_env, char *input);
void	get_input(char **input);
void	split_en(char **diff);
int		prompt_en(char *input, char ***env);
int		cd_function(char **data);
void	cd_execut(char *dir, int old_pwd_bool, char **envir);
int		cd_builtin(char *dir, char **envir);
char	*ft_getenv(char *env_str, char **environ);
void	execve_func(char **path, char **env);
char	*add_path(char *prog, char **environ);
char	**unset_env(char **name, char *key);

#endif
