/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:31:17 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:31:19 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int		*tab;
	int		nb;
}	t_stack;

typedef struct s_chunk
{
	int		left;
	int		right;
	int		chunki;
}	t_chunk;

typedef struct utils
{
	int	pos_biggest;
	int	pos_smallest;
	int	nb_moves_biggest;
	int	nb_moves_smallest;
	int	hold_smallest;
}	t_utils;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_stack	orange;
	t_chunk	chunk;
	t_utils	x;
	int		cpt_actions;
}	t_data;
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putndl_fd(char const *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_tablen(char **tab);
void	free_broken_chain(char **chain, int pos);
void	free_tab_two_d(char **tab);
void	free_tab_integer(int *tab);
void	free_all_error(t_data *data);
void	free_all(t_data *data);
int		error(int return_value, char *msg, int fd);
int		load_data(t_data *data, int ac, char **av);
int		duplicate_check(char **values);
int		*tab_string_to_tab_int(char **tab_str, size_t nb_values);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	swap(t_data *data, char c);
void	rotate_a(t_data *data, char c);
void	rotate_b(t_data *data, char c);
void	reverse_rotate_a(t_data *data, char c);
void	reverse_rotate_b(t_data *data, char c);
int		*ft_tab_int_join(int *tab, int value, int size);
int		*ft_tab_int_cpy(int *tab, int size);
void	print_stack(int *stack, int size);
int		stack_is_sorted(t_stack *stack);
void	copy_stack(int *stack, t_stack *a);
int		find_mid_value(t_stack *a);
int		nb_unit(t_stack *stack);
void	sort_three(int *s, t_data *data);
void	sort_five(t_data *data);
void	big_sort(t_data *data);
int		find_bigger_nb(t_stack *data);
void	convert_with_positif_vallue(t_data *data);
void	positif_vallue(t_data *data);
void	selectif_sort(t_stack *stack);
void	repush_on_a(t_data *data);
int		find_pos_smallest(t_stack *stack);
int		average(t_stack *stack);
void	multiple_rotate(t_data *data, int repetition, char index);
void	multiple_reverse_rotate(t_data *data, int repetition, char index);
#endif
