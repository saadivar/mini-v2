/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:19:02 by smounafi          #+#    #+#             */
/*   Updated: 2023/03/11 16:41:14 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_lstadd_front1(t_shell **lst, t_shell *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->nextcmd = *lst;
		*lst = new;
	}
}
