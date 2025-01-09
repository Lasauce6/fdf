/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:12:10 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/09 12:05:09 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	find_width(char **split, t_map *map, char *line, int fd)
{
	int	i;

	if (!*split)
	{
		free_map(map);
		free_split_line(split, line, fd);
		exit_error(MAP_EMPTY_ERROR);
	}
	i = 0;
	while (split[i])
		i++;
	free_split(split);
	return (i);
}

static void	get_map_size(int fd, t_map *map)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	split = ft_split(line, ' ');
	if (!split || !line)
	{
		free_split_line(split, line, fd);
		free_map(map);
		exit_error(MAP_EMPTY_ERROR);
	}
	map->width = find_width(split, map, line, fd);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}

static void	parse_map(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	alloc_map(map);
	while (++i < map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split || !line)
			(free_split_line(split, line, fd), free_map(map),
				exit_error(MAP_EMPTY_ERROR));
		if (!split[0] || !split[1])
			(free_split_line(split, line, fd), free_map(map),
				exit_error(MAP_EMPTY_ERROR));
		j = -1;
		while (split[++j])
		{
			map->z_map[i][j] = calc_z_value(ft_atoi(split[j]), map);
			map->colors[i][j] = convert_hex_color(split[j], map);
		}
		(free_split(split), free(line));
	}
}

t_map	*init_map(char *file)
{
	int		fd;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(FILE_OPEN_ERROR);
	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		exit_error(MEM_ALLOC_ERROR);
	get_map_size(fd, map);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		exit_error(FILE_OPEN_ERROR);
	}
	parse_map(fd, map);
	close(fd);
	return (map);
}
