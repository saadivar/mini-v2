/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:39:00 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 05:20:01 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	noarg(t_shell *p, t_data **data)
{
	char	*oldpwd;
	char	*home;

	oldpwd = getpwd();
	home = getmyenv("HOME", data);
	if (!home)
	{
		free(oldpwd);
		printerr("bash", p->cmd[0], "HOME not set");
		return (0);
	}
	chdir(home);
	chengingoldpwd(oldpwd, data);
	free(home);
	free(oldpwd);
	return (1);
}

int	whdfnccd100(t_shell *p, t_data **data)
{
	char	*oldpwd;
	int		dir;

	dir = 0;
	oldpwd = getpwd();
	chengingoldpwd(oldpwd, data);
	dir = chdir(p->cmd[1]);
	if (dir == -1)
	{
		printerr(p->cmd[0], p->cmd[1], "No such file or directory");
		free(oldpwd);
		return (1);
	}
	free(oldpwd);
	return (1);
}

int	ft_cd(t_shell *p, t_data **data)
{
	char	*oldpwd;

	if (ft_strcmp(p->cmd[0], "CD") == 0)
		return (0);
	if (p->cmd[1] == NULL)
		return (noarg(p, data));
	else
	{
		if (ft_strncmp(".", p->cmd[1], 1) == 0 && p->cmd[1][1] == '\0')
		{
			oldpwd = getz();
			if (!oldpwd)
				ft_putstr_fd("cd: error retrieving current directory: \
					getcwd: cannot access\
					parent directories: No such file or directory\n", 2);
			else
				free(oldpwd);
			return (1);
		}
		else if (ft_strncmp("..", p->cmd[1], 2) == 0 && p->cmd[1][2] == '\0')
			return (whdfnccd(data));
		else
			return (whdfnccd100(p, data));
	}
	return (0);
}
