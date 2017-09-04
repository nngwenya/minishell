/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:26:11 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/04 11:36:01 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
/*
void    split_en(char **diff)
{
    char **data;
    t_env main_env;
    char *input;

    data = ft_strsplit(input, ' ');
    displays_env(main_env.env);
    if (ft_strcmp(data[0], "env") == 0)
        displays_env(main_env.env);
    else if(ft_strcmp(data[0], "exit") == 0)
        return ;
}
*/
void    execute(t_env main_env, char *input)
{
    if (ft_strcmp(input, "env") == 0)
    	displays_env(main_env.env);
}

char	**env_dup(char **env_new)
{
    int i;
    char **ret;
	extern char **environ;
    t_env main_env;

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
