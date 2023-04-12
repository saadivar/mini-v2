/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:38:56 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 05:11:15 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	checks1(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) <= 1)
		return (1);
	while (s[i] && s[i + 1])
	{
		if (s[0] != '-' || s[i + 1] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_echo1(t_shell *p, int *i, int *check)
{
	while (p->cmd[*i] && p->cmd[*i + 1])
	{
		if (!checks1(p->cmd[*i]))
		{
			*check = 1;
			(*i)++;
		}
		else
			break ;
	}
	while (p->cmd[*i])
	{
		ft_putstr_fd(p->cmd[*i], 1);
		if (p->cmd[(*i) + 1])
			ft_putchar_fd(' ', 1);
		(*i)++;
	}
	if (*check == 0)
		ft_putchar_fd('\n', 1);
}

int	ft_echo(t_shell *p)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	if (!p->cmd[i])
		write(1, "\n", 1);
	else
		ft_echo1(p, &i, &check);
	return (0);
}
