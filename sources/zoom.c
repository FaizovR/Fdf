/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 12:47:10 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_up(t_fdf *data)
{
	if (data->zoom < INT_MAX - ZOOM)
		data->zoom += ZOOM;
}

static void	zoom_down(t_fdf *data)
{
	if (data->zoom > 5)
		data->zoom -= ZOOM;
	else
		data->zoom = 5;
}

void		zoom(int key, t_fdf *data)
{
	if (key == 69)
		zoom_up(data);
	if (key == 78)
		zoom_down(data);
}
