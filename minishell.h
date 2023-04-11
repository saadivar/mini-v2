/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:15:53 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/04/11 07:18:55 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>

typedef struct helper
{
	char			*holder;
	char			*tmp2;
	char			**stocker;
	char			*tmp1;
	char			**finale_holder;
	int				i;
}					t_helper;

typedef struct t_glob
{
	int				exit_status;
	int				*pid;
	int				nb_cmd;
}					t_glob;

t_glob				g_globe;

typedef struct t_vars
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	int				n;
	int				len;
	int				string_len;
	int				counter;
	char			char_holder;
	char			*dst;
	int				index;
	int				forfree;
	char			*exits;
	char			*tmp;
}					t_var;

typedef struct t_info
{
	int				fd_in;
	int				nb_heredocs;
	int				fd_out;
	int				fdd[2];
	int				**pipesfds;
	int				iter;
	int				cls;
	int				**herepipes;
	int				single_counter;
	int				double_counter;
	char			*input;
	char			**splited_string;
	char			*splited_str;
	char			*strfinal;
	int				nb_cmd;
	char			*pwd;
	char			**envir;
	int				i_exp;
	int				check;
	int				check1;
	int				flag;
	char			*sdhere;
	int				hhh;
	int				len;
	int				len1;
	int				iaia;
	int				jaja;
}					t_info;

typedef struct t_data
{
	char			*content;
	struct t_data	*next;

}					t_data;

typedef struct t_shell
{
	char			**cmd;
	char			**files;
	struct t_shell	*nextcmd;
	int				fdhere;
}					t_shell;

char				*add_to_shlv(char *s);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				check_files_ex(t_shell *shellcmd, t_info *info);
void				printerr2(char *s1, char *s2, char *s3);
int					ft_len(long n);
void				printerr1(char *s1, char *s2, char *s3);
void				communpart2222(t_shell *shellcmd, t_data **envp,
						t_info *info, int check);
void				wahexec(t_shell *shellcmd, t_info *info, t_data **envp);
void				helper_built(t_info *info);
char				*checkpath(char **str, t_shell *shellcmd);
char				**getpath(t_data **envp);
void				help_for3rd(t_info *info);
void				cnf_nsfd(char *s, int check, t_shell *shellcmd,
						t_info *info);
