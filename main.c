/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:54:31y nngwenya          #+#    #+#             */
/*   Updated: 2017/09/19 13:58:53 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include "minishell.h"

//displaying the env
void	displays_env(char **s)
{

	int i = -1;
	while (s[++i])
	{
		ft_putstr(s[i]);
	ft_putchar('\n');
	}
}

int		main(int argc, char **argv, char **env)
{
	char *name;
	char **args;
	extern char **environ;

	t_env main_env;
	main_env.env = env_dup(environ);
	char *input;
	while (1)
	{
		ft_putstr("\x1b[32m");
		ft_putstr("(minishell👌 )>");
		ft_putstr("\x1b[33m");
		//printf("\x1B[0;39m");
		get_input(&input);
		prompt_en(input, &main_env.env);
	}
	return (0);
}
