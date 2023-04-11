/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:39:39 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 22:31:02 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	helper_pwd(void)
{
	char	*tmp;

	tmp = getpwd();
	ft_putendl_fd(tmp, 1);
	free(tmp);
}

void	execbuiltins(t_shell *shellcmd, t_data **envp, t_info *info)
{
	if (checkforfiles(shellcmd, info) == -2)
		return ;
	if (info->fd_in != -2)
		dup2(info->fd_in, 0);
	if (info->fd_out != -2)
		dup2(info->fd_out, 1);
	if (!strcmp(shellcmd->cmd[0], "echo"))
		g_globe.exit_status = ft_echo(shellcmd);
	else if (!strcmp(shellcmd->cmd[0], "cd") || !strcmp(shellcmd->cmd[0], "CD"))
		g_globe.exit_status = ft_cd(shellcmd, envp);
	else if (!strcmp(shellcmd->cmd[0], "export"))
		ft_export (shellcmd, envp, info);
	else if (!strcmp(shellcmd->cmd[0], "unset"))
		g_globe.exit_status = ft_unset(shellcmd, envp);
	else if (!strcmp(shellcmd->cmd[0], "exit"))
		ft_exit(shellcmd);
	else if (!strcmp(shellcmd->cmd[0], "env"))
		g_globe.exit_status = ft_env(shellcmd, envp);
	else if (!strcmp(shellcmd->cmd[0], "pwd"))
		helper_pwd();
	helper_built(info);
}

void	execbuiltins1(t_shell *shellcmd, t_data **envp, t_info *info)
{
	if (checkforfiles(shellcmd, info) == -2)
		exit(0);
	if (info->fd_in != -2)
		dup2(info->fd_in, 0);
	if (info->fd_out != -2)
		dup2(info->fd_out, 1);
	if (!strcmp(shellcmd->cmd[0], "echo"))
		g_globe.exit_status = ft_echo(shellcmd);
	else if (!strcmp(shellcmd->cmd[0], "cd"))
		g_globe.exit_status = ft_cd(shellcmd, envp);
	else if (!strcmp(shellcmd->cmd[0], "export"))
		ft_export(shellcmd, envp, info);
	else if (!strcmp(shellcmd->cmd[0], "unset"))
		g_globe.exit_status = ft_unset(shellcmd, envp);
	else if (!strcmp(shellcmd->cmd[0], "exit"))
		ft_exit(shellcmd);
	else if (!strcmp(shellcmd->cmd[0], "env"))
		g_globe.exit_status = ft_env(shellcmd, envp);
	else if (!strcmp(shellcmd->cmd[0], "pwd"))
		printf("%s\n", getpwd());
}

char	**getpath( t_data **envp)
{
	t_data	*env;
	char	**str;

	env = *envp;
	if (!(*envp)->content)
		return (NULL);
	while (env)
	{
		if (strncmp(env->content, "PATH=", 5) == 0)
		{
			str = ft_splitpath(env->content + 5, ':');
			break ;
		}
		env = env->next;
	}
	if (!env)
		return (NULL);
	return (str);
}

char	*checkpath(char **str, t_shell *shellcmd)
{
	char	*strfinal;
	char	*s;
	char	*s1;
	int		i;

	i = 0;
	strfinal = NULL;
	s = ft_strjoin("/", shellcmd->cmd[0]);
	while (str[i])
	{
		s1 = ft_strjoin(str[i], s);
		if (!(access(s1, X_OK)))
		{
			strfinal = (ft_strjoin(str[i], s));
			free(s);
			free(s1);
			break ;
		}
		free(s1);
		i++;
	}
	if (!str[i])
		free(s);
	return (strfinal);
}
