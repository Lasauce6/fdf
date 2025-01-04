/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:43:21 by rbaticle          #+#    #+#             */
/*   Updated: 2025/01/04 12:12:24 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Window size
#define W_WIDTH 1200
#define W_HEIGHT 800

// Hex base
#define HEX_BASE "0123456789ABCDEF"

// Colors
#define WHITE 0xFFFFFF
#define BLUE 0x1B03A3
#define YELLOW 0xFFFF33
#define NAVY 0x071952
#define B_TEAL 0x0B666A
#define TEAL 0x35A29F
#define MINT 0x97FEED

// Bit shifting & bit mask
#define AS 24
#define RS 16
#define GS 8
#define BM 0xFF

// Exit messages
#define COLOR_ERR_MSG "\033[33m"
#define RESET_ERR_MSG "\033[0m"
#define SUCCESS 0
#define FAILURE 1
#define INVALID_ARGS_ERROR 2
#define FILE_OPEN_ERROR 3
#define MEM_ALLOC_ERROR 4
#define MAP_EMPTY_ERROR 5
#define LIBFT_ERROR 6
#define MLX_ERROR 7
#define INVALID_FILENAME_ERROR 8

// Keys
#define ESC_KEY 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define C_KEY 99
#define R_KEY 114
#define Q_KEY 113
#define E_KEY 101
#define X_KEY 120
#define Z_KEY 122
#define R_KEY 114
#define TAB 65289
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54

// Transformations
#define TRANS 2.0
#define ROT 0.01
#define ZOOM 0.1
#define TRANS_ALT 0.01
