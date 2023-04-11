/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:24:19 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/11 04:49:54 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sighandle(int sig)
{
	(void)sig;
	g_globe.exit_status = 1;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sighandle1(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

void	sighandlequit(int sig)
{
	(void)sig;
	write(1, "QUIT: 3\n", 9);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	freelinkedlist(t_shell *head)
{
	t_shell	*tmp;
	int		i;

	i = 0;
	while (head)
	{
		if (head->cmd)
			free_2d_array(head->cmd);
		if (head->files)
			free_2d_array(head->files);
		tmp = head;
		head = head->nextcmd;
		free(tmp);
	}
}
