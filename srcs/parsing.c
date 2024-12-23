/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:28:14 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/23 15:41:23 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	parse(char *file)
{
	char	**map;
	char	*line;
	int		fd;

	map = ft_split(file, '.');
	if (ft_strncmp(map[-1], ".fdf", 4))
		return (free_split(map), 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{

	}
}
