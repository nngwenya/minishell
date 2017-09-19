/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:22:24 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/19 13:42:23 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
//searching if the key exist and printing the value

int    prompt_en(char *input, char ***env)
{
    char **data;
	char *dir;
    
	data = ft_strsplit(input, ' ');
	if (ft_strcmp(data[0], "env") == 0)
        displays_env(*env);
	else if (ft_strcmp(data[0], "setenv") == 0)
		*env = ft_setenv(*env, data[1], data[3]);
	else if (ft_strcmp(data[0], "unsetenv") == 0)
	*env =	unset_env(*env, data[1]);
    else if(ft_strcmp(data[0], "exit") == 0)
		exit(-1);
	else if ((ft_strcmp(data[0], "echo") == 0) && (data[1][0] == '$'))
		ft_putendl(ft_getenv(data[1] + 1 ,*env));
	else if ((ft_strcmp(data[0], "echo") == 0) && (data[1][0] != '$'))
		ft_echo(&data[1]);
	else if(ft_strcmp(data[0], "cd") == 0)
		cd_builtin(data[1] , *env);
	else
		execve_func(data, *env);
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
//function obtains the current value of the environment variable,
//name.
char	*ft_getenv(char *env_str, char **env)
{
	int i;
	char *temp;
	
	i = -1;
	temp = ft_strjoin(env_str, "=");
	while (env[++i])
	{
		if (ft_strncmp(env[i], temp, ft_strlen(temp)) == 0)
		{
			free(temp);
			return (ft_strchr(env[i], '=') + 1);
		}
	}
	free(temp);
	return (NULL);
}
