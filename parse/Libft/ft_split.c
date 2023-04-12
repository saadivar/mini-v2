/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:53:49 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 00:00:12 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_count_word(char *str, t_var *var)
{
	init_stuff(var);
	while (str[var->i])
	{
		if (str[var->i] == 34 || str[var->i] == 39)
		{
			var->i++;
			while (str[var->i] && str[var->i] != 34 && str[var->i] != 39)
				var->i++;
		}
		if (var->j == 0 && str[var->i] != ' ' && str[var->i] != '\t'
			&& str[var->i] != '\n')
		{
			var->j = 1;
			var->counter++;
		}
		else if (var->j == 1 && (str[var->i] == ' ' || str[var->i] == '\t'
				|| str[var->i] == '\n'))
			var->j = 0;
		var->i++;
	}
	return (var->counter);
}

char	*fill_word(char *str, t_var *var)
{
	char	*s1;
	char	c;

	init_stuff(var);
	while (str[var->j] && str[var->j] != ' ' && str[var->j] != '\t'
		&& str[var->j] != '\n')
	{
		if (str[var->j] == 34 || str[var->j] == 39)
		{
			c = str[var->j];
			var->j++;
			while (str[var->j] && str[var->j] != c)
				var->j++;
		}
		var->j++;
	}
	s1 = malloc(var->j + 1);
	while (var->i < var->j)
	{
		s1[var->i] = str[var->i];
		var->i++;
	}
	s1[var->i] = '\0';
	return (s1);
}

char	*skip_single_double_quotes(char *str)
{
	char	c;

	if (*str == 34 || *str == 39)
	{
		c = *str;
		str++;
		while (*str && *str != c)
			str++;
	}
	return (str);
}

char	**ft_split(char *str)
{
	int		i;
	char	**split;
	int		count;
	t_var	var;

	i = 0;
	count = ft_count_word(str, &var);
	split = malloc((sizeof(char *) * (count + 1)));
	while (*str && i < count)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		split[i] = fill_word(str, &var);
		i++;
		while (*str && (*str != ' ' && *str != '\t' && *str != '\n'))
		{
			str = skip_single_double_quotes(str);
			str++;
		}
	}
	split[i] = 0;
	return (split);
}
