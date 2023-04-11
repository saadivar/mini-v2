/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:58:00 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/07 10:07:30 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	checkchar1(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+')
		return (0);
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_'
			&& ((s[i] == '=') && strlen(s) != 1))
			return (1);
		i++;
	}
	return (0);
}

int	ecrase(char *s, t_data **data, int *check)
{
	t_data	*tmp;
	char	*str;

	tmp = *data;
	str = bringaftertossawi(s);
	while (tmp)
	{
		if (ft_strncmp(tmp->content, s, *check) == 0
			&& ((ft_strncmp(tmp->content + *check, "=", 1) == 0)
				|| !(tmp->content[*check])))
		{
			tmp->content = ft_strjoin1(tmp->content, str);
			free(str);
			return (0);
		}
		tmp = tmp->next;
	}
	free(str);
	return (1);
}

int	checkingifexist(char *s, t_data **data)
{
	t_data	*tmp;
	char	*str;
	int		len;

	len = 0;
	str = bringbeforetossawi(s);
	tmp = *data;
	if (!(tmp))
		return (1);
	while (tmp)
	{
		if (!str)
			len = ft_strlen(s);
		else
			len = ft_strlen(str);
		if (strncmp(tmp->content, s, len) == 0)
		{
			free(str);
			return (0);
		}
		tmp = tmp->next;
	}
	free(str);
	return (1);
}

int	checkingifexist1(char *s, t_data **data, int l)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (strncmp(tmp->content, s, l) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	checknotexist(char *s, t_data **data, int len)
{
	t_data	*tmp;
	char	*str;

	len = 0;
	str = bringbeforetossawi(s);
	tmp = *data;
	while (tmp)
	{
		if (!str)
			len = ft_strlen(s);
		else
		{
			if (checkzaid(s) != 0)
				len = ft_strlen(str) - 1;
			else
				len = ft_strlen(str);
		}
		if (strncmp(tmp->content, s, len) == 0)
			return (free_export(str, 0));
		tmp = tmp->next;
	}
	return (free_export(str, -1));
}
