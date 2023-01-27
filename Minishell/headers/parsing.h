/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:18:10 by akefeder          #+#    #+#             */
/*   Updated: 2022/12/22 20:33:47 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>

# define ERROR		-1
# define OK			0
# define N_FOLLOW	0
# define N_FOUND	0
# define FOUND		1
# define FOLLOW		1
# define CONTINUE	1
# define ERR_CHECK	1
# define SPEC		2
# define ERR_SPLIT	2
# define END		3

// Variable globale
extern int				g_exit_ret;

typedef struct s_data	t_data;
typedef struct s_env	t_env;

typedef enum s_token
{
	DEFAULT,
	CMD,
	OPT,
	ARG,
	ARG_FILE,
	PIPE,
	S_R_REDIR,
	D_R_REDIR,
	S_L_REDIR,
	D_L_REDIR,
	S_QUOTE,
	D_QUOTE,
	EX_CODE
}	t_token;

struct s_data
{
	char	*str;
	t_token	token;
	t_data	*suiv;
	int		follow;
};

struct	s_env
{
	char	*str;
	char	*shrt;
	char	*path;
	t_env	*suiv;
};

char	*ft_strcopy(char *str);
char	*ft_strcopy_int(char *str, int *i);
char	*ft_strcopy_char(char *str, char c);
char	*ft_strcopy_char_i(char *str, char c, int *i);
char	*ft_strcopy_char_e(char *str, char c, int *i);
//int		ft_split_env(t_env *env, char c);
int		ft_strlen(char *str);
int		ft_strlen_int(char *str, int i);
int		ft_strlen_char(char *str, char c);
int		ft_strlen_char_i(char *str, char c, int i);
int		ft_strllen(char **str);
t_data	*add_l_arg(void);
void	del_l_arg(t_data *data);
void	clean_list(t_data *slot);
char	*ft_strcopy_esp_split(t_data *slot, char *str, int *i, char *c);
t_data	*ft_quot_esp_split(char *src);
t_data	*parsing(char *s, char **env);
void	free_str(char **str);
void	free_parse(t_data *data);
void	gest_error(int code_err, t_data *data);
int		check_error_parse(char *s);
int		ft_compare(char src, char *cmp);
int		ft_compare_str(char *src, char *cmp);
int		ft_compare_char(char *src, char cmp);
int		ft_count_compare(char *src, char cmp);
int		check_space(char *s);
void	ft_select_split(t_data *data);
t_data	*ft_pipe_redir(t_data *data);
t_data	*add_pipe_token(void);
t_data	*add_s_l_redir_token(void);
t_data	*add_s_r_redir_token(void);
t_data	*add_d_l_redir_token(void);
t_data	*add_d_r_redir_token(void);
t_data	*ft_search_expand(t_data *data, char **env);
int		ft_strstrcmp(char **env, char *str);
char	*ft_strrjoin(char **str);
void	ft_expand(t_data *data, char **env);
t_data	*ft_after_expand(t_data	*data);
void	ft_split_space(t_data *data);
int		ft_min(char c);
int		ft_maj(char c);
int		ft_num(char c);
char	*ft_strcopy_spec(char *str, int j);
char	**add_one_str(char **exp, char *str);
int		found_split(char *s, int dollar, int j, int i);
void	change_dollar(char *str, int *dollar, int i);
char	**select_found(int cpt[3], int *dollar, char **exp, char *str);
int		ft_strstrlen(char **str);
char	*ft_strcopy_i_j(char *str, int i, int j);
char	**ft_split_exp(char *str);
void	ft_join_arg(t_data *data);
t_data	*ft_last_error(t_data *data);
int		ft_cmp_token(t_data *data);
char	*modif_exp(char **exp, int j, char **env);
void	ft_token(t_data *data);
char	*interro_case(char **exp, int i);
char	*ft_itoa(int n);
int		print_error(char *s);
#endif

//"sdasa$asdad$aDa$zsda$$$$AASdAs$?adads"