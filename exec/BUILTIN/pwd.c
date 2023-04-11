/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:26:09 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/07 23:38:08 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*getz(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	return (s);
}

char	*getpwd(void)
{
	char	*tmp;
	char	*path;
	char	s[1024];
	char	*buff;

	tmp = getcwd(s, sizeof(s));
	if (tmp)
	{
		buff = strdup(tmp);
		return (buff);
	}
	else
	{
		path = getenv("PWD");
		if (path != NULL)
			return (path);
	}
	return (NULL);
}
