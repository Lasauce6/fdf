/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:11:45 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/05 15:03:24 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_split_line(char **split, char *line)
{
	if (split)
		free_split(split);
	if (line)
		free(line);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_map)
	{
		i = -1;
		while (++i < map->height && map->z_map[i])
			free(map->z_map[i]);
		free(map->z_map);
	}
	if (map->colors)
	{
		i = -1;
		while (++i < map->height && map->colors[i])
			free(map->colors[i]);
		free(map->colors);
	}
	free(map);
}

void	alloc_map(t_map *map)
{
	int	i;

	map->z_map = ft_calloc(map->height, sizeof(int *));
	map->colors = ft_calloc(map->height, sizeof(int *));
	if (!map->z_map || !map->colors)
	{
		free_map(map);
		exit_error(MEM_ALLOC_ERROR);
	}
	i = -1;
	while (++i < map->height)
	{
		map->z_map[i] = ft_calloc(map->width, sizeof(int));
		map->colors[i] = ft_calloc(map->width, sizeof(int));
		if (!map->z_map[i] || !map->colors[i])
		{
			free_map(map);
			exit_error(MEM_ALLOC_ERROR);
		}
	}
}

int	close_window(t_data *data)
{
	if (data == NULL)
		return (MEM_ALLOC_ERROR);
	if (data->img->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	if (data->win)
		mlx_destroy_window(data->mlx_ptr, data->win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->img)
		free(data->img);
	if (data->map)
		free_map(data->map);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	free(data);
	exit_error(SUCCESS);
	return (SUCCESS);
}
