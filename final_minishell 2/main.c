/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:28:28 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/07 09:22:35 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

char		**init_env(void)
{
	extern char **environ;
	char 	**ret;
	int 	len;
	int 	i;

	len = -1;
	i = -1;
	while (environ[++len])
		len++;
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	while (environ[++i])
		ret[i] = ft_strdup(environ[i]);
	ret[i] = NULL;
	return (ret);
}

int		main(void)
{
	char 	**g_env;

	g_env = init_env();
	while (1)
	{
		prompt(&g_env);
	}
	free_args(g_env);
	return (1);
}
