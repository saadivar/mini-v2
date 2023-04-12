/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:50:35 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 01:56:38 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fcs(int *fd, char *s, t_data **env)
{
	char	*str;

	while (1)
	{
		str = readline("> ");
		if (!str || strcmp(str, s) == 0)
		{
			g_globe.exit_status = 0;
			break ;
		}
		if (checkfordollar(str))
			str = ft_get_environment(str, *env);
		str = ft_strjoin10(str, "\n");
		write(fd[1], str, ft_strlen(str));
		free(str);
	}
}

void	her(int i)
{
	(void)i;
	exit(69);
}

void	child_heredoc(t_shell *shellcmds, t_info *info, t_data **env)
{
	int		np;
	t_shell	*cmds;
	int		i;

	np = 0;
	cmds = shellcmds;
	while (cmds)
	{
		i = 0;
		if (cmds->files[i])
		{
			while (cmds->files[i])
			{
				if (ft_strncmp(cmds->files[i], "<<", 2) == 0)
				{
					fcs(info->herepipes[np], cmds->files[i] + 2, env);
					close(info->herepipes[np][1]);
					np++;
				}
				i++;
			}
		}
		cmds = cmds->nextcmd;
	}
	exit(g_globe.exit_status);
}
