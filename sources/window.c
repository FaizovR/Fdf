/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 12:49:12 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_window(t_fdf *data)
{
	if (data->mlx_ptr != NULL && data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->mlx_ptr = mlx_init();
	if (data->is_fullscreen)
		data->win_ptr =
	mlx_new_window(data->mlx_ptr, WINDOW_SIZE_F_X, WINDOW_SIZE_F_Y, "FDF");
	else
		data->win_ptr =
	mlx_new_window(data->mlx_ptr, WINDOW_SIZE_S_X, WINDOW_SIZE_S_Y, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}

void	change_window(t_fdf *data)
{
	if (data->is_fullscreen)
		data->is_fullscreen = 0;
	else
		data->is_fullscreen = 1;
	new_window(data);
}
