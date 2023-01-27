/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:03:52 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/21 18:03:56 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

// builtins.c
int		len_of_new_string(char **tab);
char	*string_bonding(char **tab);
int		is_builtin(char *s);
void	builtins_before_pipe(t_exec *exec, char **cmd, t_data *data);
void	do_builtin(t_exec *exec, char **cmd);
// echo.c
int		pass_next_options(char *new_s, int i);
void	builtin_echo(char *s);
// pwd.c
char	*fill_pwd(void);
void	builtin_pwd(void);
// env.c
void	builtin_env(char **env);
// cd.c
char	*get_home_path(char **usenv);
void	builtin_cd(char *s, t_exec *exec);
// export.c
int		error_export(char *s);
int		already_exists(char **env, char *s, int n);
int		change_value(t_exec *exec, char *s, int line);
int		generate_new_line(t_exec *exec, char *s);
int		builtin_export(t_exec *exec, char *s);
void	pre_export(t_exec *exec);
// unset.c
int		delete_line(t_exec *exec, int line_to_delete);
int		builtin_unset(t_exec *exec, char *name);
void	pre_unset(t_exec *exec);
// exit.c
void	free_heredoc_struct(t_exec *exec);
void	free_pipe_struct(t_exec *exec);
void	builtin_exit(t_exec *exec, t_data *data);
//wait.c
void	wait_children(t_exec *exec, int nb_pipe);
#endif
