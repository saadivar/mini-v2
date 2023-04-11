/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:54:26 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/10 00:01:30 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execnob1(t_shell *shellcmd, t_data **envp, t_info *info)
{
	int	check;

	if (shellcmd->cmd[0][0] != '/' && shellcmd->cmd[0][0] != '.')
	{
		check = communpartexec(shellcmd, envp, info);
		if (check)
		{
			check_files_ex(shellcmd, info);
			cnf_nsfd(shellcmd->cmd[0], check, shellcmd, info);
		}
		else
			communpart2222(shellcmd, envp, info, check);
	}
	else
		wahexec(shellcmd, info, envp);
}

void	exec1cmd(t_shell *shellcmds, t_data **envp, t_info *info)
{
	if (shellcmds->cmd[0] == NULL)
	{
		checkforfiles(shellcmds, info);
	}
	else if (checkbuilins(shellcmds->cmd[0]))
	{
		execbuiltins(shellcmds, envp, info);
	}
	else
		execnob(shellcmds, envp, info);
}

void	help_forfirst(t_info *info)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	while (info->cls < info->nb_cmd - 1)
	{
		if (info->cls != 0)
			close(info->pipesfds[info->cls][1]);
		close(info->pipesfds[info->cls][0]);
		info->cls++;
	}
	dup2(info->pipesfds[0][1], 1);
}

void	execfirst(t_shell *shellcmds, t_data **envp, t_info *info)
{
	g_globe.pid[info->iter] = fork();
	if (g_globe.pid[info->iter] == 0)
	{
		if ((info->nb_heredocs && !info->herepipes) || !info->pipesfds)
			exit(100);
		if (info->pipesfds)
			help_forfirst(info);
		if (shellcmds->cmd[0] == NULL)
		{
			checkforfiles(shellcmds, info);
			exit(g_globe.exit_status);
		}
		else if (checkbuilins(shellcmds->cmd[0]))
		{
			execbuiltins1(shellcmds, envp, info);
			exit(g_globe.exit_status);
		}
		else
			execnob1(shellcmds, envp, info);
	}
}

void	help_for3rd(t_info *info)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	while (info->cls < info->nb_cmd - 1)
	{
		if (info->cls != info->iter - 1)
			close(info->pipesfds[info->cls][0]);
		close(info->pipesfds[info->cls][1]);
		info->cls++;
	}
	dup2(info->pipesfds[info->iter - 1][0], 0);
}
