/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_up_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:33:58 by smounafi          #+#    #+#             */
/*   Updated: 2023/04/11 07:21:41 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_spacial_characters(char *str, t_var *var)
{
	int	counter;

	counter = 0;
	init_stuff(var);
	while (str[var->i])
	{
		if ((str[var->i] == '<' && str[var->i + 1] == '<')
			|| (str[var->i] == '>' && str[var->i + 1] == '>'))
			var->i++;
		if (str[var->i] == '<' || str[var->i] == '>' || str[var->i] == '|')
			counter++;
		var->i++;
	}
	return (counter);
}

void	hel_set_input(char *input, char *str, t_var *var)
{
	input[var->j] = ' ';
	var->j++;
	input[var->j] = str[var->i];
	var->i++;
	var->j++;
	input[var->j] = str[var->i];
	var->i++;
	var->j++;
	input[var->j] = ' ';
	var->j++;
}

void	hel_set_input1(char *input, char *str, t_var *var)
{
	input[var->j] = ' ';
	var->j++;
	input[var->j] = str[var->i];
	var->i++;
	var->j++;
	input[var->j] = ' ';
	var->j++;
}

char	*set_up_input(char *str, t_var *var)
{
	char	*input;
	int		counter;

	counter = count_spacial_characters(str, var) * 2;
	init_stuff(var);
	var->len = ft_strlen(str);
	input = malloc(var->len + counter + 1);
	while (var->j < var->len + counter && str[var->i])
	{
		//forfix skipping
		if ((str[var->i] == '<' && str[var->i + 1] == '<')
			|| (str[var->i] == '>' && str[var->i + 1] == '>'))
			hel_set_input(input, str, var);
		else if ((str[var->i] == '<' || str[var->i] == '>'
				|| str[var->i] == '|'))
			hel_set_input1(input, str, var);
		else
			input[var->j++] = str[var->i++];
	}
	input[var->j] = '\0';
	return (input);
}
