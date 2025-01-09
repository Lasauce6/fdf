/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:52:48 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/09 12:16:36 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	reset_default(t_data *data)
{
	data->zoom = ft_max((W_WIDTH / data->map->width / 2),
			(W_HEIGHT / data->map->height / 2));
	data->shift_x = W_WIDTH / 2;
	data->shift_y = (W_HEIGHT - data->map->height * data->zoom) / 2;
	data->isometric = 1;
	data->alt = 1;
	data->rot_x = 0;
	data->rot_y = 0;
	data->rot_z = 0;
}

t_data	*init_data(t_map *map)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->img = ft_calloc(1, sizeof(t_img));
	if (data->img == NULL)
		return (free(data), NULL);
	data->map = map;
	data->color_change = 0;
	reset_default(data);
	return (data);
}
