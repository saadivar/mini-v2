/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:54:35 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 03:54:47 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_shell	*ft_lstnew1(char **cmd, char **files)
{
	t_shell	*nd;

	nd = malloc(sizeof(t_shell));
	if (!nd)
		return (0);
	nd->cmd = cmd;
	nd->files = files;
	nd->nextcmd = NULL;
	return (nd);
}
