/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:38:22 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/11 15:29:16 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft/libft.h"

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
char    **set_env(char **info, char *key, char *value)
{
    char *value_env;
    char **ret;
    int i;

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
    ret[i] = ft_strdup(value_env);
    i++;
    ret[i] = NULL;
    return (ret);
}
