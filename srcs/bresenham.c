/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:50:29 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/02 18:02:50 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static void	init_bresenham(t_point *start, t_point *end, t_point *delta,
						t_point *sign)
{
	delta->x = ft_abs(end->x - start->x);
	delta->y = -ft_abs(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

void	bresenham(t_data *data, t_point start, t_point end)
{
	t_point	c;
	t_point	sign;
	t_point	delta;
	int		line;
	int		tmp;

	init_bresenham(&start, &end, &delta, &sign);
	line = delta.x + delta.y;
	c = start;
	while (c.x != end.x || c.y != end.y)
	{
		put_pixel(data, c.x, c.y, calc_color(c, start, end, delta));
		tmp = line * 2;
		if (tmp > delta.y)
		{
			line += delta.y;
			c.x += sign.x;
		}
		if (tmp < delta.x)
		{
			line += delta.x;
			c.y += sign.y;
		}
	}
}
