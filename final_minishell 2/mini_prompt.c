/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:24:40 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/13 12:54:11 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int			prompt(char ***env)
{
	char	line[4096];
	char	**args;
	int		r;

	ft_putstr(" \033[31mMy own\033[0m\033[32m-ls\033[0m\033[33m->>\033[0m ");
	r = read(0, line, 4096);
	line[r - 1] = '\0';
    if (ft_strlen(line))
    {
	     args = ft_strsplit(line, ' ');
	    if (ft_strcmp(args[0], "exit") == 0)
		    exit(-1);
	    else if ((ft_strcmp(args[0], "echo") == 0) && (args[1][0] != '$'))
		    echo_func(args);
	    else if ((ft_strcmp(args[0], "echo") == 0) && (args[1][0] == '$'))
		    get_environ(args, *env);
	    else if (ft_strcmp(args[0], "env") == 0)
		    get_env(*env);
	    else if (ft_strcmp(args[0], "setenv") == 0)
		    *env = setv(*env, args[1], args[2]);
	    else if (ft_strcmp(args[0], "unsetenv") == 0)
		    *env = ft_unsetenv(*env, args[1]);
	    else
		    get_path(*env, args);
	    free_args(args);
    }
    return (1);
}
