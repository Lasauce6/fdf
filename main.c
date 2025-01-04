/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:29:26 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/02 17:09:34 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	main(int argc, char **argv)
{
	char	*file;
	t_map	*map;

	if (argc != 2)
		exit_error(INVALID_ARGS_ERROR);
	file = argv[1];
	check_filename(file);
	map = init_map(file);
	start_mlx(map);
	free_map(map);
	return (SUCCESS);
}
