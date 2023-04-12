/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:40:37 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 03:00:27 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	usnet12(char **tmp, char **tmp1, char **str)
{
	*tmp = bringbeforetossawi(*str);
	*tmp1 = add_to_shlv(*str);
	*str = ft_strjoin1(*tmp, *tmp1);
	free(*tmp1);
}

void	ft_list_remove_if(t_data **begin_list, char *data_ref)
{
	t_data	*curr;
	t_data	*prev;

	curr = *begin_list;
	prev = NULL;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->content, data_ref, strlenhtal(curr->content)) == 0)
		{
			if (prev == NULL)
				*begin_list = curr->next;
			else
				prev->next = curr->next;
			(free(curr->content), free(curr));
			if (prev == NULL)
				curr = *begin_list;
			else
				curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

int	strlenhtal(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

int	isalphanum(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isalpha(s[i])) && !(ft_isdigit(s[i])) && s[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(t_shell *p, t_data **data)
{
	t_data	*tmp;
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	tmp = (*data);
	while (p->cmd[i])
	{
		if (isalphanum(p->cmd[i]))
			(printerr(p->cmd[0], p->cmd[i], "not a valid identifier"),
				flag = 1);
		tmp = (*data);
		while ((tmp))
		{
			if (strlenhtal(tmp->content) == ft_strlen(p->cmd[i])
				&& ft_strncmp(tmp->content, p->cmd[i],
					ft_strlen(p->cmd[i])) == 0)
				ft_list_remove_if(data, p->cmd[i]);
			tmp = tmp->next;
		}
		i++;
	}
	return (flag);
}
