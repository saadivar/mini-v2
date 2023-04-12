/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:30:57 by smounafi          #+#    #+#             */
/*   Updated: 2023/04/12 05:18:27 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = ft_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (num == 0)
	{
		str[0] = '0';
	}
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

void	env_helper(char **word, t_data **env, t_data *head, t_var *var)
{
	if ((*env)->next == NULL && var->i == -1)
	{
		var->i = index_dollar((*env)->content, *word, var->j);
		*word = if_not_var((*word), (*env)->content, var->j);
		(*env) = head;
	}
	if (var->i < 0)
	{
		var->i = var->j;
		*env = (*env)->next;
	}
}

void	env_helper1(char **word, t_data **env, t_var *var)
{
	char	*s;

	s = ft_get_environment(ft_substr(*word, var->i, (ft_strlen(*word)
					- var->i)), *env);
	var->tmp = *word;
	var->exits = ft_itoa(g_globe.exit_status);
	*word = ft_strjoin10(ft_substr((*word), 0, var->i - 2), var->exits);
	free(var->tmp);
	free(var->exits);
	*word = ft_strjoin10(*word, s);
	free(s);
}

char	*ft_get_environment(char *word, t_data *env)
{
	t_var	var;
	t_data	*head;

	init_stuff(&var);
	head = env;
	while (env)
	{
		var.j = var.i;
		var.i = check_var(env->content, word, var.i);
		if (var.i >= 0)
		{
			if (word[var.i - 1] == '?' && word[var.i - 2] == '$')
				env_helper1(&word, &env, &var);
			else
				word = hold_variable(word, env->content, var.i);
			env = head;
		}
		env_helper(&word, &env, head, &var);
	}
	return (word);
}

char	**ft_replace_var_with_env_value(char **splitted_str, t_data *env)
{
	t_var	*var;
	t_data	*tmp;

	var = malloc(sizeof(t_var));
	init_stuff(var);
	tmp = env;
	while (splitted_str[var->y])
	{
		if (!ft_strcmp(splitted_str[var->y], "<<"))
		{
			var->y++;
			if (splitted_str[var->y])
				var->y++;
		}
		else
		{
			splitted_str[var->y] = ft_get_environment(splitted_str[var->y],
					env);
			var->y++;
		}
	}
	free(var);
	return (splitted_str);
}
