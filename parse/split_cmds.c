/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:41:25 by smounafi          #+#    #+#             */
/*   Updated: 2023/04/11 06:57:42 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_helper(char **files, char **splited, int *i, int *j)
{
	while (splited[*i])
	{
		if (splited[*i][0] == '>' || splited[*i][0] == '<')
		{
			files[*j] = ft_strjoin(splited[*i], splited[*i + 1]);
			(*j)++;
			*i += 2;
		}
		else
			(*i)++;
	}
}

void	inittttttttt(int *i, int *j, int *len, char **splited)
{
	*i = 0;
	*j = 0;
	*len = countfilesss(splited);
}

char	**addfiles(char **splited, int pose_pipe)
{
	int		len;
	char	**files;
	int		i;
	int		j;

	inittttttttt(&i, &j, &len, splited);
	files = malloc(8 * (len + 1));
	if (pose_pipe == -1)
		add_helper(files, splited, &i, &j);
	else
	{
		while (i < pose_pipe)
		{
			if (splited[i][0] == '>' || splited[i][0] == '<')
			{
				files[j++] = ft_strjoin(splited[i], splited[i + 1]);
				i += 2;
			}
			else
				i++;
		}
	}
	files[j] = NULL;
	return (files);
}

void	init_elements(t_shell **shellcmds, char **splitted_string)
{
	char	**files;
	char	**cmd;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	i = get_pipe_index(splitted_string);
	cmd = addcmd(splitted_string, i);
	files = addfiles(splitted_string, i);
	k = 0;
	*shellcmds = ft_lstnew1(cmd, files);
	splitted_string += i + 1;
	while (i > 0)
	{
		if (i > 0)
			i = get_pipe_index(splitted_string);
		cmd = addcmd(splitted_string, i);
		files = addfiles(splitted_string, i);
		ft_lstadd_back1(shellcmds, ft_lstnew1(cmd, files));
		if (i > 0)
			splitted_string += i + 1;
	}
}

t_shell	*split_to_stock_cmd(char **splitted_string, t_shell **shellcmds)
{
	init_elements(shellcmds, splitted_string);
	return (*shellcmds);
}
