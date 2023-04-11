/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:53:17 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/09 03:53:19 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strjoin10(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	p = (char *)malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
	{
		if (i <= ft_strlen1(s1))
			p[i] = s1[i];
	}
	j = -1;
	while (s2 && s2[++j])
	{
		if (i < ft_strlen1(s1) + ft_strlen1(s2))
			p[i] = s2[j];
		i++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}
