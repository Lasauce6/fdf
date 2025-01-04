/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:01:56 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/02 16:23:04 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_error(int exit_status)
{
	ft_printf("%s", COLOR_ERR_MSG);
	if (exit_status == INVALID_ARGS_ERROR)
		ft_printf("INVALID_ARGS_ERROR: { Usage: ./fdf <filename>.fdf }\n");
	else if (exit_status == FILE_OPEN_ERROR)
		ft_printf("FILE_OPEN_ERROR: Error while opening the file\n");
	else if (exit_status == MEM_ALLOC_ERROR)
		ft_printf("MEM_ALLOC_ERROR: Failed allocating memory\n");
	else if (exit_status == MAP_EMPTY_ERROR)
		ft_printf("MAP_EMPTY_ERROR: The map is empty\n");
	else if (exit_status == LIBFT_ERROR)
		ft_printf("LIBFT_ERROR: Your libft function failed\n");
	else if (exit_status == MLX_ERROR)
		ft_printf("MLX_ERROR: Your minilibx function failed\n");
	else if (exit_status == SUCCESS)
		ft_printf("\e[92mSUCCESS: The program ran successfully\n");
	else if (exit_status == INVALID_FILENAME_ERROR)
		ft_printf("INVALID_FILENAME_ERROR: The filename must end with .fdf\n");
	else
		ft_printf("That's not a valid map!\n");
	ft_printf("%s", RESET_ERR_MSG);
	exit(exit_status);
}
