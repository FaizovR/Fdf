/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 14:13:26 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void		change_shift(float *x, float *y, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

int			centre(int v, int win, int k)
{
	win /= 2;
	k /= 2;
	return (v + win - k);
}

void		change_step(t_point *p1, t_point *p2, t_fdf *data)
{
	t_point	z_point;

	z_point.x = data->z_matrix[(int)p1->y][(int)p1->x];
	z_point.y = data->z_matrix[(int)p2->y][(int)p2->x];
	change_zoom(&p1->x, &p1->y, data);
	change_zoom(&p2->x, &p2->y, data);
	z_point.x *= data->shift_z;
	z_point.y *= data->shift_z;
	data->color = (z_point.x) ? COLOR_RED : COLOR_WHITE;
	if (data->is_isometric)
	{
		isometric(&p1->x, &p1->y, z_point.x);
		isometric(&p2->x, &p2->y, z_point.y);
	}
	change_shift(&p1->x, &p1->y, data);
	change_shift(&p2->x, &p2->y, data);
}

void		draw_line(t_point p1, t_point p2, t_fdf *data)
{
	t_point	step_point;
	int		max_v;

	change_step(&p1, &p2, data);
	step_point.x = p2.x - p1.x;
	step_point.y = p2.y - p1.y;
	max_v = max(mod(step_point.x), mod(step_point.y));
	step_point.x /= max_v;
	step_point.y /= max_v;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, centre(p1.x, data->win_x,
			data->width), centre(p1.y, data->win_y, data->height), data->color);
		p1.x += step_point.x;
		p1.y += step_point.y;
	}
}
