/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:06:51 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/20 16:57:47 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	cd_execut(char *dir, int old_pwd_bool, char **envir)
{
	char	*curr_dir;
	char	buff[BUFF_SIZE];
	char	*oldpwd;

	oldpwd = ft_getenv("$OLDPWD", envir);
	curr_dir = getcwd(buff, BUFF_SIZE);
	ft_setenv(envir, "OLDPWD", curr_dir);
	if (!chdir(dir))
	{
		if (old_pwd_bool)
			ft_putendl(oldpwd);
	}
	else
	{
		ft_putstr("cd :");
		if (access(dir, F_OK))
			ft_putstr(" no such file or directory: ");
		else if (access(dir, R_OK))
			ft_putstr(" permission denied: ");
		else
			ft_putstr(" not a directory");
		ft_putstr(dir);
		ft_putchar('\n');
	}
}

int		cd_builtin(char *dir, char **envir)
{
	char *home;

	home = ft_getenv("$HOME", envir);
	if	(dir[1] && dir[2])
		ft_putendl("cd : too many arguments");
	else if (!dir[1] || !ft_strcmp(&dir[1], "--"))
	{
		cd_execut(home, 0, envir);
		return (1);
	}
	else if (dir[1] == '-')
	{
		home = ft_getenv("$OLDPWD", envir);
		cd_execut(home, 1, envir);
		return (1);
	}
	else
		cd_execut(dir, 0, envir);
	return (1);
}
