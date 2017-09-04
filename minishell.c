/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  y: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:54:31y nngwenya          #+#    #+#             */
/*   Updated: 2017/09/04 12:08:02 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include "minishell.h"

void	displays_env(char **s)
{

	int i = -1;
	while (s[++i])
		printf("%s\n", s[i]);
}

int		main()
{
	extern char **environ;
//	t_env main_env;
	char	**data;
//	main_env.env = env_dup(environ);
//	main_env.env = set_env(main_env.env, "shado", "gwen");
	//displays_env(main_env.env);
	char *input;
	while (1)
	{
		ft_putstr("$> ");
		get_input(&input);
		data = ft_strsplit(input, ' ');
//		displays_env(main_env.env);
//		if (ft_strcmp(data[0], "env") == 0)
//			displays_env(main_env.env);
		if(ft_strcmp(data[0], "exit") == 0)
			return (0);
		else if (ft_strcmp(data[0], "echo") == 0)
			ft_echo(data + 1);
//		free(input);
	}
	return (0);
}
