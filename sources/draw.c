/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 13:54:02 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	init_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

void			draw(t_fdf *data)
{
	t_point p1;
	t_point p2;

	p1.y = 0;
	while (p1.y < data->height)
	{
		p1.x = 0;
		while (p1.x < data->width)
		{
			if (p1.x < data->width - 1)
			{
				p2 = init_point(p1.x + 1, p1.y);
				draw_line(p1, p2, data);
			}
			if (p1.y < data->height - 1)
			{
				p2 = init_point(p1.x, p1.y + 1);
				draw_line(p1, p2, data);
			}
			p1.x++;
		}
		p1.y++;
	}
}
