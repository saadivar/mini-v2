/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_help1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 07:22:54 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 07:35:26 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_staff_2(t_var *var, char *env, char *word, int j)
{
	var->i = 0;
	var->j = 0;
	var->x = 0;
	var->string_len = check_var(env, word, j);
	var->len = ft_strlen(word);
}

void	hold_help(t_var *var, char *env)
{
	while (env[var->i] != '=')
		var->i++;
	var->j = var->i + 1;
	var->x = var->string_len + var->i + 1;
	var->len -= var->i;
	while (env[++var->i])
		var->len++;
	var->dst = (char *)malloc(var->len);
	var->len = 0;
}

char	*hold_variable(char *word, char *env, int j)
{
	t_var	*var;
	char	*tmp;

	var = (t_var *)malloc(sizeof(t_var));
	init_staff_2(var, env, word, j);
	hold_help(var, env);
	while (var->len < var->string_len)
	{
		var->dst[var->len] = word[var->len];
		var->len++;
	}
	while (env[var->j])
		var->dst[var->len++] = env[var->j++];
	while (word[var->x])
		var->dst[var->len++] = word[var->x++];
	var->dst[var->len] = '\0';
	free(word);
	tmp = var->dst;
	free(var);
	return (tmp);
}
