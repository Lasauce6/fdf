/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:49:45 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/03 13:13:41 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	calc_percent(int start, int end, int value)
{
	double	range;
	double	position;

	range = end - start;
	position = value - start;
	if (!range)
		return (1.0);
	return (position / range);
}

static int	calc_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int	calc_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	percent;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percent = calc_percent(start.x, end.x, current.x);
	else
		percent = calc_percent(start.y, end.y, current.y);
	r = calc_light((start.color >> RS) & BM, (end.color >> RS) & BM, percent);
	g = calc_light((start.color >> GS) & BM, (end.color >> GS) & BM, percent);
	b = calc_light(start.color & BM, end.color & BM, percent);
	return ((r << RS) | (g << GS) | b);
}

int	calc_z_color(t_data *data, int height)
{
	double	percent;

	percent = calc_percent(data->map->min_z, data->map->max_z, height);
	if (data->color_change)
	{
		if (percent < 0.7)
			return (YELLOW);
		else
			return (BLUE);
	}
	else
	{
		if (percent < 0.1)
			return (MINT);
		else if (percent < 0.5)
			return (TEAL);
		else if (percent < 0.7)
			return (B_TEAL);
		else
			return (NAVY);
	}
}

void	change_color(t_data *data)
{
	data->color_change ^= 1;
}
