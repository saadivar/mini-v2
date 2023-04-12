/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 07:08:44 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 05:15:08 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	countfilesss(char **splited)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (splited[i])
	{
		if (splited[i][0] == '>' || splited[i][0] == '<')
			count++;
		i++;
	}
	return (count);
}

int	count_total(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		i++;
	return (i);
}

void	add_helper_cmd(char **cmd, char **splited, int *i, int *j)
{
	while (splited[*i])
	{
		if (splited[*i][0] != '>' && splited[*i][0] != '<')
		{
			cmd[*j] = ft_strdup(splited[*i]);
			(*j)++;
			(*i)++;
		}
		else
			*i += 2;
	}
}

char	**addcmd(char **splited, int pose_pipe)
{
	int		len;
	char	**cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = count_total(splited) - (countfilesss(splited) * 2);
	cmd = malloc(8 * (len + 1));
	if (pose_pipe == -1)
		add_helper_cmd(cmd, splited, &i, &j);
	else
	{
		while (i < pose_pipe)
		{
			if (splited[i][0] != '>' && splited[i][0] != '<')
				cmd[j++] = ft_strdup(splited[i++]);
			else
				i += 2;
		}
	}
	cmd[j] = NULL;
	return (cmd);
}

int	get_pipe_index(char **holder)
{
	int	i;

	i = 0;
	while (holder[i])
	{
		if (holder[i][0] == '|')
			return (i);
		i++;
	}
	return (-1);
}
