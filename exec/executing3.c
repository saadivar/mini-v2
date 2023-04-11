/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:13:08 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/11 02:56:24 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cnf_nsfd(char *s, int check, t_shell *shellcmd, t_info *info)
{
	checkforfiles(shellcmd, info);
	if (check == 1)
	{
		printerr("bash", s, "No such file or directory");
		exit(127);
	}
	else if (check == 2)
	{
		printerr("bash", s, "command not found");
		exit(127);
	}
}

void	conver2d(t_data **envp, t_info *info)
{
	int		i;
	t_data	*tmp;

	tmp = *envp;
	i = ft_lstsize(tmp);
	info->envir = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp)
	{
		info->envir[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	info->envir[i] = NULL;
}

int	free_export(char *s, int i)
{
	free(s);
	return (i);
}
