/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 07:09:31 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 02:59:24 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	contain_quotes(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	containn_quotes(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	contain_redir(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '>' || str[i] == '<') && (str[i + 1] != '>' || str[i
					+ 1] != '<'))
			return (0);
		i++;
	}
	return (1);
}

void	trim_cmds(t_shell **shellcmds, int i)
{
	char	*tmp;

	tmp = (*shellcmds)->cmd[i];
	(*shellcmds)->cmd[i] = ft_strtrim((*shellcmds)->cmd[i]);
	free(tmp);
}

void	clean_quotes(t_shell *shellcmds)
{
	int		i;
	char	*tmp;

	while (shellcmds)
	{
		i = -1;
		while (shellcmds->cmd[++i])
			if ((contain_quotes(shellcmds->cmd[i], 34) == 0
					|| containn_quotes(shellcmds->cmd[i], 39) == 0))
				trim_cmds(&shellcmds, i);
		i = 0;
		while (shellcmds->files[i])
		{
			if (contain_redir(shellcmds->files[i]) == 0)
			{
				tmp = shellcmds->files[i];
				shellcmds->files[i] = ft_strtrim(shellcmds->files[i]);
				free(tmp);
			}
			i++;
		}
		shellcmds = shellcmds->nextcmd;
	}
}
