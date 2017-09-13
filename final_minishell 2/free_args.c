/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:18:14 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/07 09:12:16 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int			free_args(char **arr)
{
	int		i;

	if (arr == NULL)
		return (1);
	i = 0;
	while (arr[i] != NULL)
	{
		ft_free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
	return (1);
}
