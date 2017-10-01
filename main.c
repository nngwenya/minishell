/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:22:39 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/26 17:18:57 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void		sig_c_handler(int signo)
{
	if (signo == 2)
		ft_putchar('\n');
}

void		free_2d_array(char **array)
{
	int		i;

	if (!array)
		return ;
	i = -1;
	while (array[i++])
	{
		free(array[i]);
	}
	free(array);
	array = NULL;
}

void		displays_env(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		ft_putstr(s[i]);
		ft_putchar('\n');
	}
}

static void	signal_handler(int signo)
{
	if (signo == 2)
		ft_putstr("\b \b\b \b \n\x1b[32m♥️ ℳ ▷ \x1b[33m");
}

int			main(void)
{
	char		*input;
	extern char	**environ;
	t_env		main_env;

	main_env.env = env_dup(environ);
	while (1)
	{
		signal(2, signal_handler);
		ft_putstr("\x1b[32m");
		ft_putstr("♥️ ℳ ▷ ");
		ft_putstr("\x1b[33m");
		get_input(&input);
		input = ft_strtrim(input);
		if (ft_strlen(input))
			command_env(input, &main_env.env);
	}
	free_2d_array(environ);
	return (0);
}
