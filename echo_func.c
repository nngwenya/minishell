/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:22:24 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/12 16:27:05 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
//searching if the key exist and printing the value
int    prompt_en(char **args, char *input)
{
    char **data;
	t_env main_env;
	char *dir;

    data = ft_strsplit(input, ' ');
	if (ft_strcmp(data[0], "env") == 0)
        displays_env(args);
    else if(ft_strcmp(data[0], "exit") == 0)
		exit(-1);
	else if ((ft_strcmp(data[0], "echo") == 0) && (data[1][0] == '$'))
		ft_putendl(getenv_echo(data[1] ,args));
	else if ((ft_strcmp(data[0], "echo") == 0) && (data[1][0] != '$'))
		ft_echo(&data[1]);
	else if(ft_strcmp(data[0], "cd") == 0)
		cd_builtin(data[1] ,main_env.env);
	return (1);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
//checking for characters which echo doesn't display
void	putstring(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '"' && s[i] != '\\' &&  s[i] != '\'')
			ft_putchar(s[i]);
		i++;
	}
	ft_putchar(' ');
}
//printing out the arguments after the echo
void	ft_echo(char **arguments)
{
	int i;

	i = 0;
	while (arguments[i] != '\0')
		putstring(arguments[i++]);
	ft_putchar('\n');
}

char	*getenv_echo(char *env_str, char **env)
{
	int i;
	char *temp;
	
	i = -1;
	while (env[++i])
	{
		temp = ft_strjoin(env_str + 1, "=");
		if (ft_strncmp(env[i], temp, ft_strlen(temp)) == 0)
		{
			free(temp);
			return (ft_strchr(env[i], '=') + 1);
		}
		free(temp);
	}
	return (NULL);
}