int					free_export(char *s, int i);
void				free_2d_array(char **arr);
char				*ft_get_environment(char *word, t_data *env);
void				print_errors(int index);
int					single_double_quotes_counter(char *input, t_info count);
int					only_spaces_there(char *str);
void				conver2d(t_data **envp, t_info *info);
void				sighandlequit(int sig);
void				sighandle1(int sig);
void				sighandle(int sig);
void				rl_replace_line(const char *s, int z);
int					ft_lstsize(t_data *lst);
void				ft_lstadd_back(t_data **lst, t_data *new);
t_data				*ft_lstlast(t_data *lst);
int					ft_strncmp(const char *s1, const char *s2, int n);
int					ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi_fd(char *str);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				iniiiit(t_info *info);
void				export_2(t_data **data, char *s, int *check);
void				export_1(t_data **data, char *s, int *check1, int *i);
char				*withoutp(char *s);
int					chekspecial(char *s);
int					checkchar1(char *s);
int					ecrase(char *s, t_data **data, int *check);
int					checkingifexist(char *s, t_data **data);
int					checkingifexist1(char *s, t_data **data, int l);
int					checknotexist(char *s, t_data **data, int len);
int					chekspecial(char *s);
int					returntossawi(char *s);
char				*bringaftertossawi(char *s);
int					checktossawiplace(char *s);
char				*bringbeforetossawi(char *s);
void				joining(char *s, t_data **data, int *check);
int					checkchar(char *s);
void				smt(int *i, int *check, int *flag);
void				checktossawiwzid(char *s);
void				printenvwithx(t_data **data);
int					checkzaid(char *s);
char				**ft_split1(char *dst);
void				*ft_calloc(int count, int size);
char				*ft_strjoin10(char *s1, char *s2);
int					ft_strlen1(const char *s);
char				*ft_substr(char *s, int start, int len);
int					ft_count_word(char *str, t_var *var);
char				**ft_split_wid_char(char *s, char c);
t_shell				*ft_lstnew1(char **cmd, char **files);
void				ft_lstadd_back1(t_shell **lst, t_shell *new);
void				ft_lstadd_front1(t_shell **lst, t_shell *new);
int					ft_echo(t_shell *p);
void				printerr(char *s1, char *s2, char *s3);
void				ft_exit(t_shell *p);
void				ft_list_remove_if(t_data **begin_list, char *data_ref);
t_data				*ft_lstnew(void *content);
void				ft_lstadd_back(t_data **lst, t_data *new);
t_data				*ft_lstlast(t_data *lst);
int					ft_strncmp(const char *s1, const char *s2, int n);
char				**set_cmd(char **cmd, int i);
void				trim_cmd(t_shell **shellcmds);
int					get_pipe_index(char **holder);
void				first_cmd(t_helper *help, t_var *var, t_shell **shellcmds);
void				print_errors(int index);
void				sing_helper(char *input, int *single, int *db);
int					single_double_quotes_counter(char *input, t_info count);
int					only_spaces_there(char *str);
int					ft_isalnum(int c);
int					find_dollar_if_exist(char *word, int i);
int					check_var(char *env, char *word, int i);
int					index_dollar(char *env, char *word, int i);
char				*if_not_var(char *word, char *env, int index);
void				init_staff_2(t_var *var, char *env, char *word, int j);
void				hold_help(t_var *var, char *env);
char				*hold_variable(char *word, char *env, int j);
int					countfilesss(char **splited);
int					count_total(char **splited);
void				add_helper_cmd(char **cmd, char **splited, int *i, int *j);
char				**addcmd(char **splited, int pose_pipe);
void				init_stuff(t_var *var);
int					contain_quotes(char *str, char c);
int					containn_quotes(char *str, char c);
int					contain_redir(char *str);
void				clean_quotes(t_shell *shellcmds, t_var var);
int					ft_strlen(const char *s);
int					ft_isdigit(int c);
int					char_pos(char *str);
int					ft_is_spec_char(int c);
int					first_char_found(char *str);
int					count_files(char *str);
int					ft_isalpha(int c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_atoi_fd(char *str);
char				**ft_replace_var_with_env_value(char **splitted_str,
						t_data *env);
char				*set_up_input(char *str, t_var *var);
char				*ft_convert_2d_to_str_and_separate(char **splited_string);
char				**extracting_files(char *holder, t_var *var);
t_shell				*split_to_stock_cmd(char **splitted_string,
						t_shell **shellcmds);
int					syntax_errors(char *input, t_var var, t_info *count);
int					ft_unset(t_shell *p, t_data **data);
int					isalphanum(char *s);
int					strlenhtal(char *s);
void				ft_list_remove_if(t_data **begin_list, char *data_ref);
void				convert(t_data **data, char **str);
int					ft_env(t_shell *p, t_data **data);
char				*getpwd(void);
int					ft_cd(t_shell *p, t_data **data);
t_data				*sort_list(t_data *lst);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_export(t_shell *p, t_data **data, t_info *info);
int					checktossawi(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin1(char *s1, char *s2);
char				*ft_strdup(const char *s1);
int					ecrase(char *s, t_data **data, int *check);
char				**ft_splitpath(char const *s, char c);
int					ft_lstsize(t_data *lst);
char				**ft_split(char *dst);
void				init_stuff(t_var *var);
char				*ft_strtrim(char *s1, t_var *var);
void				trim_cmd(t_shell **shellcmds);
void				exec1cmd(t_shell *shellcmds, t_data **envp, t_info *info);
void				execfirst(t_shell *shellcmds, t_data **envp, t_info *info);
void				execthird(t_shell *shellcmds, t_data **envp, t_info *info);
void				execsec(t_shell *shellcmds, t_data **envp, t_info *info);
void				execpar(t_shell *shellcmds, t_info *info);
void				waitingforall(t_info *info);
int					checkbuilins(char *s);
int					checkforfiles(t_shell *shellcmd, t_info *info);
void				execbuiltins(t_shell *shellcmd, t_data **envp,
						t_info *info);
void				execbuiltins1(t_shell *shellcmd, t_data **envp,
						t_info *info);
void				execnob(t_shell *shellcmd, t_data **envp, t_info *info);
void				execnob1(t_shell *shellcmd, t_data **envp, t_info *info);
void				execnob2(t_shell *shellcmd, t_data **envp, t_info *info);
void				execnob3(t_shell *shellcmd, t_data **envp, t_info *info);
int					communpartexec(t_shell *shellcmd, t_data **envp,
						t_info *info);
void				execvedyale(t_shell *shellcmd, t_data **envp, t_info *info);
void				ft_putendl_fd(char *s, int fd);
char				*getz(void);
char				*getmyenv(char *s, t_data **env);
void				chengingoldpwd(char *s, t_data **data);
int					whdfnccd(t_data **data);
char				*getsecondlast(char *s);
void				fcs(int *fd, char *s, t_data **env);
void				her(int i);
int					ft_heredoc(t_shell *shellcmds, t_info *info, t_data **env);
void				saving(t_shell *shellcmds, t_info *info);
void				executions(t_shell *shellcmds, t_data **envp, t_info *info);
void				sighandle(int sig);
void				sighandle1(int sig);
void				sighandlequit(int sig);
void				free_2d_array(char **arr);
void				freelinkedlist(t_shell *head);
void				freestruct(t_info *info);
int					calculcmds(t_shell *shell);
int					calculheredocs(t_shell *shell);
int					**creatpipes(int number);
void				creatpids(int number);
int					**createherepipes(int number);
void				declaring(t_info **info, t_shell **shellcmds, t_var **var);
void				multipipes(t_shell *shellcmds, t_data **envp, t_info *info);
int					checkfordollar(char *s);
void				init_info(t_shell *shellcmds, t_data **envp, t_info *info);
void				child_heredoc(t_shell *shellcmds, t_info *info,
						t_data **env);
void				child(t_shell *shellcmd, t_data **envp, t_info *info);
void				papa(void);
void				execvedyale1(t_shell *shellcmd, t_data **envp,
						t_info *info);
#endif