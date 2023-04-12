/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:02:04 by smounafi          #+#    #+#             */
/*   Updated: 2023/04/12 02:50:04 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void	parsing(t_info *info, t_var *var, t_shell **shellcmds, t_data *envp)
{
	info->splited_str = set_up_input(info->input, var);
	info->splited_string = ft_split(info->splited_str);
	info->splited_string = ft_replace_var_with_env_value(info->splited_string,
			envp);
	*shellcmds = split_to_stock_cmd(info->splited_string,
			shellcmds);
	clean_quotes(*shellcmds);
	free(info->splited_str);
	if (info->splited_string)
		free_2d_array(info->splited_string);
}

void	signalsss(t_info *info)
{
	struct termios	term;
	struct termios	oldterm;

	signal(SIGINT, sighandle);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(0, &term);
	tcgetattr(0, &oldterm);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
	info->input = readline("minishell> ");
	tcsetattr(0, TCSANOW, &oldterm);
}

int	main(int ac, char **av, char **env)
{
	t_info	*info;
	t_data	*envp;
	t_shell	*shellcmds;
	t_var	*var;

	(void)ac, (void)av;
	(convert(&envp, env), declaring(&info, &shellcmds, &var));
	while (1)
	{
		(init_stuff(var), signalsss(info));
		if (info->input == NULL)
			(write(1, "exit\n", 5), exit(g_globe.exit_status));
		if (info->input && *info->input)
		{
			add_history(info->input);
			var->m = syntax_errors(info->input, *var, info);
			if (var->m == 0)
				g_globe.exit_status = 258;
			if (var->m == 1)
				(parsing(info, var, &shellcmds, envp), executions(shellcmds,
						&envp, info));
		}
		free(info->input);
	}
	return (0);
}
