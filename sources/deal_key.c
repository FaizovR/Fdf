/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 12:45:40 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_key(int key)
{
	if (key == 126 || key == 125 || key == 123 || key == 124 \
	|| key == 69 || key == 78 || key == 53 || key == 121 \
	|| key == 116 || key == 3 || key == 34)
	{
		return (1);
	}
	return (0);
}

void	do_key(int key, t_fdf *data)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		shift(key, data);
	if (key == 116 || key == 121)
		shift_z(key, data);
	if (key == 69 || key == 78)
		zoom(key, data);
	if (key == 3)
		change_window(data);
	if (key == 34)
		data->is_isometric = data->is_isometric ? 0 : 1;
	if (key == 53)
		exit_success(data);
}

int		deal_key(int key, t_fdf *data)
{
	if (is_key(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		do_key(key, data);
		draw(data);
	}
	return (0);
}
