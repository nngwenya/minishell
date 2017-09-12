/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:15:58 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/12 16:39:28 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <unistd.h>

void	execve_func(char *path, char **args)
{
	pid_t child;
	t_env main_env;

	child = fork();
	if (child == 0)
	{
		execve(path, args, main_env.env);
		ft_putstr("Return not expected. Must be an execve error");
	}
	else if (child == -1)
	{
		ft_putstr("fork error");
		exit(-1);
	}
	else
		wait (0);
}
