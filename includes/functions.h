/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:51:16 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/05 15:03:36 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

// Error
void	exit_error(int exit_status);

// Parsing
t_map	*init_map(char *file);

// Free
void	free_split(char **split);
void	free_split_line(char **split, char *line);
void	free_map(t_map *map);
void	alloc_map(t_map *map);
int		close_window(t_data *data);

// Utils
void	check_filename(const char *filename);
int		calc_z_value(int z, t_map *map);
int		convert_hex_color(char *color, t_map *map);

// Init mlx
void	start_mlx(t_map *map);

// Init data
void	reset_default(t_data *data);
t_data	*init_data(t_map *map);

// Handle keypress
int		handle_keypress(int keycode, t_data *data);

// Draw
void	draw_map(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);

// Bresenham
void	bresenham(t_data *data, t_point start, t_point end);

//-----------------------------------BONUS-----------------------------------//
// Colors
int		calc_color(t_point current, t_point start, t_point end, t_point delta);
int		calc_z_color(t_data *data, int height);
void	change_color(t_data *data);

// Transformation
t_point	transform_point(t_data *data, t_point point);
t_point	create_point(int x, int y, t_data *data);

// Rotations
void	rot_x(t_data *data, int *y, int *z);
void	rot_y(t_data *data, int *x, int *z);
void	rot_z(t_data *data, int *x, int *y);
