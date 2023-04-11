/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:54:22 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 02:35:33 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	returntossawi(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*bringaftertossawi(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	while (s[j] != '=')
		j++;
	str = malloc(i - j);
	j++;
	i = 0;
	while (s[j])
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	checktossawiplace(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

char	*bringbeforetossawi(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	i = checktossawiplace(s);
	if (i == 0)
		return (NULL);
	str = malloc(i + 1);
	i = 0;
	while (s[i] != '=')
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	joining(char *s, t_data **data, int *check)
{
	t_data	*tmp;
	char	*str;

	tmp = *data;
	str = bringaftertossawi(s);
	while (tmp)
	{
		if (strncmp(tmp->content, s, *check) == 0
			&& (tmp->content[*check] == '=' || tmp->content[*check] == '\0'))
		{
			if (!checktossawi(tmp->content))
				tmp->content = ft_strjoin10(tmp->content, str);
			else
			{
				tmp->content = ft_strjoin1(tmp->content, "=");
				tmp->content = ft_strjoin1(tmp->content, str);
			}
		}
		tmp = tmp->next;
	}
	free(str);
}
