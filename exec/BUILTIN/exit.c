/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:38:48 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 08:24:01 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	isnum(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (-1);
		i++;
	}
	return (ft_atoi_fd(s));
}

void	exit_ut(char *s)
{
	printf("%s\n", s);
	write(1, "bash: ", 6);
	printerr(s, NULL, "too many arguments");
	g_globe.exit_status = 1;
}

void	ft_exit(t_shell *p)
{
	if (p->cmd[1] == NULL)
	{
		printf("%s\n", p->cmd[0]);
		exit(g_globe.exit_status);
	}
	if (isnum(p->cmd[1]) == -1)
	{
		printf("%s\n", p->cmd[0]);
		write(1, "bash: ", 6);
		printerr(p->cmd[0], p->cmd[1], "numeric argument required");
		exit(255);
	}
	else if (p->cmd[2])
		exit_ut(p->cmd[0]);
	else
	{
		printf("%s\n", p->cmd[0]);
		g_globe.exit_status = isnum(p->cmd[1]);
		exit(g_globe.exit_status);
	}
}
