/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:49:48 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 08:24:01 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	chekspecial(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_'
			&& (s[i] != '=') && (s[i] != '+'))
			return (0);
		i++;
	}
	return (1);
}

char	*withoutp(char *s)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i] != '+')
		i++;
	str = malloc(i + 1);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	str = ft_strjoin10(str, s + i + 1);
	return (str);
}

void	export_1(t_data **data, char *s, int *check1, int *i)
{
	if (checkchar(s) == 1)
		printerr1("export", s, "not a valid identifier");
	else if (checkingifexist1(s, data, *check1) == 0)
	{
		if (ecrase(s, data, check1) == 1)
			ft_lstadd_back(data, ft_lstnew(s));
		g_globe.exit_status = 0;
	}
	else if (checkingifexist(s, data) == 0)
	{
		(*i)++;
		g_globe.exit_status = 0;
	}
	else
	{
		ft_lstadd_back(data, ft_lstnew(s));
		g_globe.exit_status = 0;
	}
}

void	export_2(t_data **data, char *s, int *check)
{
	char	*str;

	if (checknotexist(s, data, *check) == -1)
	{
		str = withoutp(s);
		ft_lstadd_back(data, ft_lstnew(str));
		g_globe.exit_status = 0;
		free(str);
	}
	else
	{
		joining(s, data, check);
		g_globe.exit_status = 0;
	}
}

void	iniiiit(t_info *info)
{
	info->check = 0;
	info->check1 = 0;
	info->i_exp = 1;
}
