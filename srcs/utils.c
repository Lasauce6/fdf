/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:00:53 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/02 16:41:59 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_filename(const char *filename)
{
	size_t		len;
	size_t		ext_len;
	const char	*extension;

	extension = ".fdf";
	len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	if (len < ext_len
		|| ft_strncmp(filename + len - ext_len, extension, 4) != 0)
		exit_error(INVALID_FILENAME_ERROR);
}

int	calc_z_value(int z, t_map *map)
{
	if (z < map->min_z)
		map->min_z = z;
	if (z > map->max_z)
		map->max_z = z;
	return (z);
}

int	convert_hex_color(char *color, t_map *map)
{
	while (ft_isdigit(*color) || *color == '-'
		|| *color == '+' || *color == ',')
		color++;
	if (*color && *color == 'x')
	{
		map->iscolor = 1;
		color++;
		return (ft_atoi_base(color, HEX_BASE));
	}
	return (WHITE);
}
