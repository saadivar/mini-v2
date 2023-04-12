/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 07:21:47 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 21:14:58 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}

int	find_dollar_if_exist(char *word, int i)
{
	int	j;

	j = 0;
	while (word[j])
	{
		if (word[j] == 34)
		{
			j++;
			while (word[j] && word[j] != 34 && word[j] != '$')
				j++;
		}
		if (word[j] == '$' && j >= i)
			return (j);
		if (word[j] == 39)
		{
			j++;
			while (word[j] && word[j] != 39)
				j++;
		}
		j++;
	}
	return (j);
}

int	check_var(char *env, char *word, int i)
{
	int	a;

	while (word[i])
	{
		i = find_dollar_if_exist(word, i);
		while (word[i] && word[i + 1] == '$')
			i++;
		a = -1;
		while (env[++a] != '=' && word[i] && env[a] == word[i + 1])
			i++;
		if (word[i] == '$' && word[i + 1] == '?')
			return (i + 2);
		if ((env[a] == '=' && (env[a - 1] == word[i]) && (!word[i + 1]
					|| (!ft_isalnum(word[i + 1]) && (word[i + 1] != '_')))))
			return (i - a);
		if (word[i - a] == '$' && (ft_isalnum(word[i - a + 1]) || word[i - a
					+ 1] == '_'))
			return (-1);
		if (word[i])
			i++;
	}
	return (-2);
}

int	index_dollar(char *env, char *word, int i)
{
	int	a;

	while (word[i])
	{
		i = find_dollar_if_exist(word, i);
		while (word[i + 1] == '$')
			i++;
		a = 0;
		while (env[a] != '=' && word[i] && env[a] == word[i + 1])
		{
			a++;
			i++;
		}
		if (word[i - a] == '$' && (ft_isalnum(word[i - a + 1]) || word[i - a
					+ 1] == '_'))
			return (i - a);
		if (word[i])
			i++;
	}
	return (0);
}

char	*if_not_var(char *word, char *env, int index)
{
	t_var	var;

	var.i = 0;
	var.j = 0;
	var.string_len = index_dollar(env, word, index) + 1;
	var.x = 0;
	var.len = ft_strlen(word);
	while (word[var.string_len] && (ft_isalnum(word[var.string_len])
			|| word[var.string_len] == '_'))
	{
		var.i++;
		var.string_len++;
	}
	var.dst = (char *)malloc(var.len - var.i);
	var.string_len -= (var.i);
	while (var.j < var.string_len - 1)
		var.dst[var.x++] = word[var.j++];
	var.j += var.i + 1;
	while (word[var.j])
		var.dst[var.x++] = word[var.j++];
	var.dst[var.x] = '\0';
	free(word);
	return (var.dst);
}
