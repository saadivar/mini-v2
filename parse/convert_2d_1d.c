/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_2d_1d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:36:02 by smounafi          #+#    #+#             */
/*   Updated: 2023/04/11 02:33:15 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_convert_2d_to_str_and_separate(char **splited_string)
{
	int		y;
	char	*holder;

	holder = ft_calloc(1, 1);
	y = 0;
	while (splited_string[y])
	{
		if (splited_string[y][0] == 0)
		{
			splited_string[y] = ft_strjoin10(splited_string[y], "");
		}
		holder = ft_strjoin10(holder, splited_string[y]);
		holder = ft_strjoin10(holder, " ");
		y++;
	}
	holder[ft_strlen(holder)] = '\0';
	return (holder);
}
