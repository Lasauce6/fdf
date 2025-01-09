/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:51:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/09 12:14:28 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free_map(data->map);
		free(data);
		exit_error(MLX_ERROR);
	}
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->win = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "FDF");
	if (data->win == NULL || data->img->mlx_img == NULL)
	{
		close_window(data);
		exit_error(MLX_ERROR);
	}
	data->img->addr = mlx_get_data_addr(data->img->mlx_img,
			&data->img->bpp, &data->img->line_len, &data->img->endian);
}

void	start_mlx(t_map *map)
{
	t_data	*data;

	data = init_data(map);
	if (data == NULL)
	{
		free_map(map);
		exit_error(MEM_ALLOC_ERROR);
	}
	init_mlx(data);
	mlx_hook(data->win, 2, (1L << 0), &handle_keypress, data);
	mlx_hook(data->win, 17, 0, &close_window, data);
	draw_map(data);
	mlx_loop(data->mlx_ptr);
}
