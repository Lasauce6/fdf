/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:48:11 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/04 12:20:03 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_menu(t_data *data)
{
	void	*mlx_ptr;
	void	*win;
	int		vp;

	mlx_ptr = data->mlx_ptr;
	win = data->win;
	vp = 20;
	mlx_string_put(mlx_ptr, win, 25, vp += 30, WHITE, "CONTROLS :");
	mlx_string_put(mlx_ptr, win, 40, vp += 20, WHITE, "'R' : RESET DEFAULTS");
	mlx_string_put(mlx_ptr, win, 40, vp += 20, WHITE, "'W'/'A'/'S'/'D' : MOVE");
	mlx_string_put(mlx_ptr, win, 40, vp += 20, WHITE, "'Z'/'X' : ZOOM IN/OUT");
	mlx_string_put(mlx_ptr, win, 40, vp += 20,
		WHITE, "'Q'/'E' : CHANGE ALTITUDE");
	mlx_string_put(mlx_ptr, win, 40, vp += 20, WHITE, "'1'/'2' : ROTATE X");
	mlx_string_put(mlx_ptr, win, 40, vp += 20, WHITE, "'3'/'4' : ROTATE Y");
	mlx_string_put(mlx_ptr, win, 40, vp += 20, WHITE, "'5'/'6' : ROTATE Z");
	mlx_string_put(mlx_ptr, win, 40, vp += 20,
		WHITE, "'TAB' : TOOGLE PERSPECTIVE");
	mlx_string_put(mlx_ptr, win, 40, vp += 20, WHITE, "'C' : CHANGE COLOR");
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	ft_bzero(data->img->addr, W_WIDTH * W_HEIGHT * (data->img->bpp / 8));
	if (data->zoom)
	{
		y = -1;
		while (++y < data->map->height)
		{
			x = -1;
			while (++x < data->map->width)
			{
				if (x < data->map->width - 1)
					bresenham(data,
						transform_point(data, create_point(x, y, data)),
						transform_point(data, create_point(x + 1, y, data)));
				if (y < data->map->height - 1)
					bresenham(data,
						transform_point(data, create_point(x, y, data)),
						transform_point(data, create_point(x, y + 1, data)));
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img->mlx_img, 0, 0);
	draw_menu(data);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	pixel;

	if (x >= W_WIDTH || y >= W_HEIGHT || x < 0 || y < 0)
		return ;
	pixel = (y * data->img->line_len) + (x * (data->img->bpp / 8));
	if (data->img->endian == 1)
	{
		data->img->addr[pixel + 0] = (color >> AS);
		data->img->addr[pixel + 1] = (color >> RS) & BM;
		data->img->addr[pixel + 2] = (color >> GS) & BM;
		data->img->addr[pixel + 3] = (color) & BM;
	}
	else if (data->img->endian == 0)
	{
		data->img->addr[pixel + 0] = (color) & BM;
		data->img->addr[pixel + 1] = (color >> GS) & BM;
		data->img->addr[pixel + 2] = (color >> RS) & BM;
		data->img->addr[pixel + 3] = (color >> AS);
	}
}
