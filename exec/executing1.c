/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 06:34:05 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/11 05:52:37 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	checkbuilins(char *s)
{
	if (strcmp(s, "echo") == 0 || strcmp(s, "cd") == 0 || strcmp(s,
			"export") == 0 || strcmp(s, "unset") == 0 || strcmp(s, "exit") == 0
		|| strcmp(s, "env") == 0 || strcmp(s, "pwd") == 0 || strcmp(s,
			"CD") == 0)
		return (1);
	return (0);
}

int	helper_out(char *s, t_info *info)
{
	if (s[1] == '\0')
	{
		printerr("bash", s + 1, "no such file or directory");
		g_globe.exit_status = 1;
		return (-2);
	}
	else if (s[1] != '>')
	{
		info->fd_out = open(s + 1,
				O_CREAT | O_TRUNC | O_WRONLY, 0644);
	}
	else if (s[1] == '>' && s[2] == '\0')
	{
		printerr("bash", s + 1, "no such file or directory");
		g_globe.exit_status = 1;
		return (-2);
	}
	else
		info->fd_out = open(s + 2,
				O_CREAT | O_APPEND | O_WRONLY, 0644);
	return (0);
}

int	helper_in(char *s, t_info *info)
{
	info->fd_in = open(s + 1, O_RDONLY);
	if (info->fd_in < 0)
	{
		printerr("bash", s + 1, "no such file or directory");
		g_globe.exit_status = 1;
		return (-2);
	}
	return (0);
}

int	helperrr(char *str, t_info *info)
{
	if (str[0] == '>')
	{
		if (helper_out(str, info) == -2)
			return (-2);
	}
	else if (str[0] == '<')
	{
		free(info->sdhere);
		info->flag = 1;
		if (str[1] != '<')
		{
			if (helper_in(str, info) == -2)
				return (-2);
			info->sdhere = ft_strdup(str);
		}
		else
			info->sdhere = ft_strdup(str);
	}
	return (0);
}

int	checkforfiles(t_shell *shellcmd, t_info *info)
{
	int	i;

	info->sdhere = NULL;
	info->flag = 0;
	i = 0;
	if (shellcmd->files[i])
	{
		while (shellcmd->files[i])
		{
			if (helperrr(shellcmd->files[i], info) == -2)
				return (-2);
			i++;
		}
		if (info->flag == 1)
		{
			if (strncmp(info->sdhere, "<<", 2) == 0)
			{
				free(info->sdhere);
				return (0);
			}
		}
	}
	free(info->sdhere);
	return (1);
}
