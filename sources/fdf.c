/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 12:43:46 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_fdf *data)
{
	data->z_matrix = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->is_fullscreen = 0;
	data->zoom = ZOOM;
	data->shift_z = SHIFT_Z;
	data->shift_x = SHIFT;
	data->shift_y = SHIFT;
	data->win_x = WINDOW_SIZE_S_X;
	data->win_y = WINDOW_SIZE_S_Y;
}

int		main(int argc, char **argv)
{
	t_fdf	data;

	if (argc == 1)
	{
		ft_putstr("Usage: ./fdf [map]");
		return (0);
	}
	init_data(&data);
	read_file(argv[1], &data);
	new_window(&data);
	return (0);
}
