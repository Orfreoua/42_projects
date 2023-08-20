/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:43 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 21:50:14 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

//ne pas oublier de remetre lindex a zero.
void	execute_menu(t_data *data)
{
	if (data->menu.index == 0) // continue
		data->menu.ison = 0;
	else if (data->menu.index == 1) // setting a faire 
	{data->menu.ison = 0;}
	else if (data->menu.index == 2) // new_game a faire
	{data->menu.ison = 0;}
	else if (data->menu.index == 3) // echape
	{
		ft_free_data(data);
		exit(0);
	}
}

void	menu_dir(t_data *data, int key)
{
	if (key == ARROW_UP)
		data->menu.index--;
	else if (key == ARROW_DOWN)
		data->menu.index++;
	if (data->menu.index == -1)
		data->menu.index = 3;
	else if (data->menu.index == 4)
		data->menu.index = 0; 
}

void	display_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 250, 150, 54545, "continue");
	mlx_string_put(data->mlx, data->win, 250, 250, 54545, "setting");
	mlx_string_put(data->mlx, data->win, 250, 350, 54545, "new game");
	mlx_string_put(data->mlx, data->win, 250, 450, 54545, "leave");
	if (data->menu.index == 0)
		mlx_string_put(data->mlx, data->win, 240, 150, 54545, "X");
	else if (data->menu.index == 1)
		mlx_string_put(data->mlx, data->win, 240, 250, 54545, "X");
	else if (data->menu.index == 2)
		mlx_string_put(data->mlx, data->win, 240, 350, 54545, "X");
	else if (data->menu.index == 3)
			mlx_string_put(data->mlx, data->win, 240, 450, 54545, "X");
	
}

void	menu(t_data *data, int keycode)
{
	if (BONUS && keycode == ENTER && !data->menu.ison)
		data->menu.ison = 1;
	else if (keycode == ENTER && data->menu.ison)
		execute_menu(data);
	else if (data->menu.ison)
		menu_dir(data, keycode);
}