/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:53:31 by smounafi          #+#    #+#             */
/*   Updated: 2023/04/11 07:22:20 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	syntax2(char *input, int *i)
{
	if (input[(*i)] == 0)
		print_errors(4);
	else if (input[(*i)] == '<')
		print_errors(2);
	else if (input[(*i)] == '>')
		print_errors(1);
	else if (input[(*i)] == '|')
		print_errors(3);
}

int	syntax_helper(char *input, int *i)
{
	if (input[(*i)] == '<' || input[(*i)] == '>')
	{
		if (input[(*i) - 1] == '<' && input[(*i)] == '>')
		{
			print_errors(1);
			return (0);
		}
		else if (input[(*i) - 1] == '>' && input[(*i)] == '<')
		{
			print_errors(2);
			return (0);
		}
		(*i)++;
	}
	while (input[(*i)] && input[(*i)] == 32)
		(*i)++;
	if (input[(*i)] == 0 || input[(*i)] == '<' || input[(*i)] == '>'
		|| input[(*i)] == '|')
	{
		syntax2(input, i);
		return (0);
	}
	return (1);
}

int	syntax_helper2(char *input, int *i)
{
	if ((input[(*i)] == '<' && input[(*i) + 1] == '|') || (input[(*i)] == '>'
			&& input[(*i) + 1] == '|'))
	{
		print_errors(3);
		return (0);
	}
	(*i)++;
	if (input[(*i)] == '\0')
	{
		print_errors(4);
		return (0);
	}
	if (input[(*i)] == '<' || input[(*i)] == '>' || input[(*i)] == 32)
	{
		if (!syntax_helper(input, i))
			return (0);
	}
	return (1);
}

int	syn_help(char **input, t_var *var)
{
	if ((*input)[var->i] == '|' && (*input)[var->i + 1] == '|')
	{
		print_errors(0);
		var->j = 1;
		return (0);
	}
	else if (((*input)[0] == '|' || (*input)[ft_strlen((*input)) - 1] == '|'
				|| ((*input)[var->i] == '|' && !only_spaces_there((*input)
						+ var->i + 1))) && var->j == 0)
	{
		print_errors(3);
		var->j = 1;
		return (0);
	}
	else if ((*input)[var->i] == '<' || (*input)[var->i] == '>')
		if (!syntax_helper2((*input), &var->i))
			return (0);
	return (1);
}

int	syntax_errors(char *input, t_var var, t_info *count)
{
	char	s;

	init_stuff(&var);
	if (single_double_quotes_counter(input, *count) == 0)
		return (0);
	while (input[var.i])
	{
		if (input[var.i] == 34 || input[var.i] == 39)
		{
			s = input[var.i];
			var.i++;
			while (input[var.i] && input[var.i] != s)
				var.i++;
		}
		if (!syn_help(&input, &var))
			return (0);
		var.i++;
	}
	return (1);
}
