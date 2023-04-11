/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:53:30 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/07 23:52:22 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	help_exp(char *s, int flag)
{
	int	i;

	i = 0;
	if (!ft_isalpha(s[0]) && s[0] != '_')
	{
		if (flag == 0)
			free(s);
		return (1);
	}
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_'
			&& (s[i] != '='))
		{
			if (flag == 0)
				free(s);
			return (1);
		}
		i++;
	}
	return (0);
}

int	checkchar(char *str)
{
	int		i;
	char	*s;
	int		flag;

	flag = 0;
	i = 0;
	s = bringbeforetossawi(str);
	if (s == NULL)
	{
		(s = str);
		(flag = 1);
	}
	if (help_exp(s, flag))
		return (1);
	if (flag == 0)
		free(s);
	return (0);
}

void	smt(int *i, int *check, int *flag)
{
	ft_putchar_fd('=', 1);
	if (*flag == 0)
		ft_putchar_fd('"', 1);
	(*i)++;
	*check = 1;
	*flag = 1;
}

void	checktossawiwzid(char *s)
{
	int	i;
	int	check;
	int	flag;

	i = 0;
	check = 0;
	flag = 0;
	ft_putstr_fd("declare -x ", 1);
	while (s[i])
	{
		if (s[i] != '=')
			ft_putchar_fd(s[i++], 1);
		else
			smt(&i, &check, &flag);
	}
	if (s[i] == '\0' && check == 1)
		ft_putchar_fd('"', 1);
	ft_putchar_fd('\n', 1);
}

void	printenvwithx(t_data **data)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		checktossawiwzid(tmp->content);
		tmp = tmp->next;
	}
}
