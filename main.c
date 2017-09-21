/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:22:39 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/21 16:33:12 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//displaying the env

void	displays_env(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		ft_putstr(s[i]);
		ft_putchar('\n');
	}
}

int		main(void)
{
	char		*input;
	extern char	**environ;
	t_env		main_env;

	main_env.env = env_dup(environ);
	while (1)
	{
		ft_putstr("\x1b[32m");
		ft_putstr("♥️ 👉 > ");
		ft_putstr("\x1b[33m");
		get_input(&input);
		input = ft_strtrim(input);
		if (ft_strlen(input))
			prompt_en(input, &main_env.env);
	}
	return (0);
}
