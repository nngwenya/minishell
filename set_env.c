/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:38:22 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/19 17:40:25 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft/libft.h"

//function tries to change the size of the allocation pointed
//to by ptr to size, and returns ptr.
void    *ft_realloc(void *ptr, int size, int new_size)
{
    void *new;

    new = ft_memalloc(new_size);
    new = ft_memcpy(new, ptr, size);
    free(ptr);
    return (new);
}

void    get_input(char **input)
{
    int ret;
    int i;
    int count;
    char buff;

    i = 0;
    count = 1;
    (*input) = (char *)malloc(sizeof(char));
    while ((ret = read(0, &buff, 1)) && buff != '\n')
    {
        *(*input + i++) = buff;
        (*input) = ft_realloc(*input, count, count + 1);
        count++;
    }
    *(*input + i) = '\0';
}
//set, unset and fetch environment variables from the host
//environment list.
char    **ft_setenv(char **info, char *key, char *value)
{
    char *value_env;
    char **ret;
    int i;
	char *dest;

    value_env = ft_strjoin(key, "=");
    value_env = ft_strjoin(value_env, value);
    i = 0;
    while (info[i])
        i++;
    ret = (char **)malloc(sizeof(char *) * i + 2);
    i = 0;
    while (info[i])
    {
        ret[i] = ft_strdup(info[i]);
        i++;
    }
	if (key && key != '\0')
	{
		*dest = *key;
		dest++;
		key++;
	}
	else
	{
		return ;
	}
    ret[i] = ft_strdup(value_env);
    i++;
    ret[i] = NULL;
    return (ret);
}
