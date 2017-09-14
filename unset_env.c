/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:37:00 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/14 16:58:33 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int		unset_env(const char *name)
{
	char **value_en; 
	char **ret;
	size_t len;
	t_env main_env.v;

	len = ft_strlen(name);
	while (value_en = main_env.v && *value_en != NULL;) 
	{
		if (ft_strncmp(*value_en, name, len) == 0 && (*value_en)[len] == '=')
		{
			while (ret = value_en && *ret != NULL) 
			{
				*ret = *(ret + 1);
				ret++;
			}
		else
		 	{		
				value_en++;
			}
		}	
	}

	return 0;
}
