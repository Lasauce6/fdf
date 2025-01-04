/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:21:59 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/04 11:59:15 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	adjust_zoom(int keycode, t_data *data)
{
	if (keycode == X_KEY)
	{
		if (data->zoom > 0)
			data->zoom -= ZOOM;
	}
	if (keycode == Z_KEY)
	{
		if (data->zoom < INT_MAX)
			data->zoom += ZOOM;
	}
}

static void	adjust_rot(int keycode, t_data *data)
{
	if (keycode == KEY_1)
		data->rot_x += ROT;
	if (keycode == KEY_2)
		data->rot_x -= ROT;
	if (keycode == KEY_3)
		data->rot_y += ROT;
	if (keycode == KEY_4)
		data->rot_y -= ROT;
	if (keycode == KEY_5)
		data->rot_z += ROT;
	if (keycode == KEY_6)
		data->rot_z -= ROT;
}

static void	adjust_trans(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->shift_y -= TRANS;
	if (keycode == A_KEY)
		data->shift_x -= TRANS;
	if (keycode == S_KEY)
		data->shift_y += TRANS;
	if (keycode == D_KEY)
		data->shift_x += TRANS;
}

static void	adjust_alt(int keycode, t_data *data)
{
	if (keycode == E_KEY)
	{
		if (data->alt < 10)
			data->alt += TRANS_ALT;
	}
	if (keycode == Q_KEY)
	{
		if (data->alt > 0)
			data->alt -= TRANS_ALT;
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	if (keycode == R_KEY)
		reset_default(data);
	if (keycode == TAB)
		data->isometric ^= 1;
	if (keycode == Z_KEY || keycode == X_KEY)
		adjust_zoom(keycode, data);
	if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY)
		adjust_trans(keycode, data);
	if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3
		|| keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6)
		adjust_rot(keycode, data);
	if (keycode == Q_KEY || keycode == E_KEY)
		adjust_alt(keycode, data);
	if (keycode == C_KEY)
		change_color(data);
	draw_map(data);
	return (0);
}
