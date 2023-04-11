/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:39:07 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 22:44:47 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	iniiiit1(t_info *info, char *s)
{
	info->check = checkzaid(s);
	info->check1 = checktossawiplace(s);
}

int	export_3(t_data **data, char *s)
{
	if (!s[0])
	{
		printerr1("export", s, "not a valid identifier");
		return (1);
	}
	else if (checkingifexist(s, data) == 0)
	{
		g_globe.exit_status = 0;
		return (1);
	}
	else
	{
		if (checkchar(s) == 1)
		{
			printerr1("export", s, "not a valid identifier");
			return (1);
		}
		else
		{
			ft_lstadd_back(data, ft_lstnew(s));
			g_globe.exit_status = 0;
		}
	}
	return (0);
}

void	export_4(t_data **data, t_shell *p, t_info *info)
{
	while (p->cmd[info->i_exp])
	{
		iniiiit1(info, p->cmd[info->i_exp]);
		if (info->check == 0 && checktossawi(p->cmd[info->i_exp]) == 1)
		{
			if (export_3(data, p->cmd[info->i_exp]) == 1)
			{
				info->i_exp++;
				continue ;
			}
		}
		else if (info->check == -1)
		{
			if (checkchar(p->cmd[info->i_exp]) == 1)
			{
				printerr1(p->cmd[0], p->cmd[info->i_exp],
					"not a valid identifier");
			}
		}
		else if (info->check == 0 && checktossawi(p->cmd[info->i_exp]) == 0)
			export_1(data, p->cmd[info->i_exp], &info->check1, &info->i_exp);
		else if (info->check != 0 && info->check != -1)
			export_2(data, p->cmd[info->i_exp], &info->check);
		info->i_exp++;
	}
}

void	ft_export(t_shell *p, t_data **data, t_info *info)
{
	iniiiit(info);
	if (p->cmd[1] == NULL)
	{
		(sort_list(*data), printenvwithx(data));
		g_globe.exit_status = 0;
	}
	else
		export_4(data, p, info);
}
