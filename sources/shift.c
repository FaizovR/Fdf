/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 14:16:36 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	shift_up_x(t_fdf *data)
{
	if (data->shift_x < INT_MAX - SHIFT)
		data->shift_x += SHIFT;
}

static void	shift_down_x(t_fdf *data)
{
	if (data->shift_x > INT_MIN + SHIFT)
		data->shift_x -= SHIFT;
}

static void	shift_up_y(t_fdf *data)
{
	if (data->shift_y < INT_MAX - SHIFT)
		data->shift_y += SHIFT;
}

static void	shift_down_y(t_fdf *data)
{
	if (data->shift_y > INT_MIN + SHIFT)
		data->shift_y -= SHIFT;
}

void		shift(int key, t_fdf *data)
{
	if (key == 126)
		shift_down_y(data);
	if (key == 125)
		shift_up_y(data);
	if (key == 123)
		shift_down_x(data);
	if (key == 124)
		shift_up_x(data);
}
