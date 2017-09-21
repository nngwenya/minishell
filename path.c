/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:51:07 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/21 16:25:14 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_path(char *prog, char **environ)
{
	char	*res;
	char	**path;
	int		i;
	char	*temp;

	temp = ft_getenv("PATH", environ);
	path = ft_strsplit(temp, ':');
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		res = ft_strjoin(temp, prog);
		free(temp);
		if (access(res, X_OK) == 0)
			return (res);
		i++;
		free(res);
	}
	return (prog);
}
