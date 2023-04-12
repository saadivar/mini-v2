/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 07:09:31 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 00:01:15 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_stuff(t_var *var)
{
	var->x = 0;
	var->y = 0;
	var->i = 0;
	var->j = 0;
	var->k = 0;
	var->m = 0;
	var->n = 0;
	var->l = 0;
	var->index = 0;
	var->len = 0;
	var->counter = 0;
}

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

void	clean_quotes(t_shell *shellcmds, t_var var)
{
	int		i;
	char	*tmp;

	i = 0;
	while (shellcmds)
	{
		i = 0;
		while (shellcmds->cmd[i])
		{
			if ((contain_quotes(shellcmds->cmd[i], 34) == 0
					|| containn_quotes(shellcmds->cmd[i], 39) == 0))
			{
				tmp = shellcmds->cmd[i];
				shellcmds->cmd[i] = ft_strtrim(shellcmds->cmd[i], &var);
				free(tmp);
			}
			i++;
		}
		i = 0;
		while (shellcmds->files[i])
		{
			if (contain_redir(shellcmds->files[i]) == 0)
			{
				tmp = shellcmds->files[i];
				shellcmds->files[i] = ft_strtrim(shellcmds->files[i], &var);
				free(tmp);
			}
			i++;
		}
		shellcmds = shellcmds->nextcmd;
	}
}
