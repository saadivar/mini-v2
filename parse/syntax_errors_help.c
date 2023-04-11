/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 07:13:56 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/11 06:59:11 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_errors(int index)
{
	if (index == 0)
		printf("minishell: syntax error near unexpected token `||'\n");
	else if (index == 1)
		printf("minishell: syntax error near unexpected token `>'\n");
	else if (index == 2)
		printf("minishell: syntax error near unexpected token `<'\n");
	else if (index == 3)
		printf("minishell: syntax error near unexpected token `|'\n");
	else if (index == 4)
		printf("minishell: syntax error near unexpected token `newline'\n");
	else if (index == 5)
		printf("minishell: syntax error in quotes!\n");
}

void	sing_helper(char *input, int *single, int *db)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == 34)
		{
			(*db)++;
			i++;
			while (input[i] && input[i] != 34)
				i++;
			if (input[i] == 34)
				(*db)++;
		}
		else if (input[i] == 39)
		{
			(*single)++;
			i++;
			while (input[i] && input[i] != 39)
				i++;
			if (input[i] == 39)
				(*single)++;
		}
		i++;
	}
}

int	single_double_quotes_counter(char *input, t_info count)
{
	count.single_counter = 0;
	count.double_counter = 0;
	sing_helper(input, &count.single_counter, &count.double_counter);
	if (count.single_counter % 2 != 0)
	{
		print_errors(5);
		return (0);
	}
	else if (count.double_counter % 2 != 0)
	{
		print_errors(5);
		return (0);
	}
	return (1);
}

int	only_spaces_there(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '|')
	{
		if (str[i] == 32)
			count++;
		i++;
	}
	if (count == i)
		return (0);
	return (1);
}

int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}
