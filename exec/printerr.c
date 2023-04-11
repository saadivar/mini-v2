/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:22:03 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 20:23:19 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printerr(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	if (s2)
	{
		ft_putstr_fd(s2, 2);
		ft_putstr_fd(": ", 2);
	}
	if (s3)
	{
		ft_putstr_fd(s3, 2);
		ft_putchar_fd('\n', 2);
	}
}

void	printerr1(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	if (s2)
	{
		ft_putstr_fd(s2, 2);
		ft_putstr_fd(": ", 2);
	}
	if (s3)
	{
		ft_putstr_fd(s3, 2);
		ft_putchar_fd('\n', 2);
	}
	g_globe.exit_status = 1;
}

void	printerr2(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	if (s2)
	{
		ft_putstr_fd(s2, 2);
		ft_putstr_fd(": ", 2);
	}
	if (s3)
	{
		ft_putstr_fd(s3, 2);
		ft_putchar_fd('\n', 2);
	}
	g_globe.exit_status = 127;
}

int	checkzaid(char *s)
{
	int		i;
	int		len;
	char	*str;

	str = bringbeforetossawi(s);
	if (!str)
		len = 0;
	else
	{
		len = ft_strlen(str);
		free(str);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '+')
		{
			if (s[i + 1] == '=')
				return (i);
			else if (i < len)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	helper_built(t_info *info)
{
	info->fd_in = -2;
	info->fd_out = -2;
	dup2(info->fdd[0], 0);
	dup2(info->fdd[1], 1);
}
