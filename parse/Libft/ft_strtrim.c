/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:52:44 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 00:00:56 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_fill_trimmed(char *returned_str, char *s1, t_var *var)
{
	init_stuff(var);
	while (s1[var->i])
	{
		while (s1[var->i] && s1[var->i] != 34 && s1[var->i] != 39)
		{
			returned_str[var->j] = s1[var->i];
			var->i++;
			var->j++;
		}
		if (s1[var->i] == 34 || s1[var->i] == 39)
		{
			var->char_holder = s1[var->i];
			var->i++;
			while (s1[var->i] != var->char_holder)
			{
				returned_str[var->j] = s1[var->i];
				var->i++;
				var->j++;
			}
		}
		if (s1[var->i])
			var->i++;
	}
	return (returned_str);
}

void	skip_both_quotes(char s1, t_var *var)
{
	if (s1 == 34 || s1 == 39)
	{
		var->char_holder = s1;
		var->i++;
		while (s1 != var->char_holder)
		{
			var->i++;
			var->len++;
		}
	}
}

char	*ft_strtrim(char *s1, t_var *var)
{
	char	*returned_str;

	returned_str = NULL;
	init_stuff(var);
	if (!s1)
		return (NULL);
	while (s1[var->i])
	{
		while (s1[var->i] && s1[var->i] != 34 && s1[var->i] != 39)
		{
			var->len++;
			var->i++;
		}
		skip_both_quotes(s1[var->i], var);
		var->i++;
	}
	returned_str = malloc(var->len + 1);
	returned_str[var->len] = '\0';
	returned_str = ft_fill_trimmed(returned_str, s1, var);
	return (returned_str);
}
