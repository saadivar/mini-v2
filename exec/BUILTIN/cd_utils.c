/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:50:31 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/12 21:08:49 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*getmyenv(char *s, t_data **env)
{
	t_data	*tmp;
	char	*str;

	if (!(*env)->content)
		return (NULL);
	tmp = *env;
	str = ft_calloc(1, 1);
	while (tmp)
	{
		if (ft_strncmp(s, tmp->content, ft_strlen(s)) == 0)
		{
			str = ft_strjoin10(str, tmp->content + ft_strlen(s) + 1);
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*getsecondlast(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	i -= 1;
	while (i > 0 && s[i] != '/')
		i--;
	str = malloc(i + 1);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*helper(char *s)
{
	char	*s1;
	char	*s2;

	s1 = s;
	s2 = getpwd();
	s = ft_strjoin("PWD=", s2);
	(free(s1), free(s2));
	return (s);
}

void	chengingoldpwd(char *s, t_data **data)
{
	t_data	*tmp;
	int		count;
	char	*s1;

	count = 0;
	tmp = *data;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "OLDPWD", 6) == 0)
		{
			s1 = tmp->content;
			tmp->content = ft_strjoin("OLDPWD=", s);
			free(s1);
			count++;
		}
		else if (ft_strncmp(tmp->content, "PWD=", 4) == 0)
		{
			tmp->content = helper(tmp->content);
			count++;
		}
		if (count == 2)
			break ;
		tmp = tmp->next;
	}
}

int	whdfnccd(t_data **data)
{
	char	*oldpwd;

	oldpwd = getpwd();
	chdir("..");
	if ((*data)->content)
		chengingoldpwd(oldpwd, data);
	free(oldpwd);
	return (1);
}
