/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:54:31y nngwenya          #+#    #+#             */
/*   Updated: 2017/09/12 16:55:17 by nngwenya         ###   ########.fr       */
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
		printf("%s\n", s[i]);
}

int		main()
{
	char *name;
	char **args;
	extern char **environ;
	printf("%s" , environ[0]);
	t_env main_env;
	main_env.env = env_dup(environ);
	char *input;
	while (1)
	{
		ft_putstr("$> ");
		get_input(&input);
		prompt_en(main_env.env, input);
		execve_func(name, args);
	}
	return (0);
}
