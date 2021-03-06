/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:15:58 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/26 15:56:28 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execve_func(char **path, char **env)
{
	pid_t	store;
	pid_t	child;
	char	*prog;

	prog = add_path(path[0], env);
	if (access(prog, X_OK) == 0)
	{
		child = fork();
		if (child == 0)
		{
			execve(prog, path, env);
			ft_putendl("FAILED TO RUN EXECVE");
			exit(-1);
		}
		else if (child > 0)
			wait(&store);
		else
			ft_putendl("FAILED TO FORK");
	}
	else
	{
		ft_putstr("command not found: ");
		ft_putendl(path[0]);
	}
}
