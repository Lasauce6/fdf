/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:48:33 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/09 11:22:25 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_map;
	int	**colors;
	int	min_z;
	int	max_z;
	int	iscolor;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win;
	t_map	*map;
	t_img	*img;
	int		shift_x;
	int		shift_y;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	float	zoom;
	int		isometric;
	float	alt;
	int		color_change;
}	t_data;

#endif
