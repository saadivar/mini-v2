/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:10:57 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 22:51:26 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execthird(t_shell *shellcmds, t_data **envp, t_info *info)
{
	g_globe.pid[info->iter] = fork();
	if (g_globe.pid[info->iter] == 0)
	{
		if ((info->nb_heredocs && !info->herepipes) || !info->pipesfds)
			exit(100);
		help_for3rd(info);
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

void	help_forsec(t_info *info)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	while (info->cls < info->nb_cmd - 1)
	{
		if (info->cls != info->iter - 1)
			close(info->pipesfds[info->cls][0]);
		if (info->cls != info->iter)
			close(info->pipesfds[info->cls][1]);
		info->cls++;
	}
	dup2(info->pipesfds[info->iter - 1][0], 0);
}

void	execsec(t_shell *shellcmds, t_data **envp, t_info *info)
{
	g_globe.pid[info->iter] = fork();
	if (g_globe.pid[info->iter] == 0)
	{
		if ((info->nb_heredocs && !info->herepipes) || !info->pipesfds)
			exit(100);
		help_forsec(info);
		dup2(info->pipesfds[info->iter][1], 1);
		if (shellcmds->cmd[0] == NULL)
		{
			dup2(info->fdd[0], 0);
			dup2(info->fdd[1], 1);
			checkforfiles(shellcmds, info);
			exit(0);
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

void	execpar(t_shell *shellcmds, t_info *info)
{
	if (info->pipesfds)
	{
		if (shellcmds->fdhere != -1)
			close(shellcmds->fdhere);
		if (info->iter > 0)
			close(info->pipesfds[info->iter - 1][0]);
		if (info->iter < info->nb_cmd - 1)
			close(info->pipesfds[info->iter][1]);
	}
}

void	waitingforall(t_info *info)
{
	pid_t	id;
	int		status;

	signal(SIGINT, sighandle1);
	signal(SIGQUIT, sighandlequit);
	id = waitpid(-1, &status, 0);
	while (id != -1)
	{
		if (id == g_globe.pid[info->iter - 1])
		{
			if (WIFEXITED(status))
				g_globe.exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				g_globe.exit_status = WTERMSIG(status) + 128;
		}
		id = waitpid(-1, &status, 0);
	}
}

// void	waitingforall(t_info *info)
// {
// 	waitpid(info->pid,&g_globe.exit_status,0);
// 	g_globe.exit_status = WEXITSTATUS(g_globe.exit_status);
// 	info->iter = -1;
// 	while (++info->iter < info->nb_cmd - 1)
// 		waitpid(-1,NULL,0);
// }