/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:37:00 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/20 14:55:07 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

//function deletes all instances of the variable name pointed
//to by name from the list

char	**unset_env(char **name, char *key)
{
	char	**ret;
	int		i;

	i = 0;
	while (name[i])
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (name[i])
	{
		if (ft_strncmp(key, name[i], ft_strlen(key)) == 0
				&& (name[i][ft_strlen(key)] == '='))
			i++;
		else
		{
			ret[i] = ft_strdup(name[i]);
			i++;
		}
	}
	ret[i] = NULL;
	return (ret);
}
