/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:39:42 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 22:48:33 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	communpartexec(t_shell *shellcmd, t_data **envp, t_info *info)
{
	char	**str;

	str = NULL;
	if (!(access(shellcmd->cmd[0], X_OK)))
		info->strfinal = strdup(shellcmd->cmd[0]);
	else
	{
		str = getpath(envp);
		if (!str)
			return (1);
		info->strfinal = checkpath(str, shellcmd);
		if (!info->strfinal)
		{
			if (str)
				free_2d_array(str);
			return (2);
		}
	}
	if (str)
		free_2d_array(str);
	return (0);
}

void	child(t_shell *shellcmd, t_data **envp, t_info *info)
{
	int	check;

	check = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	check = checkforfiles(shellcmd, info);
	if (check == -2)
		exit(g_globe.exit_status);
	else if (check == 1)
	{
		if (info->fd_in != -2)
			dup2(info->fd_in, 0);
	}
	else if (check == 0)
		dup2(shellcmd->fdhere, 0);
	if (info->fd_out != -2)
		dup2(info->fd_out, 1);
	wahexec(shellcmd, info, envp);
}

void	papa(void)
{
	signal(SIGINT, sighandle1);
	signal(SIGQUIT, sighandlequit);
	waitpid(g_globe.pid[0], &g_globe.exit_status, 0);
	if (WIFEXITED(g_globe.exit_status))
		g_globe.exit_status = WEXITSTATUS(g_globe.exit_status);
	else if (WIFSIGNALED(g_globe.exit_status))
		g_globe.exit_status = WTERMSIG(g_globe.exit_status) + 128;
}

void	child1(t_shell *shellcmd, t_data **envp, t_info *info)
{
	int	check;

	check = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	check = checkforfiles(shellcmd, info);
	if (check == -2)
		exit(g_globe.exit_status);
	else if (check == 1)
	{
		if (info->fd_in != -2)
			dup2(info->fd_in, 0);
	}
	else if (check == 0)
		dup2(shellcmd->fdhere, 0);
	if (info->fd_out != -2)
		dup2(info->fd_out, 1);
	conver2d(envp, info);
	execve(info->strfinal, shellcmd->cmd, info->envir);
}

void	execvedyale1(t_shell *shellcmd, t_data **envp, t_info *info)
{
	g_globe.pid[0] = fork();
	if (g_globe.pid[0] == 0)
		child1(shellcmd, envp, info);
	else
		papa();
}
