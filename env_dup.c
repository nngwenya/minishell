/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:26:11 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/26 15:56:42 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_env main_env, char *input)
{
	if (ft_strcmp(input, "env") == 0)
		displays_env(main_env.env);
}

char	**env_dup(char **environ)
{
	int		i;
	char	**ret;

	i = 0;
	while (environ[i])
		i++;
	ret = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (environ[i])
	{
		ret[i] = ft_strdup(environ[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
