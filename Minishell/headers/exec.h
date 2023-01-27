/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:28:12 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/22 20:30:54 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# define INTERACTIVE 0
# define PARENT_PROCESS 1
# define CHILD_PROCESS 2
# define HEREDOC 3

typedef struct s_heredoc
{
	int		nb;
	int		cpt;
	int		cpt_file;
	int		cpt_close;
	int		*tab_fd;
	char	**tab_of_name_file;
	char	**tab_exit_code;
}	t_heredoc;

typedef struct s_pipe
{
	char	*cmd;
	char	**cmd_splited;
	char	*path_cmd;
	int		fd_pipe[2];
	int		prev;
	int		nb_pipe;
}	t_pipe;

typedef struct s_exec
{
	t_heredoc	hd;
	t_pipe		pipe;
	char		**env;
	int			nb_execution;
	int			status;
}	t_exec;

//libft
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_string(char *s);
void	free_tab(char **t);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(int fd, char *s);
void	ft_putnbr_fd(int n, int fd);
int		free_tab_error(char **t, int n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_strncmp(char *str1, char *str2, int n);
char	*ft_strndup(char *str, unsigned int n);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2, int index_free);
char	*ft_strdup(const char *s);
char	**ft_tabdup(char **tab);
char	**split(char *s, char sep);
//env.c
void	replace_shlvl(char **new_env);
char	**set_empty_env(void);
char	**set_env(char **env);
//error.c
void	print_error_heredoc(t_exec *exec, int pos);
int		print_error(char *s);
int		print_error_cmd(t_exec *exec);
int		error_export(char *s);
//utils.c
void	replace_string_on_tab(char **t, int i, char *s);
void	close_and_wait(t_exec *exec, int nb_pipe);
int		count_nb_pipe(t_data *data);
int		find_index(char *str, char c);
t_data	*pass_hold_pipe(t_data *data, int cpt_pipe);
//exec.c
int		execution(t_data *data, t_exec *exec);
int		load_pipe(t_data *data, t_exec	*exec, int cpt_pipe);
//heredoc_init.c
int		init_file_heredoc(t_exec *exec);
int		init_tab_exitcode(t_data *data, t_exec *exec);
int		count_nb_heredoc(t_data *data);
int		load_heredoc(t_data *data, t_exec *exec);
void	feature(t_exec *exec, t_data *slot);
//heredoc.c
int		create_file(char *filename, t_exec *exec);
int		to_fill_heredoc(int i, t_exec *exec);
int		heredoc(t_exec *exec, int i);
char	*add_contents(char *contents, char *s);
char	*gen_name(t_exec *exec, int i);
//expand_heredoc.c
char	*ft_heredoc_expand(char *str, char **env);
//free_struct.c
void	free_heredoc(t_exec *exec);
void	free_pipe(t_exec *exec);
int		free_history_end(t_exec *exec, t_data *data, int i);
//get_cmd.c
int		is_cat_cmd(t_data *data);
int		get_cmd(t_data	*slot, t_exec *exec);
int		load_struct_pipe(t_data	*data, t_exec *exec, int cpt_pipe);
char	*getpath(char *cmd, char **env);
char	*path_join(char *path, char *bin);
//redir.c
int		is_redir(t_data *slot);
int		openfile(char *filename, int mode);
int		do_redir(int redir, char *str, t_exec *exec);
int		redir(t_data *data, t_exec *exec, int cpt_pipe);
// signals.c
void	redisplay_prompt(void);
void	signal_catching_mode(int mode);
// path.c
char	*path_join(char *path, char *bin);
char	*getpath(char *cmd, char **env);
#endif
