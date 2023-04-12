/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:58:46 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 05:17:06 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	convert(t_data **data, char **str)
{
	int		i;
	char	*tmp;
	char	*tmp1;

	i = -1;
	if (!str[0])
	{
		tmp1 = getpwd();
		tmp = ft_strjoin("PWD=", tmp1);
		ft_lstadd_back(data, ft_lstnew(tmp));
		(free(tmp), free(tmp1));
		ft_lstadd_back(data, ft_lstnew("OLDPWD"));
		ft_lstadd_back(data, ft_lstnew("SHLVL=1"));
	}
	else
	{
		while (str[++i])
		{
			if (ft_strncmp(str[i], "SHLVL=", 6) == 0)
				usnet12(&tmp, &tmp1, &str[i]);
			ft_lstadd_back(data, ft_lstnew(str[i]));
		}
	}
}

void	init_stuff(t_var *var)
{
	var->x = 0;
	var->y = 0;
	var->i = 0;
	var->j = 0;
	var->k = 0;
	var->m = 0;
	var->n = 0;
	var->l = 0;
	var->index = 0;
	var->len = 0;
	var->counter = 0;
}
