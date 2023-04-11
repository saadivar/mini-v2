/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing11.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 04:53:03 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/10 00:00:10 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execvedyale(t_shell *shellcmd, t_data **envp, t_info *info)
{
	g_globe.pid[0] = fork();
	if (g_globe.pid[0] == 0)
		child(shellcmd, envp, info);
	else
		papa();
}

void	check_files_ex(t_shell *shellcmd, t_info *info)
{
	if (checkforfiles(shellcmd, info) == -2)
		exit(1);
}

void	execnob(t_shell *shellcmd, t_data **envp, t_info *info)
{
	int	check;

	if (shellcmd->cmd[0][0] != '/' && shellcmd->cmd[0][0] != '.')
	{
		check = communpartexec(shellcmd, envp, info);
		if (shellcmd->cmd[0][0] == '\0' || check == 2)
		{
			if (checkforfiles(shellcmd, info) == -2)
				return ;
			printerr2("bash", shellcmd->cmd[0], "command not found");
		}
		else if (check == 1)
		{
			if (checkforfiles(shellcmd, info) == -2)
				return ;
			printerr2("bash", shellcmd->cmd[0], "No such file or directory");
		}
		else
			execvedyale1(shellcmd, envp, info);
	}
	else
		execvedyale(shellcmd, envp, info);
}

void	wahexec(t_shell *shellcmd, t_info *info, t_data **envp)
{
	conver2d(envp, info);
	execve(shellcmd->cmd[0], shellcmd->cmd, info->envir);
	if (access(shellcmd->cmd[0], F_OK) == 0)
	{
		if (shellcmd->cmd[0][0] == '.')
		{
			if (shellcmd->cmd[0][1] == '\0')
			{
				printerr("bash", shellcmd->cmd[0],
					"ilename argument required\
					\n.: usage: . filename [arguments]");
				exit(2);
			}
			else if (shellcmd->cmd[0][1] == '.' && shellcmd->cmd[0][2] == '\0')
			{
				printerr("bash", shellcmd->cmd[0], "command not found");
				exit(127);
			}
		}
		perror(shellcmd->cmd[0]);
		exit(126);
	}
	perror(shellcmd->cmd[0]);
	exit(127);
}

void	communpart2222(t_shell *shellcmd, t_data **envp, t_info *info,
		int check)
{
	check = checkforfiles(shellcmd, info);
	if (check == -2)
		exit(g_globe.exit_status);
	else if (check == 1)
	{
		if (info->fd_in != -2)
			dup2(info->fd_in, 0);
	}
	else if (check == 0)
	{
		dup2(shellcmd->fdhere, 0);
		close(shellcmd->fdhere);
	}
	if (info->fd_out != -2)
		dup2(info->fd_out, 1);
	conver2d(envp, info);
	execve(info->strfinal, shellcmd->cmd, info->envir);
}

// else if (check == 2)
		// {
		// 	if (checkforfiles(shellcmd, info) == -2)
		// 		return ;
		// 	printerr2("bash", shellcmd->cmd[0], "command not found");
		// }