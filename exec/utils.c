/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:22:41 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/10 07:30:12 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*ft_lstnew(void *content)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->content = ft_strdup((char *)content);
	new->next = NULL;
	return (new);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_data	*sort_list(t_data *lst)
{
	char	*swap;
	t_data	*tmp;

	tmp = lst;
	if (ft_lstsize(tmp) < 1)
		return (lst);
	while (lst->next != NULL)
	{
		if (ft_strcmp(lst->content, lst->next->content) > 0)
		{
			swap = lst->content;
			lst->content = lst->next->content;
			lst->next->content = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		mid;

	if (!s1 || !s2)
		return (0);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	mid = i;
	i = 0;
	while (s2[i])
	{
		p[mid + i] = s2[i];
		i++;
	}
	p[mid + i] = '\0';
	return (p);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		mid;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s1[i] != '=')
		i++;
	p = (char *)malloc(sizeof(char) * (i + ft_strlen(s2) + 2));
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i] && s1[i] != '=')
		p[i] = s1[i];
	p[i++] = '=';
	mid = 0;
	while (s2[mid])
	{
		p[mid + i] = s2[mid];
		mid++;
	}
	p[mid + i] = '\0';
	free(s1);
	return (p);
}
