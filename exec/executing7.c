/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:24:12 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/10 22:29:47 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	**createherepipes(int number)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int *) * (number));
	if (!tab)
		return (0);
	while (i < number)
	{
		tab[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < number)
	{
		if (pipe(tab[i]) == -1)
		{
			perror("pipe");
			return (NULL);
		}
		i++;
	}
	return (tab);
}

void	declaring(t_info **info, t_shell **shellcmds, t_var **var)
{
	*var = malloc(sizeof(t_var));
	*shellcmds = NULL;
	*info = malloc(sizeof(t_info));
}

void	multipipes(t_shell *shellcmds, t_data **envp, t_info *info)
{
	int	i;

	i = -1;
	info->iter = 0;
	while (shellcmds)
	{
		info->cls = 0;
		if (info->iter == 0)
			execfirst(shellcmds, envp, info);
		else if (info->iter == info->nb_cmd - 1)
			execthird(shellcmds, envp, info);
		else
			execsec(shellcmds, envp, info);
		execpar(shellcmds, info);
		if (shellcmds->fdhere != -1)
			close(info->herepipes[++i][0]);
		shellcmds = shellcmds->nextcmd;
		info->iter++;
		if (info->iter == info->nb_cmd)
			break ;
	}
	waitingforall(info);
}

int	checkfordollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
