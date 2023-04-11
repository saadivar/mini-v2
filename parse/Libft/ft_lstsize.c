/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:19:32 by smounafi          #+#    #+#             */
/*   Updated: 2023/04/09 03:54:28 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_lstsize1(t_shell *lst)
{
	int		i;
	t_shell	*new;

	i = 0;
	new = lst;
	while (new != NULL)
	{
		new = new->nextcmd;
		i++;
	}
	return (i);
}
