/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:42:28 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/03 12:48:13 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_x(t_data *data, int *y, int *z)
{
	float	mem_y;

	mem_y = *y;
	*y = (mem_y * cos(data->rot_x)) + (*z * sin(data->rot_x));
	*z = (-mem_y * sin(data->rot_x)) + (*z * cos(data->rot_x));
}

void	rot_y(t_data *data, int *x, int *z)
{
	float	mem_x;

	mem_x = *x;
	*x = (mem_x * cos(data->rot_y)) + (*z * sin(data->rot_y));
	*z = (-mem_x * sin(data->rot_y)) + (*z * cos(data->rot_y));
}

void	rot_z(t_data *data, int *x, int *y)
{
	float	mem_x;

	mem_x = *x;
	*x = (mem_x * cos(data->rot_z)) - (*y * sin(data->rot_z));
	*y = (mem_x * sin(data->rot_z)) + (*y * cos(data->rot_z));
}
