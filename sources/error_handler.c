/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 11:34:45 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_success(t_fdf *data)
{
	if (data->z_matrix != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->z_matrix);
		data->z_matrix = NULL;
	}
	exit(0);
}

void	ft_error(t_fdf *data, char *str)
{
	ft_putstr(str);
	if (data->z_matrix != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->z_matrix);
		data->z_matrix = NULL;
	}
	exit(0);
}
