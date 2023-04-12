/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:24:23 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 05:17:06 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_heredoc(t_shell *shellcmds, t_info *info, t_data **env)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		if (!info->herepipes)
			exit(100);
		signal(SIGINT, her);
		signal(SIGQUIT, SIG_IGN);
		child_heredoc(shellcmds, info, env);
	}
	else
	{
		signal(SIGINT, sighandle1);
		waitpid(pid, &status, 0);
		if (69 == WEXITSTATUS(status))
		{
			g_globe.exit_status = 1;
			return (1);
		}
		else
			g_globe.exit_status = 0;
	}
	return (0);
}

void	helperwhile(t_shell *cmds, t_info *info, int *np, int i)
{
	int	flag;

	flag = 0;
	while (cmds->files[i])
	{
		if (ft_strncmp(cmds->files[i], "<<", 2) == 0)
		{
			if (flag > 0)
			{
				close(info->herepipes[(*np) - 1][0]);
				close(info->herepipes[(*np) - 1][1]);
			}
			flag++;
			(*np)++;
		}
		i++;
	}
}

void	saving(t_shell *shellcmds, t_info *info)
{
	t_shell	*cmds;
	int		i;
	int		np;

	np = 0;
	cmds = shellcmds;
	while (cmds)
	{
		i = 0;
		if (cmds->files[i])
		{
			helperwhile(cmds, info, &np, i);
			if (np > 0)
			{
				cmds->fdhere = info->herepipes[np - 1][0];
				close(info->herepipes[np - 1][1]);
			}
		}
		cmds = cmds->nextcmd;
	}
}

void	init_info(t_shell *shellcmds, t_data **envp, t_info *info)
{
	(info)->fd_in = -2;
	(info)->fd_out = -2;
	(info)->fdd[0] = dup(0);
	(info)->fdd[1] = dup(1);
	info->hhh = 0;
	info->strfinal = NULL;
	info->nb_cmd = 0;
	info->nb_heredocs = 0;
	info->nb_cmd = calculcmds(shellcmds);
	if (info->nb_cmd)
	{
		g_globe.nb_cmd = info->nb_cmd;
		if (info->nb_cmd > 1)
			info->pipesfds = creatpipes(info->nb_cmd);
		creatpids(info->nb_cmd);
	}
	info->nb_heredocs = calculheredocs(shellcmds);
	if (info->nb_heredocs)
	{
		info->herepipes = createherepipes(info->nb_heredocs);
		info->hhh = ft_heredoc(shellcmds, info, envp);
		saving(shellcmds, info);
	}
}

void	executions(t_shell *shellcmds, t_data **envp, t_info *info)
{
	init_info(shellcmds, envp, info);
	if (info->nb_cmd == 1 && info->hhh == 0)
	{
		exec1cmd(shellcmds, envp, info);
		if (shellcmds->fdhere != -1)
			close(shellcmds->fdhere);
	}
	else if (info->nb_cmd > 1 && info->hhh == 0)
		multipipes(shellcmds, envp, info);
	freestruct(info);
	freelinkedlist(shellcmds);
}
