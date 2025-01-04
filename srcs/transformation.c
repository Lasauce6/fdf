/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:04:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/04 11:59:06 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	isometric(t_data *data, int *x, int *y, int z)
{
	int	mem_x;
	int	mem_y;

	if (!data->isometric)
		return ;
	mem_x = *x;
	mem_y = *y;
	*x = (mem_x - mem_y) * cos(0.52359877559);
	*y = -z + (mem_x + mem_y) * sin(0.52359877559);
}

t_point	transform_point(t_data *data, t_point point)
{
	point.x *= data->zoom;
	point.y *= data->zoom;
	point.z *= (data->zoom / 10) * data->alt;
	rot_x(data, &point.y, &point.z);
	rot_y(data, &point.x, &point.z);
	rot_z(data, &point.x, &point.y);
	isometric(data, &point.x, &point.y, point.z);
	point.x += data->shift_x;
	point.y += data->shift_y;
	return (point);
}

t_point	create_point(int x, int y, t_data *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = data->map->z_map[y][x];
	if (data->map->iscolor)
		point.color = data->map->colors[y][x];
	else
		point.color = calc_z_color(data, point.z);
	return (point);
}
