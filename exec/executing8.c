/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:24:17 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 20:37:41 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	freestruct(t_info *info)
{
	int	i;

	i = 0;
	if (info->nb_cmd > 1 && info->pipesfds)
	{
		while (i < info->nb_cmd - 1)
		{
			free(info->pipesfds[i]);
			i++;
		}
		free(info->pipesfds);
	}
	free(g_globe.pid);
	if (info->strfinal)
		free(info->strfinal);
	if (info->nb_heredocs && info->herepipes)
	{
		i = 0;
		while (i < info->nb_heredocs)
			free(info->herepipes[i++]);
		free(info->herepipes);
	}
	close(info->fdd[0]);
	close(info->fdd[1]);
}

int	calculcmds(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell)
	{
		shell->fdhere = -1;
		shell = shell->nextcmd;
		i++;
	}
	return (i);
}

int	calculheredocs(t_shell *shell)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (shell)
	{
		i = 0;
		while (shell->files[i])
		{
			if (strncmp(shell->files[i], "<<", 2) == 0)
				count++;
			i++;
		}
		shell = shell->nextcmd;
	}
	return (count);
}

int	**creatpipes(int number)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int *) * (number - 1));
	if (!tab)
		return (0);
	while (i < number - 1)
	{
		tab[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < number - 1)
	{
		if (pipe(tab[i]) == -1)
		{
			perror("PIPE");
			return (NULL);
		}
		i++;
	}
	return (tab);
}

void	creatpids(int number)
{
	g_globe.pid = malloc(sizeof(int) * (number));
	if (!g_globe.pid)
		perror("malloc");
}
