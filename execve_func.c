/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:15:58 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/19 17:37:04 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <unistd.h>
//copies the process id of a program
void	execve_func(char **path, char **env)
{
	pid_t store;
	pid_t child;
	char *prog;
	prog = add_path(path[0], env);
	if (prog)
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
		ft_putstr("Seriously Now ?: ");
		ft_putendl(path[0]);
	}
}
