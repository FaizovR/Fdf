/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 14:15:38 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		shift_z_up(t_fdf *data)
{
	if (data->shift_z < INT_MAX - SHIFT_Z)
		data->shift_z += SHIFT_Z;
}

static void		shift_z_down(t_fdf *data)
{
	if (data->shift_z > 0)
		data->shift_z -= SHIFT_Z;
	else
		data->shift_z = 0;
}

void			shift_z(int key, t_fdf *data)
{
	if (key == 116)
		shift_z_up(data);
	if (key == 121)
		shift_z_down(data);
}
