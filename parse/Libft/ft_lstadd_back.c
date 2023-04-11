/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:54:57 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 03:55:03 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_shell	*ft_lstlast1(t_shell *lst)
{
	while (lst != NULL && lst->nextcmd != NULL)
		lst = lst->nextcmd;
	return (lst);
}

void	ft_lstadd_back1(t_shell **lst, t_shell *new)
{
	t_shell	*last_node;

	if (!*lst)
	{
		*lst = new;
		new->nextcmd = NULL;
	}
	else
	{
		last_node = ft_lstlast1(*lst);
		last_node->nextcmd = new;
	}
}
