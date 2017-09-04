#ifndef MINISHELL_H
#define  MINISHELL_H

#include "libft/libft.h"

typedef struct s_env
{
    char	**env;
    
}               t_env;

void    putstring(char *s);
void    ft_echo(char **arguments);
void    displays_env(char **s);
char	**env_dup(char **env_new);
char    **set_env(char **info, char *key, char *value);
void    *ft_realloc(void *ptr, int size, int new_size);
void    execute(t_env main_env, char *input);
void    get_input(char **input);
void    split_en(char **diff);

#endif
