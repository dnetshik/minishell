/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:34:13 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/12 15:31:58 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void		ft_exec(char *prog, char **args, char **env)
{
	pid_t	k;

	k = fork();
	if (k == 0)
	{
		if (prog == NULL)
			printf("error\n");
		else
			execve(prog, args, env);
	}
	wait(NULL);
}

void       func(char *temp, char **s, char **args, char **env)
{
    char *prog;
    int i;

    i = 0;
    prog = NULL;
    while(s[i])
    {
        temp = ft_strjoin(s[i], "/");
        temp = ft_strjoin(temp, args[0]);
        if(access(temp, X_OK) == 0)
            prog = ft_strdup(temp);
        i++;
    }
    ft_exec(prog, args, env);
}
void		get_path(char **env, char **args)
{
	char	*path;
	char 	**s;
	int  i;
	char 	*tmp;
	char 	*prog;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (strncmp("PATH=", env[i], 5) == 0)
			path = ft_strdup(env[i]);
		i++;
	}
	if (path == NULL)
	{
		if (access(args[0], X_OK) == 0)
			ft_exec(args[0], args, env);
		else
			printf("minishell: command not found: %s\n", args[0]);
		return ;
	}
	path = ft_strdup(ft_strchr(path, '/'));
	s = ft_strsplit(path, ':');
/*	i = 0;
	prog = NULL;
	while (s[i])
	{
		tmp = ft_strjoin(s[i], "/");
		tmp= ft_strjoin(tmp, args[0]);
		if (access(tmp, X_OK) == 0)
			prog = ft_strdup(tmp);
		i++;
	}
	ft_exec(prog, args, env);*/
    func(tmp, s, args, env);
}
