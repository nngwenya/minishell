/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:22:24 by nngwenya          #+#    #+#             */
/*   Updated: 2017/09/04 11:50:31 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_echo(char **arguments)
{
	int i;

	i = 0;
	while (arguments[i] != '\0')
		putstring(arguments[i++]);
	ft_putchar('\n');
}
