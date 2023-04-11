/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:38:52 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 03:55:35 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	checktossawi(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

int	checkpath1(t_data **data)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "PATH=", 5) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_env(t_shell *p, t_data **data)
{
	t_data	*tmp;

	(void)p;
	tmp = *data;
	while (tmp)
	{
		if (checktossawi(tmp->content) == 0)
			printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
