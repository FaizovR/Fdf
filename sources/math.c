/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrett <hbarrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:50 by hbarrett          #+#    #+#             */
/*   Updated: 2020/08/13 14:17:24 by hbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max(float a, float b)
{
	return ((a > b) ? a : b);
}

float	mod(float i)
{
	return ((i < 0) ? -i : i);
}
